#ifdef ARDUINO

#include "debounced-rotary.h"

#include "sys-debug.h"

#ifdef ARDUINO
#include <Arduino.h>
#endif

vector<DebouncedRotary *> *DebouncedRotary::instances = NULL;

void debouncedRotaryISR()
{
    auto s = DebouncedRotary::instances->size();
    for (int i = 0; i < s; ++i)
    {
        (*DebouncedRotary::instances)[i]->isrRHandler();
    }
}

DebouncedRotary::DebouncedRotary(int _pinA, int _pinB, int _debounceUs)
{
    if (instances == NULL)
        instances = new vector<DebouncedRotary *>();

    pinA = _pinA;
    pinB = _pinB;
    debounceUs = _debounceUs;

    pinMode(pinA, INPUT_PULLUP);
    pinMode(pinB, INPUT_PULLUP);
    digitalWrite(pinA, HIGH);
    digitalWrite(pinB, HIGH);

    instances->push_back(this);
    if (instances->size() == 1)
    {
        // use one of A, B not either as trigger
        attachInterrupt(digitalPinToInterrupt(pinA), debouncedRotaryISR, CHANGE);
        //attachInterrupt(digitalPinToInterrupt(pinB), DebouncedRotaryISR, CHANGE);
    }
}

DebouncedRotary::~DebouncedRotary()
{
    int j = -1;
    auto s = instances->size();
    for (int i = 0; i < s; ++i)
    {
        if ((*instances)[i] == this)
        {
            j = i;
            break;
        }
    }
    if (j != -1)
    {
        instances->erase(instances->begin() + j);

        if (instances->size() == 0)
        {
            // use one of A, B not either as trigger
            detachInterrupt(digitalPinToInterrupt(pinA));
            //detachInterrupt(digitalPinToInterrupt(pinB));
        }
    }
    else
    {
        error();
    }
}

void DebouncedRotary::isrRHandler()
{
    int stateA = digitalRead(pinA);
    int stateB = digitalRead(pinB);
    unsigned long u = micros();

    if (stateA == HIGH && pressed) // signal HIGH
    {
        if (releasing)
        {
            if (u - releasedBegin >= debounceUs)
            {
                pressed = releasing = false;
            }
        }
        else
        {
            releasing = true;
            releasedBegin = u;
        }
    }
    else // signal LOW
    {
        if (releasing)
        {
            if (u - releasedBegin >= debounceUs)
            {
                pressed = releasing = false;
            }
        }

        if (pressed)
        {
            releasing = false;
        }
        else
        {
            pressed = true;
            pressedBegin = u;

            if (stateA == HIGH)
            {
                if (stateB == LOW)
                    rotPos += pos_inc;
                else
                    rotPos += pos_dec;
            }
            else
            {
                if (stateB == HIGH)
                    rotPos += pos_inc;
                else
                    rotPos += pos_dec;
            }
        }
    }
}

int DebouncedRotary::getRotPos() const
{
    return rotPos;
}

void DebouncedRotary::setInverted(bool inverted)
{
    if (inverted)
    {
        pos_inc = -1;
        pos_dec = 1;
    }
    else
    {
        pos_inc = 1;
        pos_dec = -1;
    }
}

#endif
