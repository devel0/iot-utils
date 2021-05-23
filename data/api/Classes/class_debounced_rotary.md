---
title: DebouncedRotary
summary: rotA,B will be set as INPUT_PULLUP  

---

# DebouncedRotary




rotA,B will be set as INPUT_PULLUP 

`#include <debounced-rotary.h>`















## Public Functions

|                | Name           |
| -------------- | -------------- |
|  | **[DebouncedRotary](https://github.com/devel0/iot-utils/tree/main/data/api/Classes/class_debounced_rotary.md#function-debouncedrotary)**(int _pinA, int _pinB, int _debounceUs =1500)  |
|  | **[~DebouncedRotary](https://github.com/devel0/iot-utils/tree/main/data/api/Classes/class_debounced_rotary.md#function-~debouncedrotary)**()  |
| void | **[setInverted](https://github.com/devel0/iot-utils/tree/main/data/api/Classes/class_debounced_rotary.md#function-setinverted)**(bool inverted) <br>set behavior of cw/ccw to increment or decrement rotary pos value  |
| int | **[getRotPos](https://github.com/devel0/iot-utils/tree/main/data/api/Classes/class_debounced_rotary.md#function-getrotpos)**() const  |






## Friends

|                | Name           |
| -------------- | -------------- |
| void | **[debouncedRotaryISR](https://github.com/devel0/iot-utils/tree/main/data/api/Classes/class_debounced_rotary.md#friend-debouncedrotaryisr)**()  |















## Public Functions Documentation

### function DebouncedRotary

```cpp
DebouncedRotary(
    int _pinA,
    int _pinB,
    int _debounceUs =1500
)
```





























### function ~DebouncedRotary

```cpp
~DebouncedRotary()
```





























### function setInverted

```cpp
void setInverted(
    bool inverted
)
```

set behavior of cw/ccw to increment or decrement rotary pos value 

**Parameters**: 

  * **inverted** if true cw will decrement pos; if false cw will increment pos 




























### function getRotPos

```cpp
int getRotPos() const
```



































## Friends

### friend debouncedRotaryISR

```cpp
friend void debouncedRotaryISR();
```































-------------------------------

