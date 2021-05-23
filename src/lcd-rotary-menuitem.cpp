#ifdef ARDUINO

#include "lcd-rotary-menuitem.h"

#include "lcd-rotary-menu.h"

void goBack(LCDRotaryMenuItem &item)
{
    item.back();
}

LCDRotaryMenuItem::LCDRotaryMenuItem(LCDRotaryMenu &menu, LCDRotaryMenuItem *parent, int tag) : menu(menu)
{
    this->parent = parent;
    this->tag = tag;
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

LCDRotaryMenuItem &LCDRotaryMenuItem::append(string menuText, int tag)
{
    auto newItem = new LCDRotaryMenuItem(menu, this, tag);
    newItem->setText(menuText);

    if (this != menu.root && children.size() == 0)
    {
        auto backMenuItem = new LCDRotaryMenuItem(menu, this);
        backMenuItem->setText(menu.options.backString);
        backMenuItem->isBack = true;
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
        selectCb(*this);
    else if (selectCb2 != NULL)
        selectCb2();
    else if (menu.defaultCb != NULL)
        menu.defaultCb(*this);
        
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

int LCDRotaryMenuItem::getTag() const
{
    return tag;
}

#endif