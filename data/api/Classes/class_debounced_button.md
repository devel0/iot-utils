---
title: DebouncedButton
summary: btn pin will be set as INPUT_PULLUP  

---

# DebouncedButton




btn pin will be set as INPUT_PULLUP 

`#include <debounced-button.h>`















## Public Functions

|                | Name           |
| -------------- | -------------- |
|  | **[DebouncedButton](https://github.com/devel0/iot-utils/tree/main/data/api/Classes/class_debounced_button.md#function-debouncedbutton)**(int pin, int debounceMs =50)  |
|  | **[~DebouncedButton](https://github.com/devel0/iot-utils/tree/main/data/api/Classes/class_debounced_button.md#function-~debouncedbutton)**()  |
| int | **[getPressCount](https://github.com/devel0/iot-utils/tree/main/data/api/Classes/class_debounced_button.md#function-getpresscount)**() const  |






## Friends

|                | Name           |
| -------------- | -------------- |
| void | **[debouncedButtonISR](https://github.com/devel0/iot-utils/tree/main/data/api/Classes/class_debounced_button.md#friend-debouncedbuttonisr)**()  |















## Public Functions Documentation

### function DebouncedButton

```cpp
DebouncedButton(
    int pin,
    int debounceMs =50
)
```





























### function ~DebouncedButton

```cpp
~DebouncedButton()
```





























### function getPressCount

```cpp
int getPressCount() const
```



































## Friends

### friend debouncedButtonISR

```cpp
friend void debouncedButtonISR();
```































-------------------------------

Updated on 17 May 2021 at 21:02:57 CEST