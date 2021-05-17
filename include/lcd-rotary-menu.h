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
    /**
     * @brief Construct a new LCDRotaryMenu object
     * 
     * @param addr i2c lcd address
     * @param cols nr. of lcd columns
     * @param rows nr. of lcd rows
     * @param rotAPin pin of rotary encoder A
     * @param rotBPin pin of rotary encoder B
     * @param rotSWPin pin of rotary encoder switch
     * @param inverted if true cw/ccw generates decrement/increment in position
     * @param btnDebounceMs debounce(ms) for rotary switch
     * @param btnDebounceMs debounce(us) for rotary A, B
     */
    LCDRotaryMenu(int addr, int cols, int rows, int rotAPin, int rotBPin, int rotSWPin, bool inverted = false,
                  int btnDebounceMs = 50, int abDebounceUs = 1500);
    ~LCDRotaryMenu();

    /**
     * @brief Set splash callback before Init
     * 
     * @param splCb callback here you can directly used lcd ( clear, setCursor, print )
     * @param timeoutMs time after which menu display
     */
    void setSplashCb(void (*splCb)(LiquidCrystal_I2C &lcd), uint32_t timeoutMs);

    void init();
    void loop();

    LCDRotaryMenuItem &getRoot();
};

#endif

#endif