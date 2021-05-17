---
title: LCDRotaryMenu
summary: LCD Rotary Menu.  

---

# LCDRotaryMenu




LCD Rotary Menu.  [More...](#detailed-description)


`#include <lcd-rotary-menu.h>`















## Public Functions

|                | Name           |
| -------------- | -------------- |
|  | **[LCDRotaryMenu](https://github.com/devel0/iot-utils/tree/main/data/api/Classes/class_l_c_d_rotary_menu.md#function-lcdrotarymenu)**(int addr, int cols, int rows, int rotAPin, int rotBPin, int rotSWPin, bool inverted =false, int btnDebounceMs =50, int abDebounceUs =1500) <br>Construct a new [LCDRotaryMenu](https://github.com/devel0/iot-utils/tree/main/data/api/Classes/class_l_c_d_rotary_menu.md) object.  |
|  | **[~LCDRotaryMenu](https://github.com/devel0/iot-utils/tree/main/data/api/Classes/class_l_c_d_rotary_menu.md#function-~lcdrotarymenu)**()  |
| void | **[setSplashCb](https://github.com/devel0/iot-utils/tree/main/data/api/Classes/class_l_c_d_rotary_menu.md#function-setsplashcb)**(void(*)(LiquidCrystal_I2C &lcd) splCb, uint32_t timeoutMs) <br>Set splash callback before Init.  |
| void | **[init](https://github.com/devel0/iot-utils/tree/main/data/api/Classes/class_l_c_d_rotary_menu.md#function-init)**()  |
| void | **[loop](https://github.com/devel0/iot-utils/tree/main/data/api/Classes/class_l_c_d_rotary_menu.md#function-loop)**()  |
| [LCDRotaryMenuItem](https://github.com/devel0/iot-utils/tree/main/data/api/Classes/class_l_c_d_rotary_menu_item.md) & | **[getRoot](https://github.com/devel0/iot-utils/tree/main/data/api/Classes/class_l_c_d_rotary_menu.md#function-getroot)**()  |

## Protected Functions

|                | Name           |
| -------------- | -------------- |
| void | **[displayMenu](https://github.com/devel0/iot-utils/tree/main/data/api/Classes/class_l_c_d_rotary_menu.md#function-displaymenu)**()  |
| void | **[invalidate](https://github.com/devel0/iot-utils/tree/main/data/api/Classes/class_l_c_d_rotary_menu.md#function-invalidate)**()  |
| void | **[move](https://github.com/devel0/iot-utils/tree/main/data/api/Classes/class_l_c_d_rotary_menu.md#function-move)**(int diff)  |





## Friends

|                | Name           |
| -------------- | -------------- |
| class | **[LCDRotaryMenuItem](https://github.com/devel0/iot-utils/tree/main/data/api/Classes/class_l_c_d_rotary_menu.md#friend-lcdrotarymenuitem)**  |





## Detailed Description

```cpp
class LCDRotaryMenu;
```

LCD Rotary Menu. 


























nfo 











## Public Functions Documentation

### function LCDRotaryMenu

```cpp
LCDRotaryMenu(
    int addr,
    int cols,
    int rows,
    int rotAPin,
    int rotBPin,
    int rotSWPin,
    bool inverted =false,
    int btnDebounceMs =50,
    int abDebounceUs =1500
)
```

Construct a new [LCDRotaryMenu](https://github.com/devel0/iot-utils/tree/main/data/api/Classes/class_l_c_d_rotary_menu.md) object. 

**Parameters**: 

  * **addr** i2c lcd address 
  * **cols** nr. of lcd columns 
  * **rows** nr. of lcd rows 
  * **rotAPin** pin of rotary encoder A 
  * **rotBPin** pin of rotary encoder B 
  * **rotSWPin** pin of rotary encoder switch 
  * **inverted** if true cw/ccw generates decrement/increment in position 
  * **btnDebounceMs** debounce(ms) for rotary switch 
  * **btnDebounceMs** debounce(us) for rotary A, B 




























### function ~LCDRotaryMenu

```cpp
~LCDRotaryMenu()
```





























### function setSplashCb

```cpp
void setSplashCb(
    void(*)(LiquidCrystal_I2C &lcd) splCb,
    uint32_t timeoutMs
)
```

Set splash callback before Init. 

**Parameters**: 

  * **splCb** callback here you can directly used lcd ( clear, setCursor, print ) 
  * **timeoutMs** time after which menu display 




























### function init

```cpp
void init()
```





























### function loop

```cpp
void loop()
```





























### function getRoot

```cpp
LCDRotaryMenuItem & getRoot()
```






























## Protected Functions Documentation

### function displayMenu

```cpp
void displayMenu()
```





























### function invalidate

```cpp
void invalidate()
```





























### function move

```cpp
void move(
    int diff
)
```


































## Friends

### friend LCDRotaryMenuItem

```cpp
friend class LCDRotaryMenuItem;
```































-------------------------------

Updated on 17 May 2021 at 21:02:57 CEST