---
title: nullable
summary: allow to hold an object value or state that isn't set (nullable)  

---

# nullable




allow to hold an object value or state that isn't set (nullable)  [More...](#detailed-description)


`#include <obj-utils.h>`















## Public Functions

|                | Name           |
| -------------- | -------------- |
|  | **[nullable](https://github.com/devel0/iot-utils/tree/main/data/api/Classes/classnullable.md#function-nullable)**() <br>construct a nullified obj representation  |
|  | **[nullable](https://github.com/devel0/iot-utils/tree/main/data/api/Classes/classnullable.md#function-nullable)**(const T & v) <br>construct a non nullified obj representation  |
| bool | **[HasValue](https://github.com/devel0/iot-utils/tree/main/data/api/Classes/classnullable.md#function-hasvalue)**() const <br>states if obj is present  |
| const T & | **[Value](https://github.com/devel0/iot-utils/tree/main/data/api/Classes/classnullable.md#function-value)**() const <br>retrieve object value ( [HasValue()](https://github.com/devel0/iot-utils/tree/main/data/api/Classes/classnullable.md#function-hasvalue) must true )  |











## Detailed Description

```cpp
template <class T >
class nullable;
```

allow to hold an object value or state that isn't set (nullable) 




**Template Parameters**: 

  * **T** type of object 


































## Public Functions Documentation

### function nullable

```cpp
inline nullable()
```

construct a nullified obj representation 




























### function nullable

```cpp
inline nullable(
    const T & v
)
```

construct a non nullified obj representation 

**Parameters**: 

  * **v** obj that will copied into this container 




























### function HasValue

```cpp
inline bool HasValue() const
```

states if obj is present 




























### function Value

```cpp
inline const T & Value() const
```

retrieve object value ( [HasValue()](https://github.com/devel0/iot-utils/tree/main/data/api/Classes/classnullable.md#function-hasvalue) must true ) 







**Return**: T& 





























-------------------------------

