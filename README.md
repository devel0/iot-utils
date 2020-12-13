# iot-utils

## Description

Utilities for ststm32 platform, mbed os framework.

- [double to string][1]

[1]: 

## Examples

### double to string

```cpp
#include <mbed.h>

#include "number-utils.h"
#include "string-utils.h"

int main()
{
    printf("START\n");

    printf("[%s]\n", tostr(1234.5678901234567, 4).c_str());
    printf("[%s]\n", tostr(-1234.5678901234567, 4).c_str());

    printf("[%s]\n", tostr(1234.5678901234567, 10).c_str());
    printf("[%s]\n", tostr(-1234.5678901234567, 10).c_str());

    printf("[%s]\n", tostr(1234.5678901234567e-8, 6).c_str());
    printf("[%s]\n", tostr(-1234.5678901234567e-8, 6).c_str());

    printf("[%s]\n", tostr(1234.5678901234567e100, 6).c_str());
    printf("[%s]\n", tostr(-1234.5678901234567e100, 6).c_str());

    printf("[%s]\n", tostr(1234.5678901234567e-100, 6).c_str());
    printf("[%s]\n", tostr(-1234.5678901234567e-100, 6).c_str());
}
```

produce follow

```
START
[1234.5679]
[-1234.5679]
[1234.5678901235]
[-1234.5678901235]
[1.234568e-5]
[-1.234568e-5]
[1.234568e103]
[-1.234568e103]
[1.234568e-97]
[-1.234568e-97]
```

## Unit tests

from vscode command palette `PlatformIO: New Terminal` then

```sh
pio test
```

when started from vscode command palette `PlatformIO: Serial Monitor` (ctrl+alt+s) see test results.

```
> Executing task: pio device monitor <

--- Available filters and text transformations: colorize, debug, default, direct, hexlify, log2file, nocontrol, printable, send_on_enter, time
--- More details at http://bit.ly/pio-monitor-filters
--- Miniterm on /dev/ttyACM0  9600,8,N,1 ---
--- Quit: Ctrl+C | Menu: Ctrl+T | Help: Ctrl+T followed by Ctrl+H ---
test/test-main.cpp:76:test_frexp10:PASS
test/test-main.cpp:77:test_tostr:PASS

-----------------------
2 Tests 0 Failures 0 Ignored 
OK
```

note: you may need to press RESET btn when in monitor to run tests

## How this project was built

References:
- [Creating Librart](https://docs.platformio.org/en/latest/librarymanager/creating.html?utm_medium=piohome&utm_source=platformio)
- [library.json](https://docs.platformio.org/en/latest/librarymanager/config.html)
