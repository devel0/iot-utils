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
| string | **[appendCRC](https://github.com/devel0/iot-utils/tree/main/data/api/Files/string-utils_8h.md#function-appendcrc)**(const string & str) <br>create a new string with crc32 appended  |
| string | **[removeCRC](https://github.com/devel0/iot-utils/tree/main/data/api/Files/string-utils_8h.md#function-removecrc)**(const string & str) <br>remove CRC from string ( latest 8 chars )  |
| bool | **[verifyCRC](https://github.com/devel0/iot-utils/tree/main/data/api/Files/string-utils_8h.md#function-verifycrc)**(const string & str) <br>returns true if string of form "str...AABBCCDD" contains valid crc32  |








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




























### function appendCRC

```cpp
string appendCRC(
    const string & str
)
```

create a new string with crc32 appended 




























### function removeCRC

```cpp
string removeCRC(
    const string & str
)
```

remove CRC from string ( latest 8 chars ) 




























### function verifyCRC

```cpp
bool verifyCRC(
    const string & str
)
```

returns true if string of form "str...AABBCCDD" contains valid crc32 
































## Source code

```cpp
#ifndef _SEARCHATHING_STRING_UTILS_H
#define _SEARCHATHING_STRING_UTILS_H

#include <Arduino.h>
#include <string>

using namespace std;

#ifndef ESP8266

string tostr(double d, int decimals = -16, bool trim_leading_zeroes = true);

#endif

string ltrim(const string &str);

string rtrim(const string &str);

string trim(const string &str);

string appendCRC(const string &str);

string removeCRC(const string &str);

bool verifyCRC(const string& str);

#endif
```


-------------------------------


