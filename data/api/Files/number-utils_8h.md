---
title: include/number-utils.h


---

# include/number-utils.h












## Functions

|                | Name           |
| -------------- | -------------- |
| int64_t | **[frexp10](https://github.com/devel0/iot-utils/tree/main/data/api/Files/number-utils_8h.md#function-frexp10)**(double d, int * expb10) <br>compute mantissa and exp base10  |








## Functions Documentation

### function frexp10

```cpp
int64_t frexp10(
    double d,
    int * expb10
)
```

compute mantissa and exp base10 

**Parameters**: 

  * **d** value to compute mantissa,exp from 
  * **expb10** ptr to exp where store exp info 







**Return**: int64_t mantissa base10 of given number so that d=res*10^expb10 

























## Source code

```cpp
#ifndef _SEARCHATHING_NUMBER_UTILS_H
#define _SEARCHATHING_NUMBER_UTILS_H

#include <mbed.h>

int64_t frexp10(double d, int *expb10);

#endif
```


-------------------------------

Updated on  6 January 2021 at 13:20:24 CET
