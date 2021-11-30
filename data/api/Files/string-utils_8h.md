---
title: include/string-utils.h


---

# include/string-utils.h












## Functions

|                | Name           |
| -------------- | -------------- |
| string | **[ltrim](https://github.com/devel0/iot-utils/tree/main/data/api/Files/string-utils_8h.md#function-ltrim)**(const string & str) <br>trim beginning spaces  |
| string | **[rtrim](https://github.com/devel0/iot-utils/tree/main/data/api/Files/string-utils_8h.md#function-rtrim)**(const string & str) <br>trim ending spaces  |
| string | **[trim](https://github.com/devel0/iot-utils/tree/main/data/api/Files/string-utils_8h.md#function-trim)**(const string & str) <br>trim begin and ending spaces  |
| int | **[computeChecksum](https://github.com/devel0/iot-utils/tree/main/data/api/Files/string-utils_8h.md#function-computechecksum)**(const String & str) <br>compute xor checksum of given string  |
| String | **[appendChecksum](https://github.com/devel0/iot-utils/tree/main/data/api/Files/string-utils_8h.md#function-appendchecksum)**(const String & str) <br>create a new string with xor checksum appended  |
| String | **[removeChecksum](https://github.com/devel0/iot-utils/tree/main/data/api/Files/string-utils_8h.md#function-removechecksum)**(const String & str) <br>remove xor checksum from string ( latest 2 chars )  |
| bool | **[verifyChecksum](https://github.com/devel0/iot-utils/tree/main/data/api/Files/string-utils_8h.md#function-verifychecksum)**(const String & str) <br>returns true if string of form "str...XX" contains valid xor checksum  |








## Functions Documentation

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




























### function computeChecksum

```cpp
int computeChecksum(
    const String & str
)
```

compute xor checksum of given string 




























### function appendChecksum

```cpp
String appendChecksum(
    const String & str
)
```

create a new string with xor checksum appended 




























### function removeChecksum

```cpp
String removeChecksum(
    const String & str
)
```

remove xor checksum from string ( latest 2 chars ) 




























### function verifyChecksum

```cpp
bool verifyChecksum(
    const String & str
)
```

returns true if string of form "str...XX" contains valid xor checksum 
































## Source code

```cpp
#ifndef _SEARCHATHING_STRING_UTILS_H
#define _SEARCHATHING_STRING_UTILS_H

#include <Arduino.h>

#include <string>

using namespace std;

#ifdef ARDUINO_ARCH_STM32

string tostr(double d, int decimals = -16, bool trim_leading_zeroes = true);

#endif

string ltrim(const string &str);

string rtrim(const string &str);

string trim(const string &str);

int computeChecksum(const String &str);

String appendChecksum(const String &str);

String removeChecksum(const String &str);

bool verifyChecksum(const String& str);

#endif
```


-------------------------------


