---
title: SListNode
summary: Templated simple linked-list node element.  

---

# SListNode




Templated simple linked-list node element.  [More...](#detailed-description)


`#include <slist.h>`















## Public Functions

|                | Name           |
| -------------- | -------------- |
|  | **[SListNode](https://github.com/devel0/iot-utils/tree/main/data/api/Classes/class_s_list_node.md#function-slistnode)**(const T & _data) <br>Constructor stores a copy of given element into internal data.  |




## Public Attributes

|                | Name           |
| -------------- | -------------- |
| T | **[data](https://github.com/devel0/iot-utils/tree/main/data/api/Classes/class_s_list_node.md#variable-data)** <br>Element data.  |
| [SListNode](https://github.com/devel0/iot-utils/tree/main/data/api/Classes/class_s_list_node.md)< T > * | **[next](https://github.com/devel0/iot-utils/tree/main/data/api/Classes/class_s_list_node.md#variable-next)** <br>Pointer to the next node in simple linked list.  |







## Detailed Description

```cpp
template <class T >
class SListNode;
```

Templated simple linked-list node element. 




**Template Parameters**: 

  * **T** template of data 























Store templated element "T into a node object that allow to follow using a "next pointer to the next one in the list. The given template "T must support default constructor for internal purpose.











## Public Functions Documentation

### function SListNode

```cpp
inline SListNode(
    const T & _data
)
```

Constructor stores a copy of given element into internal data. 

**Parameters**: 

  * **_data** data to store 
































## Public Attributes Documentation

### variable data

```cpp
T data;
```

Element data. 




























### variable next

```cpp
SListNode< T > * next = NULL;
```

Pointer to the next node in simple linked list. 
































-------------------------------

Updated on 17 May 2021 at 21:02:57 CEST