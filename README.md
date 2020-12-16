# iot-utils

## Description

Utilities for ststm32 platform, mbed os framework.

- [double to string][1]

[1]: https://github.com/devel0/iot-utils/blob/d24eb41871fdbacb68edf2786f50ba79ad585a25/include%2Fstring-utils.h#L14

## Quickstart

Install using vscode command palette `PlatformIO: New Terminal` referring to [platformio registry](https://platformio.org/lib/show/11564/iot-utils/installation) cli mode doc.

If got trouble during compile, remove `.pio/libdeps/nucleo_f446re/iot-utils/library.json`.

## Examples

### double to string

```cpp
#include <mbed.h>

#include <number-utils.h>
#include <string-utils.h>

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

## Debugging

to debug examples/example01.cpp if may needed to select only 1 platform from `platformio.ini` so the launch.json will generate accordingly; todo that comment others platform, ie:

```
[env]
src_filter = +<*> -<.git/> -<.svn/> -<example/> -<examples/> -<test/> -<tests/>

; [platformio]
; default_envs = nucleo_f446re, nucleo_f767zi

[env:nucleo_f767zi]
platform = ststm32
board = nucleo_f767zi
framework = mbed
test_build_project_src = true
debug_build_flags = -O0 -g -ggdb

; [env:nucleo_f446re]
; platform = ststm32
; board = nucleo_f446re
; framework = mbed
; test_build_project_src = true
; debug_build_flags = -O0 -g -ggdb
```

- [other references/troubleshoot](https://github.com/devel0/iot-stm32-ledblink-interrupt-debug#iot-stm32-ledblink-interrupt-debug)

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
- [Creating Library](https://docs.platformio.org/en/latest/librarymanager/creating.html?utm_medium=piohome&utm_source=platformio)
- [library.json](https://docs.platformio.org/en/latest/librarymanager/config.html)
