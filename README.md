# iot-utils

<!-- TOC -->
any text
<!-- TOCEND -->

<hr/>

## Description

Utilities for ststm32 platform, mbed os framework.

- [extract mantissa, exp base 10][1]
- [double to string][2]
- [timer/clock macros][3]
- [simple linked list][4]

[1]: https://github.com/devel0/iot-utils/blob/d24eb41871fdbacb68edf2786f50ba79ad585a25/include%2Fnumber-utils.h#L12
[2]: https://github.com/devel0/iot-utils/blob/5fdf781f97cb69752d66480991e3c378ed6a4d17/include%2Fstring-utils.h#L13
[3]: https://github.com/devel0/iot-utils/blob/d5906d775a021a6ac925ade11db0b7ae57e56f9a/include/timer-utils.h#L7
[4]: https://github.com/devel0/iot-utils/blob/1a4a6af2157e699805c98761f147c9bf74a4cc26/include%2Fslist.h#L30

## API

- [classes](data/api/index_classes.md)
- [number-utils](data/api/Files/number-utils_8h.md#file-number-utils.h)
- [string-utils](data/api/Files/string-utils_8h.md#file-string-utils.h)
- [timer-utils](data/api/Files/string-utils_8h.md#file-timer-utils.h)
- [constant-utils](data/api/Files/string-utils_8h.md#file-constant-utils.h)

## Quickstart

Install using vscode command palette `PlatformIO: New Terminal` referring to [platformio registry](https://platformio.org/lib/show/11564/iot-utils/installation) cli mode doc.

If got trouble during compile, remove `.pio/libdeps/nucleo_f446re/iot-utils/library.json`.

## Examples

### double to string

```cpp
#include <mbed.h>

#include <number-utils.h>
#include <string-utils.h>
#include <timer-utils.h>
#include <slist.h>

int main()
{
    printf("START\n");

    //
    // DOUBLE TO STRING
    //
    {
        printf("%s\n", tostr(1234.5678901234567, 4).c_str());  // 1234.5679
        printf("%s\n", tostr(-1234.5678901234567, 4).c_str()); // -1234.5679

        printf("%s\n", tostr(1234.5678901234567, 10).c_str());  // 1234.5678901235
        printf("%s\n", tostr(-1234.5678901234567, 10).c_str()); // -1234.5678901235

        printf("%s\n", tostr(1234.5678901234567e-8, 6).c_str());  // 0.000012
        printf("%s\n", tostr(-1234.5678901234567e-8, 6).c_str()); // -0.000012

        printf("%s\n", tostr(1234.5678901234567e100, 6).c_str());  // 1.234568e103
        printf("%s\n", tostr(-1234.5678901234567e100, 6).c_str()); // -1.234568e103

        printf("%s\n", tostr(1234.5678901234567e-100, 6).c_str());  // 1.234568e-97
        printf("%s\n", tostr(-1234.5678901234567e-100, 6).c_str()); // -1.234568e-97

        printf("%s\n", tostr(1).c_str());              // 1e0
        printf("%s\n", tostr(1e20).c_str());           // 1e20
        printf("%s\n", tostr(1e20, 4).c_str());        // 1e20
        printf("%s\n", tostr(1e20, 4, false).c_str()); // 1.0000e20
        printf("%s\n", tostr(1, 4, false).c_str());    // 1.0000
        printf("%s\n", tostr(1.01200).c_str());        // 1.012e0

        printf("%s\n", tostr(1234.5678, 0, false).c_str());     // 1235
        printf("%s\n", tostr(1234.5678, 1, false).c_str());     // 1234.6
        printf("%s\n", tostr(0.00012345678, 0, false).c_str()); // 0
        printf("%s\n", tostr(0.00012345678, 4, false).c_str()); // 0.0001
        printf("%s\n", tostr(0.00012345678, 8, false).c_str()); // 0.00012346

        printf("%s\n", tostr(400, 1, false).c_str()); // 400.0
        printf("%s\n", tostr(400, 1).c_str());        // 400
    }

    //
    // TIMER
    //
    {

        Timer t;
        t.start();
        auto clkStart = clock_now(); // rtos::Kernel::Clock::time_point

        ThisThread::sleep_for(795ms);

        auto tDiff = t.elapsed_time();         // std::chrono::microseconds
        auto clkDiff = clock_now() - clkStart; // std::chrono::milliseconds

        auto clk_s = chrono_s(clkDiff);
        auto clk_ms = chrono_ms(clkDiff);
        auto clk_us = chrono_us(clkDiff);

        auto t_s = chrono_s(tDiff);
        auto t_ms = chrono_ms(tDiff);
        auto t_us = chrono_us(tDiff);

        // diff using clock (double) .795 s ; 795 ms ; 795000 us
        printf("diff using clock (double) %s s ; %s ms ; %s us\n",
            tostr(clk_s, 4).c_str(), tostr(clk_ms, 4).c_str(), tostr(clk_us, 4).c_str());

        // diff using timer (double) .795 s ; 795.033 ms ; 795033 us
        printf("diff using timer (double) %s s ; %s ms ; %s us\n",
            tostr(t_s, 4).c_str(), tostr(t_ms, 4).c_str(), tostr(t_us, 4).c_str());
    }

    //
    // SIMPLE LINKED LIST
    //
    {
        SList<int> lst;

        lst.Add(1);
        lst.Add(2);
        lst.Add(3);
        
        // lst[0] = 1
        // lst[1] = 2
        // lst[2] = 3

        int l = lst.Size();
        int i = 0;

        while (i < l)
        {
            printf("lst[%d] = %d\n", i, lst.Get(i));
            ++i;
        }

        // more efficient walking nodes

        auto n = lst.GetNode(0);
        i = 0;
        while (n != NULL)
        {
            printf("lst[%d] = %d\n", i, n->data);

            ++i;
            n = n->next;
        }
    }
}
```

## Debugging

to debug examples/example01.cpp (included through [src/debug-main.cpp](src/debug-main.cpp)) it may needed to select only 1 platform from `platformio.ini` so the launch.json will generate accordingly; todo that comment others platform, ie:

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

Test available [here](test/test-main.cpp).

To execute tests, from vscode command palette `PlatformIO: New Terminal` then

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
test/test-main.cpp:171:test_frexp10     [PASSED]
test/test-main.cpp:172:test_tostr       [PASSED]
test/test-main.cpp:173:test_slist       [PASSED]
test/test-main.cpp:174:test_timer       [PASSED]

-----------------------
4 Tests 0 Failures 0 Ignored 
OK
```

note: you may need to press RESET btn when in monitor to run tests

## How this project was built

References:
- [Creating Library](https://docs.platformio.org/en/latest/librarymanager/creating.html?utm_medium=piohome&utm_source=platformio)
- [library.json](https://docs.platformio.org/en/latest/librarymanager/config.html)
