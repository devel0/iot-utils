---
title: include/vector-utils.h


---

# include/vector-utils.h












## Functions

|                | Name           |
| -------------- | -------------- |
| template \<typename T ,typename... Args\></br>void | **[FoldPushBack](https://github.com/devel0/iot-utils/tree/main/data/api/Files/vector-utils_8h.md#function-foldpushback)**(vector< T > & v, Args &&... args) <br>pushback to std::vector using c++17 folds ( [https://en.cppreference.com/w/cpp/language/fold](https://en.cppreference.com/w/cpp/language/fold) )  |








## Functions Documentation

### function FoldPushBack

```cpp
template <typename T ,
typename... Args>
void FoldPushBack(
    vector< T > & v,
    Args &&... args
)
```

pushback to std::vector using c++17 folds ( [https://en.cppreference.com/w/cpp/language/fold](https://en.cppreference.com/w/cpp/language/fold) ) 

**Parameters**: 

  * **v** vector 
  * **args** items to add 
































## Source code

```cpp
#ifndef _VECTOR_UTILS_H
#define _VECTOR_UTILS_H

#include <vector>

template <typename T, typename... Args>
void FoldPushBack(vector<T> &v, Args &&...args)
{
    (v.push_back(args), ...);
}

#endif
```


-------------------------------


