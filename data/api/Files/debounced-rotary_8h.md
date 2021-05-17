---
title: include/debounced-rotary.h


---

# include/debounced-rotary.h
























## Source code

```cpp
#ifndef _DEBOUNCED_ROTARY_H
#define _DEBOUNCED_ROTARY_H

#ifdef ARDUINO

#include <Arduino.h>

#include <vector>

using namespace std;

class DebouncedRotary
{
    friend void debouncedRotaryISR();
    void isrRHandler();

    int pinA, pinB;
    int debounceUs;

    bool pressed = false;
    unsigned long pressedBegin = 0;
    bool releasing = false;
    unsigned long releasedBegin = 0;

    volatile int rotPos = 0;

    int pos_inc = 1;
    int pos_dec = -1;

    static vector<DebouncedRotary *> *instances;

public:
    DebouncedRotary(int _pinA, int _pinB, int _debounceUs = 1500);
    ~DebouncedRotary();

    void setInverted(bool inverted);

    int getRotPos() const;
};

#endif

#endif
```


-------------------------------

Updated on 17 May 2021 at 20:39:28 CEST
