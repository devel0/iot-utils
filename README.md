# iot-utils

<!-- TOC -->
* [Description](#description)
* [API](#api)
* [Quickstart](#quickstart)
* [Examples](#examples)
  + [lcd rotary menu](#lcd-rotary-menu)
  + [lcd rotary menu with tags](#lcd-rotary-menu-with-tags)
  + [double to string](#double-to-string)
* [Debugging](#debugging)
* [Unit tests](#unit-tests)
* [How this project was built](#how-this-project-was-built)
<!-- TOCEND -->

<hr/>

## Description

Utilities for ststm32 platform, mbed os framework.

## API

- [classes](data/api/index_classes.md)
- core (arduino, mbed)
    - [number-utils](data/api/Files/number-utils_8h.md#file-number-utils.h)
    - [string-utils](data/api/Files/string-utils_8h.md#file-string-utils.h)
    - [timer-utils](data/api/Files/timer-utils_8h.md#file-timer-utils.h)
    - [constant-utils](data/api/Files/constant-utils_8h.md#file-constant-utils.h)
    - [vector-utils](data/api/Files/vector-utils_8h.md#file-vector-utils.h)
- lcd rotary menu (arduino)
    - [lcd-rotary-menu](data/api/Files/lcd-rotary-menu_8h.md#lcd-rotary-menu.h)
    - [lcd-rotary-menuitem](data/api/Files/lcd-rotary-menuitem_8h.md#lcd-rotary-menuitem.h)
    - [debounced-button](data/api/Files/debounced-button_8h.md#debounced-button.h)
    - [debounced-rotary](data/api/Files/debounced-rotary_8h.md#debounced-rotary.h)
- dev
    - [sys-debug](data/api/Files/sys-debug_8h.md#sys-debug.h)

## Quickstart

Install using vscode command palette `PlatformIO: New Terminal` referring to [platformio registry](https://platformio.org/lib/show/11564/iot-utils/installation) cli mode doc.

## Examples

### lcd rotary menu

```cpp
#include <lcd-rotary-menu.h>
#include <lcd-rotary-menuitem.h>

#include <sys-debug.h>

// rotary menu example

LCDRotaryMenu *menu;

// check i2c lcd address using i2c scanner
#define LCD_ADDR 0x3F
#define LCD_COLS 16
#define LCD_ROWS 2

#define ROT_A_PIN 40
#define ROT_B_PIN 41
#define ROT_SW_PIN 45

#define SPLASH_TIMEOUT_MS 1000

void LCDSplash(LiquidCrystal_I2C &lcd)
{
    lcd.setCursor(0, 0);
    lcd.print("firmware");
    lcd.setCursor(0, 1);
    lcd.print("version");
}

void reboot()
{
    debug("would to reboot...");
}

void setup()
{
    Serial.begin(9600);
    setSystemPrinter(Serial); // for debug and error notice

    auto inverted = false; // set to true if want to invert cw/ccw behavior

    menu = new LCDRotaryMenu(LCD_ADDR, LCD_COLS, LCD_ROWS, ROT_A_PIN, ROT_B_PIN, ROT_SW_PIN, inverted);

    // splash screen ( custom lcd usage ) ; call this before menu init
    menu->setSplashCb(LCDSplash, SPLASH_TIMEOUT_MS);

    menu->init();

    // compose follow menu
    //
    // sample1
    // sample2
    // dev---+
    //       reboot
    //       test

    auto &root = menu->getRoot();

    root.append("sample1");
    root.append("sample2");

    auto &dev = root.append("dev");

    dev.append("reboot").onSelect(reboot);
    dev.append("test1");
}

void loop()
{
    menu->loop();
}
```

### lcd rotary menu with tags

[see example03](examples/example03/example03.cpp)

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

    // v (size=6) : {1.2, 3.4, 5.6, 7.8, 9.10, 11.12}
    {
        vector<double> v;
        FoldPushBack(v, 1.2, 3.4, 5.6, 7.8);
        FoldPushBack(v, 9.10, 11.12);

        printf("v (size=%d) : {", v.size());
        for (int i = 0; i < v.size(); ++i)
        {
            printf("%s%s", i > 0 ? ", " : "", tostr(v[i], 2).c_str());
        }
        printf("}\n");
    }

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
