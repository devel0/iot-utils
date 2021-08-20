---
title: include/obj-utils.h


---

# include/obj-utils.h








## Classes

|                | Name           |
| -------------- | -------------- |
| class | **[nullable](https://github.com/devel0/iot-utils/tree/main/data/api/Classes/classnullable.md)** <br>allow to hold an object value or state that isn't set (nullable)  |
















## Source code

```cpp
#ifndef _OBJ_UTILS_H
#define _OBJ_UTILS_H

template <class T>
class nullable
{
    T vv;
    bool isnull;

public:
    nullable()
    {
        isnull = true;
    }

    nullable(const T &v)
    {
        vv = v;
        isnull = false;
    }

    bool HasValue() const
    {
        return !isnull;
    }

    const T &Value() const
    {
        if (isnull)
        {
            error("null nullable");
        }
        return vv;
    }
};

#endif
```


-------------------------------


