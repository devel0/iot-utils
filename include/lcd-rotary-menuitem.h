#ifndef _LCD_ROTARY_MENUITEM_H
#define _LCD_ROTARY_MENUITEM_H

#ifdef ARDUINO

#include <Arduino.h>

#include <vector>

using namespace std;

class LCDRotaryMenu;
class LCDRotaryMenuItem;

typedef void (*LCDRotaryMenuItemCB)(LCDRotaryMenuItem &);

class LCDRotaryMenuItem
{
    friend class LCDRotaryMenu;

    /**
     * @brief reference to menu manager
     */
    LCDRotaryMenu &menu;

    /**
     * @brief null if this menu is the root     
     */
    LCDRotaryMenuItem *parent;

    LCDRotaryMenuItem(LCDRotaryMenu &menu, LCDRotaryMenuItem *parent, int tag = -1);

    vector<LCDRotaryMenuItem *> children;

    string text;

    /**
     * @brief children scroll row     
     */
    int scrollRowPos;

    LCDRotaryMenuItem *selectedChild;

    /**
     * @brief callback when select this menuitem     
     */
    LCDRotaryMenuItemCB selectCb = NULL;

    /**
     * @brief callback when select this menuitem ( argument less )
     */
    void (*selectCb2)() = NULL;

    bool isBack = false;    

    int tag = -1;

public:
    ~LCDRotaryMenuItem();

    /**
     * @brief append new child ( deallocation automatic )
     * 
     * @param menuText text for the item
     * @param tag optional user tag useful to manage callback with switch type     
     */
    LCDRotaryMenuItem &append(string menuText, int tag = -1);

    LCDRotaryMenuItem *getParent();

    void setText(string menuText);

    /**
     * @brief set callback on select this item
     */
    void onSelect(LCDRotaryMenuItemCB cb);

    void onSelect(void (*cb)());

    /**
     * @brief enter this menuitem (if children) selecting last child of it selected or first if never entered before    
     */
    void select();

    /**
     * @brief exit this menu and go back     
     */
    void back();

    const string &getText() const;

    /**
     * @brief retrieve user tag associated to this menuitem ( useful when manage with single callback that switch on menuitem tag )
     * 
     * @return int 
     */
    int getTag() const;

    bool isDisplayed() const;
};

#endif

#endif