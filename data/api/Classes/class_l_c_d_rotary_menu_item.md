---
title: LCDRotaryMenuItem


---

# LCDRotaryMenuItem






`#include <lcd-rotary-menuitem.h>`















## Public Functions

|                | Name           |
| -------------- | -------------- |
|  | **[~LCDRotaryMenuItem](https://github.com/devel0/iot-utils/tree/main/data/api/Classes/class_l_c_d_rotary_menu_item.md#function-~lcdrotarymenuitem)**()  |
| [LCDRotaryMenuItem](https://github.com/devel0/iot-utils/tree/main/data/api/Classes/class_l_c_d_rotary_menu_item.md) & | **[append](https://github.com/devel0/iot-utils/tree/main/data/api/Classes/class_l_c_d_rotary_menu_item.md#function-append)**(string menuText) <br>append new child ( deallocation automatic )  |
| [LCDRotaryMenuItem](https://github.com/devel0/iot-utils/tree/main/data/api/Classes/class_l_c_d_rotary_menu_item.md) * | **[getParent](https://github.com/devel0/iot-utils/tree/main/data/api/Classes/class_l_c_d_rotary_menu_item.md#function-getparent)**()  |
| void | **[setText](https://github.com/devel0/iot-utils/tree/main/data/api/Classes/class_l_c_d_rotary_menu_item.md#function-settext)**(string menuText)  |
| void | **[onSelect](https://github.com/devel0/iot-utils/tree/main/data/api/Classes/class_l_c_d_rotary_menu_item.md#function-onselect)**([LCDRotaryMenuItemCB](https://github.com/devel0/iot-utils/tree/main/data/api/Files/lcd-rotary-menuitem_8h.md#typedef-lcdrotarymenuitemcb) cb) <br>set callback on select this item  |
| void | **[onSelect](https://github.com/devel0/iot-utils/tree/main/data/api/Classes/class_l_c_d_rotary_menu_item.md#function-onselect)**(void(*)() cb)  |
| void | **[select](https://github.com/devel0/iot-utils/tree/main/data/api/Classes/class_l_c_d_rotary_menu_item.md#function-select)**() <br>enter this menuitem (if children) selecting last child of it selected or first if never entered before  |
| void | **[back](https://github.com/devel0/iot-utils/tree/main/data/api/Classes/class_l_c_d_rotary_menu_item.md#function-back)**() <br>exit this menu and go back  |
| const string & | **[getText](https://github.com/devel0/iot-utils/tree/main/data/api/Classes/class_l_c_d_rotary_menu_item.md#function-gettext)**() const  |






## Friends

|                | Name           |
| -------------- | -------------- |
| class | **[LCDRotaryMenu](https://github.com/devel0/iot-utils/tree/main/data/api/Classes/class_l_c_d_rotary_menu_item.md#friend-lcdrotarymenu)**  |















## Public Functions Documentation

### function ~LCDRotaryMenuItem

```cpp
~LCDRotaryMenuItem()
```





























### function append

```cpp
LCDRotaryMenuItem & append(
    string menuText
)
```

append new child ( deallocation automatic ) 




























### function getParent

```cpp
LCDRotaryMenuItem * getParent()
```





























### function setText

```cpp
void setText(
    string menuText
)
```





























### function onSelect

```cpp
void onSelect(
    LCDRotaryMenuItemCB cb
)
```

set callback on select this item 




























### function onSelect

```cpp
void onSelect(
    void(*)() cb
)
```





























### function select

```cpp
void select()
```

enter this menuitem (if children) selecting last child of it selected or first if never entered before 




























### function back

```cpp
void back()
```

exit this menu and go back 




























### function getText

```cpp
const string & getText() const
```



































## Friends

### friend LCDRotaryMenu

```cpp
friend class LCDRotaryMenu;
```































-------------------------------

Updated on 20 May 2021 at 12:04:49 CEST