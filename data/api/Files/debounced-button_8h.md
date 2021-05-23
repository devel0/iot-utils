---
title: include/debounced-button.h


---

# include/debounced-button.h







## Namespaces

| Name           |
| -------------- |
| **[std](https://github.com/devel0/iot-utils/tree/main/data/api/Namespaces/namespacestd.md)**  |

## Classes

|                | Name           |
| -------------- | -------------- |
| class | **[DebouncedButton](https://github.com/devel0/iot-utils/tree/main/data/api/Classes/class_debounced_button.md)** <br>btn pin will be set as INPUT_PULLUP  |
















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

Updated on 23 May 2021 at 11:28:50 CEST
