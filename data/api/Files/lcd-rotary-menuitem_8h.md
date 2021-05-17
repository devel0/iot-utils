---
title: include/lcd-rotary-menuitem.h


---

# include/lcd-rotary-menuitem.h
























## Source code

```cpp
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

    LCDRotaryMenu &menu;

    LCDRotaryMenuItem *parent;    

    LCDRotaryMenuItem(LCDRotaryMenu &menu, LCDRotaryMenuItem *parent);

    vector<LCDRotaryMenuItem *> children;

    string text;

    int scrollRowPos;

    LCDRotaryMenuItem *selectedChild;

    LCDRotaryMenuItemCB selectCb = NULL;    

    void (*selectCb2)() = NULL;    

public:
    ~LCDRotaryMenuItem();

    LCDRotaryMenuItem &append(string menuText);

    LCDRotaryMenuItem *getParent();

    void setText(string menuText);

    void onSelect(LCDRotaryMenuItemCB cb);

    void onSelect(void (*cb)());

    void select();

    void back();

    const string &getText() const;
};

#endif

#endif
```


-------------------------------

Updated on 17 May 2021 at 20:39:28 CEST
