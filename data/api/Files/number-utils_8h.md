---
title: include/number-utils.h


---

# include/number-utils.h












## Functions

|                | Name           |
| -------------- | -------------- |
| int64_t | **[frexp10](https://github.com/devel0/iot-utils/tree/main/data/api/Files/number-utils_8h.md#function-frexp10)**(double d, int * expb10) <br>compute mantissa and exp base10  |
| bool | **[EqualsTol](https://github.com/devel0/iot-utils/tree/main/data/api/Files/number-utils_8h.md#function-equalstol)**(double tol, double x, double y) <br>true if ( |x-y| <= tol )  |
| bool | **[GreatThanTol](https://github.com/devel0/iot-utils/tree/main/data/api/Files/number-utils_8h.md#function-greatthantol)**(double tol, double x, double y) <br>true if (x > y) AND NOT ( |x-y| <= tol )  |
| bool | **[GreatThanOrEqualsTol](https://github.com/devel0/iot-utils/tree/main/data/api/Files/number-utils_8h.md#function-greatthanorequalstol)**(double tol, double x, double y) <br>true if (x > y) AND ( |x-y| <= tol )  |
| bool | **[LessThanTol](https://github.com/devel0/iot-utils/tree/main/data/api/Files/number-utils_8h.md#function-lessthantol)**(double tol, double x, double y) <br>true if (x < y) AND NOT ( |x-y| <= tol )  |
| bool | **[LessThanOrEqualsTol](https://github.com/devel0/iot-utils/tree/main/data/api/Files/number-utils_8h.md#function-lessthanorequalstol)**(double tol, double x, double y) <br>true if (x < y) AND ( |x-y| <= tol )  |
| int | **[CompareTol](https://github.com/devel0/iot-utils/tree/main/data/api/Files/number-utils_8h.md#function-comparetol)**(double tol, double x, double y) <br>return 0 if equalstol, -1 if x<~y or 1 if x>~y  |








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





















### function EqualsTol

```cpp
bool EqualsTol(
    double tol,
    double x,
    double y
)
```

true if ( |x-y| <= tol ) 




























### function GreatThanTol

```cpp
bool GreatThanTol(
    double tol,
    double x,
    double y
)
```

true if (x > y) AND NOT ( |x-y| <= tol ) 




























### function GreatThanOrEqualsTol

```cpp
bool GreatThanOrEqualsTol(
    double tol,
    double x,
    double y
)
```

true if (x > y) AND ( |x-y| <= tol ) 




























### function LessThanTol

```cpp
bool LessThanTol(
    double tol,
    double x,
    double y
)
```

true if (x < y) AND NOT ( |x-y| <= tol ) 




























### function LessThanOrEqualsTol

```cpp
bool LessThanOrEqualsTol(
    double tol,
    double x,
    double y
)
```

true if (x < y) AND ( |x-y| <= tol ) 




























### function CompareTol

```cpp
int CompareTol(
    double tol,
    double x,
    double y
)
```

return 0 if equalstol, -1 if x<~y or 1 if x>~y 
































## Source code

```cpp
#ifndef _SEARCHATHING_NUMBER_UTILS_H
#define _SEARCHATHING_NUMBER_UTILS_H

#ifdef ARDUINO
#include <Arduino.h>
#endif

#ifdef __MBED__
#include <mbed.h>
#endif

int64_t frexp10(double d, int *expb10);

bool EqualsTol(double tol, double x, double y);

bool GreatThanTol(double tol, double x, double y);

bool GreatThanOrEqualsTol(double tol, double x, double y);

bool LessThanTol(double tol, double x, double y);

bool LessThanOrEqualsTol(double tol, double x, double y);

int CompareTol(double tol, double x, double y);

#endif
```


-------------------------------


