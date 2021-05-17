---
title: include/lcd-rotary-menu.h


---

# include/lcd-rotary-menu.h
























## Source code

```cpp
#ifndef _LCD_ROTARY_MENU_H
#define _LCD_ROTARY_MENU_H

#ifdef ARDUINO

#include <Arduino.h>

#include <LiquidCrystal_I2C.h>

#include "debounced-button.h"
#include "debounced-rotary.h"
#include "lcd-rotary-menuitem.h"

class LCDRotaryMenu
{
    friend class LCDRotaryMenuItem;

    int cols;
    int rows;

    LiquidCrystal_I2C *lcd;
    DebouncedButton *btn;
    DebouncedRotary *rotary;

    void (*splCb)(LiquidCrystal_I2C &lcd);
    uint32_t splTimeoutMs;

    uint32_t menuBeginTimestamp;
    bool splashDisplayed;

    int rotAPin;
    int rotBPin;
    int rotSWPin;

    LCDRotaryMenuItem *root;
    LCDRotaryMenuItem *selectedItem;
    bool invalidated;

protected:
    void displayMenu();
    void invalidate();
    void move(int diff);

public:
    LCDRotaryMenu(int addr, int cols, int rows, int rotAPin, int rotBPin, int rotSWPin, bool inverted = false,
                  int btnDebounceMs = 50, int abDebounceUs = 1500);
    ~LCDRotaryMenu();

    void setSplashCb(void (*splCb)(LiquidCrystal_I2C &lcd), uint32_t timeoutMs);

    void init();
    void loop();

    LCDRotaryMenuItem &getRoot();
};

#endif

#endif
```


-------------------------------

Updated on 17 May 2021 at 20:39:28 CEST