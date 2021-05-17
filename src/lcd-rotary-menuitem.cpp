#ifdef ARDUINO

#include "lcd-rotary-menuitem.h"

#include "lcd-rotary-menu.h"

void goBack(LCDRotaryMenuItem &item)
{
    item.back();
}

LCDRotaryMenuItem::LCDRotaryMenuItem(LCDRotaryMenu &menu, LCDRotaryMenuItem *parent) : menu(menu)
{
    this->parent = parent;    
    scrollRowPos = 0;
    selectedChild = NULL;

    /*if (!(options & NO_BACK))
    {
        auto backMenuItem = new LCDRotaryMenuItem(menu, this, LCDRotaryMenuItemOptions::NO_BACK);
        backMenuItem->setText("..");
        backMenuItem->onSelect(goBack);
        children.push_back(backMenuItem);
    }*/
}

LCDRotaryMenuItem::~LCDRotaryMenuItem()
{
    // TODO: deallocate menu items
}

LCDRotaryMenuItem &LCDRotaryMenuItem::append(string menuText)
{
    auto newItem = new LCDRotaryMenuItem(menu, this);
    newItem->setText(menuText);

    if (this != menu.root && children.size() == 0)
    {
        auto backMenuItem = new LCDRotaryMenuItem(menu, this);
        backMenuItem->setText("..");
        backMenuItem->onSelect(goBack);
        children.push_back(backMenuItem);
    }

    children.push_back(newItem);

    return *newItem;
}

LCDRotaryMenuItem *LCDRotaryMenuItem::getParent()
{
    return parent;
}

void LCDRotaryMenuItem::onSelect(LCDRotaryMenuItemCB cb)
{
    this->selectCb = cb;
}

void LCDRotaryMenuItem::onSelect(void (*cb)())
{
    this->selectCb2 = cb;
}

void LCDRotaryMenuItem::setText(string menuText)
{
    text = menuText;
    menu.invalidate();
}

void LCDRotaryMenuItem::select()
{
    if (children.size() > 0)
    {
        if (selectedChild != NULL)
        {
            menu.selectedItem = selectedChild;
        }
        else
        {
            selectedChild = children[0];
            menu.selectedItem = selectedChild;
        }
    }

    if (selectCb != NULL)
    {
        selectCb(*this);
    }
    if (selectCb2 != NULL)
    {
        selectCb2();
    }
    menu.invalidate();
}

void LCDRotaryMenuItem::back()
{
    menu.selectedItem = parent->parent->selectedChild;
    menu.invalidate();
}

const string &LCDRotaryMenuItem::getText() const
{
    return text;
}

#endif