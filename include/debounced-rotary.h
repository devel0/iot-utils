#ifndef _DEBOUNCED_ROTARY_H
#define _DEBOUNCED_ROTARY_H

#ifdef ARDUINO

#include <Arduino.h>

#include <vector>

using namespace std;

/**
 * @brief rotA,B will be set as INPUT_PULLUP 
 */
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

    /**
     * @brief set behavior of cw/ccw to increment or decrement rotary pos value
     * 
     * @param inverted if true cw will decrement pos; if false cw will increment pos
     */
    void setInverted(bool inverted);

    int getRotPos() const;
};

#endif

#endif