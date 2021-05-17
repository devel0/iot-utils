#ifdef ARDUINO

#include "debounced-button.h"

#include "sys-debug.h"

vector<DebouncedButton *> *DebouncedButton::instances = NULL;

void debouncedButtonISR()
{
    auto s = DebouncedButton::instances->size();
    for (int i = 0; i < s; ++i)
    {
        (*DebouncedButton::instances)[i]->isrHandler();
    }
}

DebouncedButton::DebouncedButton(int pin, int debounceMs)
{
    if (instances == NULL)
        instances = new vector<DebouncedButton *>();

    this->pin = pin;
    this->debounceMs = debounceMs;

    pinMode(pin, INPUT_PULLUP);

    instances->push_back(this);

    if (instances->size() == 1)
    {
        attachInterrupt(digitalPinToInterrupt(pin), debouncedButtonISR, CHANGE);
    }
}

DebouncedButton::~DebouncedButton()
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
            detachInterrupt(digitalPinToInterrupt(pin));
        }
    }
    else
    {
        error();
    }
}

void DebouncedButton::isrHandler()
{
    auto isPressed = digitalRead(pin) == LOW;
    unsigned long m = millis();

    switch (state)
    {
    case DebouncedButtonState::UNKNOWN:
    {
        if (isPressed)
        {
            state = DebouncedButtonState::PRESSED;            
        }
        else
            state = DebouncedButtonState::RELEASED;
    }
    break;

    case DebouncedButtonState::PRESSED:
    {
        if (!isPressed)
        {
            state = DebouncedButtonState::RELEASED;
            releasedBegin = m;            
            ++pressCount;
        }        
    }
    break;

    case DebouncedButtonState::RELEASED:
    {
        if (isPressed && m - releasedBegin > debounceMs)
        {
            state = DebouncedButtonState::PRESSED;
        }
    }
    break;
    }
} 

int DebouncedButton::getPressCount() const
{
    return pressCount;
}

#endif