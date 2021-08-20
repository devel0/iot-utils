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
| double | **[ToRad](https://github.com/devel0/iot-utils/tree/main/data/api/Files/number-utils_8h.md#function-torad)**(double angleDeg) <br>convert given angle(deg) to rad  |
| double | **[ToDeg](https://github.com/devel0/iot-utils/tree/main/data/api/Files/number-utils_8h.md#function-todeg)**(double angleRad) <br>convert given angle(rad) to deg  |
| double | **[MRound](https://github.com/devel0/iot-utils/tree/main/data/api/Files/number-utils_8h.md#function-mround)**(double value, double multiple) <br>Round the given value using the multiple basis.  |
| double | **[Sign](https://github.com/devel0/iot-utils/tree/main/data/api/Files/number-utils_8h.md#function-sign)**(int n) <br>returns 1.0 if n>=0 ; -1 otherwise  |
| double | **[Sign](https://github.com/devel0/iot-utils/tree/main/data/api/Files/number-utils_8h.md#function-sign)**(double n) <br>returns 1.0 if n>=0 ; -1 otherwise  |
| int | **[Magnitude](https://github.com/devel0/iot-utils/tree/main/data/api/Files/number-utils_8h.md#function-magnitude)**(double value) <br>Magnitude of given number. (eg. 190 -> 1.9e2 -> 2) (eg. 0.0034 -> 3.4e-3 -> -3)  |








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




























### function ToRad

```cpp
double ToRad(
    double angleDeg
)
```

convert given angle(deg) to rad 




























### function ToDeg

```cpp
double ToDeg(
    double angleRad
)
```

convert given angle(rad) to deg 




























### function MRound

```cpp
double MRound(
    double value,
    double multiple
)
```

Round the given value using the multiple basis. 




























### function Sign

```cpp
double Sign(
    int n
)
```

returns 1.0 if n>=0 ; -1 otherwise 




























### function Sign

```cpp
double Sign(
    double n
)
```

returns 1.0 if n>=0 ; -1 otherwise 




























### function Magnitude

```cpp
int Magnitude(
    double value
)
```

Magnitude of given number. (eg. 190 -> 1.9e2 -> 2) (eg. 0.0034 -> 3.4e-3 -> -3) 
































## Source code

```cpp
#ifndef _SEARCHATHING_NUMBER_UTILS_H
#define _SEARCHATHING_NUMBER_UTILS_H

#ifdef ARDUINO
#include <Arduino.h>
#endif

int64_t frexp10(double d, int *expb10);

bool EqualsTol(double tol, double x, double y);

bool GreatThanTol(double tol, double x, double y);

bool GreatThanOrEqualsTol(double tol, double x, double y);

bool LessThanTol(double tol, double x, double y);

bool LessThanOrEqualsTol(double tol, double x, double y);

int CompareTol(double tol, double x, double y);

double ToRad(double angleDeg);

double ToDeg(double angleRad);

double MRound(double value, double multiple);

double Sign(int n);

double Sign(double n);

int Magnitude(double value);

#endif
```


-------------------------------


