---
title: include/string-utils.h


---

# include/string-utils.h












## Functions

|                | Name           |
| -------------- | -------------- |
| string | **[tostr](https://github.com/devel0/iot-utils/tree/main/data/api/Files/string-utils_8h.md#function-tostr)**(double d, int decimals =-16, bool trim_leading_zeroes =true) <br>convert given double to string  |
| string | **[ltrim](https://github.com/devel0/iot-utils/tree/main/data/api/Files/string-utils_8h.md#function-ltrim)**(const string & str) <br>trim beginning spaces  |
| string | **[rtrim](https://github.com/devel0/iot-utils/tree/main/data/api/Files/string-utils_8h.md#function-rtrim)**(const string & str) <br>trim ending spaces  |
| string | **[trim](https://github.com/devel0/iot-utils/tree/main/data/api/Files/string-utils_8h.md#function-trim)**(const string & str) <br>trim begin and ending spaces  |








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





















### function ltrim

```cpp
string ltrim(
    const string & str
)
```

trim beginning spaces 




























### function rtrim

```cpp
string rtrim(
    const string & str
)
```

trim ending spaces 




























### function trim

```cpp
string trim(
    const string & str
)
```

trim begin and ending spaces 
































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

string ltrim(const string &str);

string rtrim(const string &str);

string trim(const string &str);

#endif
```


-------------------------------


