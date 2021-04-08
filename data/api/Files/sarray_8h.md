---
title: include/sarray.h


---

# include/sarray.h








## Classes

|                | Name           |
| -------------- | -------------- |
| class | **[SArray](https://github.com/devel0/iot-utils/tree/main/data/api/Classes/class_s_array.md)**  |
















## Source code

```cpp
#ifndef _SARRAY_H
#define _SARRAY_H

template <typename t>
class SArray
{
    uint32_t _size;

    void storeData(t val)
    {
        printf("storing\n");
    }

    template <typename... values>
    void storeData(values... vals)
    {
        printf("recurse\n");
        storeData(vals...);
    }

public:
    t data[];

    template <typename... values>
    SArray(values... vals)
    {
        _size = sizeof...(vals);
        t* ptr = new t[_size];
        storeData(vals...);
    }
    uint32_t size() const { return _size; }
};

#endif
```


-------------------------------

Updated on  8 April 2021 at 19:09:26 CEST
