---
title: include/lcd-rotary-menu.h


---

# include/lcd-rotary-menu.h








## Classes

|                | Name           |
| -------------- | -------------- |
| struct | **[LCDRotaryMenuOptions](https://github.com/devel0/iot-utils/tree/main/data/api/Classes/struct_l_c_d_rotary_menu_options.md)**  |
| class | **[LCDRotaryMenu](https://github.com/devel0/iot-utils/tree/main/data/api/Classes/class_l_c_d_rotary_menu.md)** <br>LCD Rotary Menu.  |
















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

struct LCDRotaryMenuOptions
{
    char subMenuPostChar;
};

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
    
    char **rowsBuf;
    char **rowsBuf2;
    short customLineRow;

protected:
    void displayMenu();
    void invalidate();
    void move(int diff);

public:
    LCDRotaryMenu(int addr, int cols, int rows, int rotAPin, int rotBPin, int rotSWPin, bool inverted = false,
                  int btnDebounceMs = 50, int abDebounceUs = 1500);
    ~LCDRotaryMenu();    

    LCDRotaryMenuOptions options;

    void setSplashCb(void (*splCb)(LiquidCrystal_I2C &lcd), uint32_t timeoutMs);

    void init();
    void loop();    

    LCDRotaryMenuItem &getRoot();

    void setCustomLine(const char *customLine, short rowIdx);
    void unsetCustomLine();
};

#endif

#endif
```


-------------------------------

Updated on 20 May 2021 at 12:04:49 CEST
