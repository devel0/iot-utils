---
title: include/string-utils.h


---

# include/string-utils.h












## Functions

|                | Name           |
| -------------- | -------------- |
| string | **[tostr](https://github.com/devel0/iot-utils/tree/main/data/api/Files/string-utils_8h.md#function-tostr)**(double d, int decimals =-16, bool trim_leading_zeroes =true) <br>convert given double to string  |








## Functions Documentation

### function tostr

```cpp
string tostr(
    double d,
    int decimals =-16,
    bool trim_leading_zeroes =true
)
```

convert given double to string 

**Parameters**: 

  * **d** value to convert to string 
  * **decimals** number of decimals to show rounding on last decimal; if negative or digits+b10exp exceed 15 length then scimode is selected automatically 
  * **trim_leading_zeroes** trim_leading_zeroes if true autoremove decimals ending zeroes 







**Return**: std::string representation of given value 

























## Source code

```cpp
#ifndef _SEARCHATHING_STRING_UTILS_H
#define _SEARCHATHING_STRING_UTILS_H

#ifdef ARDUINO
#include <Arduino.h>
#endif

#ifdef __MBED__
#include <mbed.h>
#endif

using namespace std;

string tostr(double d, int decimals = -16, bool trim_leading_zeroes = true);

#endif
```


-------------------------------

Updated on 20 May 2021 at 12:04:49 CEST
