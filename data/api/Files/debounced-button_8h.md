---
title: include/debounced-button.h


---

# include/debounced-button.h
























## Source code

```cpp
#ifndef _DEBOUNCED_BUTTON_H
#define _DEBOUNCED_BUTTON_H

#ifdef ARDUINO

#include <Arduino.h>

#include <vector>

using namespace std;

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
```


-------------------------------

Updated on 17 May 2021 at 20:39:28 CEST
