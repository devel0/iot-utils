#ifndef _DEBOUNCED_BUTTON_H
#define _DEBOUNCED_BUTTON_H

#ifdef ARDUINO

#include <Arduino.h>

#include <vector>

using namespace std;

/**
 * @brief btn pin will be set as INPUT_PULLUP
 */
class DebouncedButton
{
    enum DebouncedButtonState
    {
        UNKNOWN,
        RELEASED,
        PRESSED
    };

    friend void debouncedButtonISR();
    void isrHandler();

    int pin;
    int debounceMs;

    DebouncedButtonState state = DebouncedButtonState::UNKNOWN;
    uint32_t releasedBegin = 0;

    volatile int pressCount = 0;

    static vector<DebouncedButton *> *instances;

public:
    DebouncedButton(int pin, int debounceMs = 50);
    ~DebouncedButton();

    int getPressCount() const;
};

#endif

#endif