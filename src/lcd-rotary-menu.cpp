#ifdef ARDUINO

#include "lcd-rotary-menu.h"

#include "lcd-rotary-menuitem.h"
#include "sys-debug.h"

#include <vector>

using namespace std;

LCDRotaryMenu::LCDRotaryMenu(int addr, int cols, int rows, int rotAPin, int rotBPin, int rotSWPin, bool inverted,
                             int btnDebounceMs, int abDebounceUs)
{
    this->cols = cols;
    this->rows = rows;
    lcd = new LiquidCrystal_I2C(addr, cols, rows);
    btn = new DebouncedButton(rotSWPin, btnDebounceMs);
    rotary = new DebouncedRotary(rotAPin, rotBPin, abDebounceUs);
    rotary->setInverted(inverted);

    root = new LCDRotaryMenuItem(*this, NULL);
    selectedItem = NULL;
    invalidated = true;
}

LCDRotaryMenu::~LCDRotaryMenu()
{
    delete rotary;
    delete btn;
    delete lcd;
}

void LCDRotaryMenu::displayMenu()
{
    lcd->clear();

    LCDRotaryMenuItem *parent = (selectedItem == NULL || selectedItem->parent == NULL) ? root : selectedItem->parent;

    vector<LCDRotaryMenuItem *> &menuItems = parent->children;

    auto menuItemsSize = menuItems.size();

    if (menuItemsSize == 0)
        return;

    if (selectedItem == NULL)
        selectedItem = *menuItems.begin();

    int selectedItemIndex = -1;
    for (int i = 0; i < menuItemsSize; ++i)
    {
        if (menuItems[i] == selectedItem)
        {
            selectedItemIndex = i;
            break;
        }
    }
    if (selectedItemIndex == -1)
        error("menuitem idx not found");

    for (int r = 0; r < rows; ++r)
    {
        if (parent->scrollRowPos + r >= menuItemsSize)
            break;

        auto item = menuItems[parent->scrollRowPos + r];
        if (item == selectedItem)
        {
            lcd->setCursor(0, r);
            lcd->print('>');
        }

        lcd->setCursor(1, r);
        lcd->print(item->getText().c_str());
    }

    invalidated = false;
}

void LCDRotaryMenu::move(int diff)
{
    LCDRotaryMenuItem *parent = (selectedItem == NULL || selectedItem->parent == NULL) ? root : selectedItem->parent;

    vector<LCDRotaryMenuItem *> &menuItems = parent->children;

    auto menuItemsSize = menuItems.size();

    if (menuItemsSize == 0)
        return;

    if (selectedItem == NULL)
        selectedItem = *menuItems.begin();

    int selectedItemIndex = -1;
    for (int i = 0; i < menuItemsSize; ++i)
    {
        if (menuItems[i] == selectedItem)
        {
            selectedItemIndex = i;
            break;
        }
    }
    if (selectedItemIndex == -1)
        error("menuitem idx not found");

    auto newSelectedItemIndex = selectedItemIndex + diff;
    if (newSelectedItemIndex < 0)
        newSelectedItemIndex = 0;
    if (newSelectedItemIndex >= menuItemsSize)
        newSelectedItemIndex = menuItemsSize - 1;

    selectedItem = menuItems[newSelectedItemIndex];
    parent->selectedChild = selectedItem;

    if (newSelectedItemIndex < parent->scrollRowPos)
        parent->scrollRowPos = newSelectedItemIndex;
    else if (newSelectedItemIndex >= parent->scrollRowPos + rows)
        parent->scrollRowPos = newSelectedItemIndex;

    //debug("new menu idx:%d ( scrollpos:%d )", newSelectedItemIndex, parent->scrollRowPos);

    invalidated = true;
}

void LCDRotaryMenu::invalidate()
{
    invalidated = true;
}

void LCDRotaryMenu::setSplashCb(void (*splCb)(LiquidCrystal_I2C &lcd), uint32_t timeoutMs)
{
    this->splCb = splCb;
    this->splTimeoutMs = timeoutMs;
}

int lastPressCount = 0;
int lastRotPos = 0;

void LCDRotaryMenu::init()
{
    lcd->init();

    lcd->backlight();
    lcd->clear();

    if (splCb)
    {
        splCb(*lcd);
        splashDisplayed = true;
    }
    else
        displayMenu();

    menuBeginTimestamp = millis();

    //debug("INIT press cnt = %d", lastPressCount);
}

void LCDRotaryMenu::loop()
{
    if (splashDisplayed)
    {
        if (millis() - menuBeginTimestamp >= splTimeoutMs)
        {
            splashDisplayed = false;
            displayMenu();
        }
        return;
    }

    bool redrawMenu = invalidated || false;

    if (btn->getPressCount() != lastPressCount)
    {
        lastPressCount = btn->getPressCount();
        if (selectedItem != NULL)
        {
            selectedItem->select();

            redrawMenu = true;
        }

        //debug("press cnt = %d", lastPressCount);
    }

    if (rotary->getRotPos() != lastRotPos)
    {
        auto rotPos = rotary->getRotPos();
        auto rotDiff = rotPos - lastRotPos;
        lastRotPos = rotPos;

        move(rotDiff);

        redrawMenu = true;

        //debug("rot pos = %d", lastRotPos);
    }

    if (redrawMenu)
        displayMenu();
}

LCDRotaryMenuItem &LCDRotaryMenu::getRoot() { return *root; }

#endif
