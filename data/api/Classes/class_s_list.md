---
title: SList
summary: Templated simple linked-list.  

---

# SList




Templated simple linked-list.  [More...](#detailed-description)


`#include <slist.h>`















## Public Functions

|                | Name           |
| -------------- | -------------- |
|  | **[SList](https://github.com/devel0/iot-utils/tree/main/data/api/Classes/class_s_list.md#function-slist)**() <br>Default constructor.  |
|  | **[SList](https://github.com/devel0/iot-utils/tree/main/data/api/Classes/class_s_list.md#function-slist)**(const [SList](https://github.com/devel0/iot-utils/tree/main/data/api/Classes/class_s_list.md) & other) <br>Copy constructor.  |
| [SList](https://github.com/devel0/iot-utils/tree/main/data/api/Classes/class_s_list.md) & | **[operator=](https://github.com/devel0/iot-utils/tree/main/data/api/Classes/class_s_list.md#function-operator=)**(const [SList](https://github.com/devel0/iot-utils/tree/main/data/api/Classes/class_s_list.md) & other) <br>Assign operator.  |
|  | **[~SList](https://github.com/devel0/iot-utils/tree/main/data/api/Classes/class_s_list.md#function-~slist)**() <br>Destructor.  |
| uint16_t | **[Size](https://github.com/devel0/iot-utils/tree/main/data/api/Classes/class_s_list.md#function-size)**() const <br>Current list size.  |
| T & | **[Add](https://github.com/devel0/iot-utils/tree/main/data/api/Classes/class_s_list.md#function-add)**(const T & data) <br>Adds given templated object "data to the list.  |
| void | **[Clear](https://github.com/devel0/iot-utils/tree/main/data/api/Classes/class_s_list.md#function-clear)**() <br>Clear the list destroying each nodes thus calling the destructor of contained templated data objects.  |
| void | **[Remove](https://github.com/devel0/iot-utils/tree/main/data/api/Classes/class_s_list.md#function-remove)**(uint16_t idx) <br>Remove the node by idx ( 0 is the first ).  |
| T & | **[Get](https://github.com/devel0/iot-utils/tree/main/data/api/Classes/class_s_list.md#function-get)**(int idx) const <br>Retrieve a reference of the template object at the given "idx in the node list.  |
| [SListNode](https://github.com/devel0/iot-utils/tree/main/data/api/Classes/class_s_list_node.md)< T > * | **[GetNode](https://github.com/devel0/iot-utils/tree/main/data/api/Classes/class_s_list.md#function-getnode)**(int idx) const <br>Retrieve a pointer to the node at the given "idx ( 0 is start ).  |











## Detailed Description

```cpp
template <class T >
class SList;
```

Templated simple linked-list. 




**Template Parameters**: 

  * **T** template of data 























Store templated element "T into a simple linked list. The given template "T must support default constructor for internal purpose.











## Public Functions Documentation

### function SList

```cpp
inline SList()
```

Default constructor. 




























### function SList

```cpp
inline SList(
    const SList & other
)
```

Copy constructor. 

**Parameters**: 

  * **other** list to copy data from 




























### function operator=

```cpp
inline SList & operator=(
    const SList & other
)
```

Assign operator. 

**Parameters**: 

  * **other** other list to copy data from 







**Return**: [SList](https://github.com/devel0/iot-utils/tree/main/data/api/Classes/class_s_list.md)& new list with data copied from given other 



















Creates a copy of the given "other list.


### function ~SList

```cpp
inline ~SList()
```

Destructor. 


























Deallocates memory used for nodes and thus calls destructor of stored templated objects. 


### function Size

```cpp
inline uint16_t Size() const
```

Current list size. 







**Return**: uint16_t 





















### function Add

```cpp
inline T & Add(
    const T & data
)
```

Adds given templated object "data to the list. 

**Parameters**: 

  * **data** item data to add 







**Return**: T& reference to item data 



















If DEBUG enabled a report about out-of-memory will be reported if unable to allocate more nodes.


### function Clear

```cpp
inline void Clear()
```

Clear the list destroying each nodes thus calling the destructor of contained templated data objects. 




























### function Remove

```cpp
inline void Remove(
    uint16_t idx
)
```

Remove the node by idx ( 0 is the first ). 

**Parameters**: 

  * **idx** index of item to remove (0 is the first) 


























It does nothing if invalid index out of bounds.


### function Get

```cpp
inline T & Get(
    int idx
) const
```

Retrieve a reference of the template object at the given "idx in the node list. 

**Parameters**: 

  * **idx** index of element to retrieve (0 is the first) 







**Return**: T& template data of i-th item 



















Note: don't use "auto pointer of the returned object will be copied instead of referenced.


### function GetNode

```cpp
inline SListNode< T > * GetNode(
    int idx
) const
```

Retrieve a pointer to the node at the given "idx ( 0 is start ). 

**Parameters**: 

  * **idx** index of element node to retrieve (0 is the first) 







**Return**: SListNode<T>* pointer to i-th item in the list ( NULL if invalid index ) 



















If an invalid index was given returns NULL.










-------------------------------

Updated on 17 May 2021 at 21:02:57 CEST