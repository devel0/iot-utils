# iot-utils

<!-- TOC -->
* [Description](#description)
* [API](#api)
* [Quickstart](#quickstart)
* [Examples](#examples)
  + [double to string](#double-to-string)
* [Debugging](#debugging)
* [Unit tests](#unit-tests)
* [How this project was built](#how-this-project-was-built)
<!-- TOCEND -->

<hr/>

## Description

Utilities for ststm32, espressif8266, atmelavr platforms with arduino framework.

## API

- [classes](data/api/index_classes.md)
- core (arduino)
    - [number-utils](data/api/Files/number-utils_8h.md#file-number-utils.h)
    - [string-utils](data/api/Files/string-utils_8h.md#file-string-utils.h)
    - [constant-utils](data/api/Files/constant-utils_8h.md#file-constant-utils.h)
    - [vector-utils](data/api/Files/vector-utils_8h.md#file-vector-utils.h)
- dev
    - [sys-debug](data/api/Files/sys-debug_8h.md#sys-debug.h)

## Quickstart

Install using vscode command palette `PlatformIO: New Terminal` referring to [platformio registry](https://platformio.org/lib/show/11564/iot-utils/installation) cli mode doc.

### atmelavr deps

```
lib_deps = 	
	mike-matera/ArduinoSTL@^1.1.0	
```

## Examples

### double to string

```cpp
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

    // CRC32
    {
        string s = "somedata";
        auto sWithCRC = appendCRC(s);
        printf("[%s] with crc = [%s]\n", s.c_str(), sWithCRC.c_str());
        printf("[%s] has valid crc = %d\n", sWithCRC.c_str(), verifyCRC(sWithCRC));
        s = "somedata530CBDD1";
        printf("[%s] has valid crc = %d\n", s.c_str(), verifyCRC(s));
    }
}
```

## Unit tests

Test available [here](test/test-main.cpp).

To execute tests, from vscode command palette `PlatformIO: New Terminal` then

```sh
pio test
```

make sure serial monitor is closed

```
Testing...
If you don't see any output for the first 10 secs, please reset board (press reset button)

test/test-main.cpp:187:test_frexp10     [PASSED]
test/test-main.cpp:188:test_tostr       [PASSED]
test/test-main.cpp:189:test_slist       [PASSED]
test/test-main.cpp:190:test_vector      [PASSED]
-----------------------
4 Tests 0 Failures 0 Ignored
========================================= [PASSED] Took 12.59 seconds =========================================

Test    Environment    Status    Duration
------  -------------  --------  ------------
*       nucleo_f446re  PASSED    00:00:12.592
========================================= 1 succeeded in 00:00:12.592 =========================================
```

note: you may need to press RESET btn when in monitor to run tests

## How this project was built

References:
- [Creating Library](https://docs.platformio.org/en/latest/librarymanager/creating.html?utm_medium=piohome&utm_source=platformio)
- [library.json](https://docs.platformio.org/en/latest/librarymanager/config.html)
