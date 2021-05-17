---
title: include/timer-utils.h


---

# include/timer-utils.h














## Defines

|                | Name           |
| -------------- | -------------- |
|  | **[chrono_s](https://github.com/devel0/iot-utils/tree/main/data/api/Files/timer-utils_8h.md#define-chrono_s)**(x) <br>retrieve (double) seconds from given chrono representation  |
|  | **[chrono_ms](https://github.com/devel0/iot-utils/tree/main/data/api/Files/timer-utils_8h.md#define-chrono_ms)**(x) <br>retrieve (double) milliseconds from given chrono representation  |
|  | **[chrono_us](https://github.com/devel0/iot-utils/tree/main/data/api/Files/timer-utils_8h.md#define-chrono_us)**(x) <br>retrieve (double) microseconds from given chrono representation  |
|  | **[clock_now](https://github.com/devel0/iot-utils/tree/main/data/api/Files/timer-utils_8h.md#define-clock_now)**() <br>retrieve current kernel time_point ( diff between will generate std::chrono::milliseconds type )  |








## Macro Documentation

### define chrono_s

```cpp
#define chrono_s(
    x
) std::chrono::duration<double>(x).count()
```

retrieve (double) seconds from given chrono representation 




























### define chrono_ms

```cpp
#define chrono_ms(
    x
) ([chrono_s](https://github.com/devel0/iot-utils/tree/main/data/api/Files/timer-utils_8h.md#define-chrono_s)(x) * 1e3)
```

retrieve (double) milliseconds from given chrono representation 




























### define chrono_us

```cpp
#define chrono_us(
    x
) ([chrono_s](https://github.com/devel0/iot-utils/tree/main/data/api/Files/timer-utils_8h.md#define-chrono_s)(x) * 1e6)
```

retrieve (double) microseconds from given chrono representation 




























### define clock_now

```cpp
#define clock_now(
    
) Kernel::Clock::now()
```

retrieve current kernel time_point ( diff between will generate std::chrono::milliseconds type ) 






























## Source code

```cpp
#ifndef _SEARCHATHING_TIMER_UTILS_H
#define _SEARCHATHING_TIMER_UTILS_H

#ifdef ARDUINO
#include <Arduino.h>
#endif

#ifdef __MBED__
#include <mbed.h>
#endif

#define chrono_s(x) std::chrono::duration<double>(x).count()

#define chrono_ms(x) (chrono_s(x) * 1e3)

#define chrono_us(x) (chrono_s(x) * 1e6)

#define clock_now() Kernel::Clock::now()

#endif
```


-------------------------------

Updated on 17 May 2021 at 21:02:57 CEST
