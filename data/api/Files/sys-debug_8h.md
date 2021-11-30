---
title: include/sys-debug.h


---

# include/sys-debug.h












## Functions

|                | Name           |
| -------------- | -------------- |
| void | **[setSystemPrinter](https://github.com/devel0/iot-utils/tree/main/data/api/Files/sys-debug_8h.md#function-setsystemprinter)**(Stream & printer) <br>set printer to receive debug and internal error messages  |
| void | **[setInternalErrorCallback](https://github.com/devel0/iot-utils/tree/main/data/api/Files/sys-debug_8h.md#function-setinternalerrorcallback)**(void(*)() cb) <br>set fn callback before infinite loop on internal error  |
| void | **[error](https://github.com/devel0/iot-utils/tree/main/data/api/Files/sys-debug_8h.md#function-error)**(const char * fmt, ... ) <br>generate an internal error issueing a print ( if setSystemPrinter used ), calling custom callback ( if setInternalErrorCallback used ) then going for infinite loop  |
| void | **[error](https://github.com/devel0/iot-utils/tree/main/data/api/Files/sys-debug_8h.md#function-error)**() <br>same as error(fmt, ...) but without argument printing "internal error" as message  |
| void | **[debug](https://github.com/devel0/iot-utils/tree/main/data/api/Files/sys-debug_8h.md#function-debug)**(const char * fmt, ... ) <br>generate debug message issueing a print ( if setSystemPrinter used ) unless -DDISABLE_DEBUG defined  |








## Functions Documentation

### function setSystemPrinter

```cpp
void setSystemPrinter(
    Stream & printer
)
```

set printer to receive debug and internal error messages 

**Parameters**: 

  * **printer** Serial, Serial2, ... 




























### function setInternalErrorCallback

```cpp
void setInternalErrorCallback(
    void(*)() cb
)
```

set fn callback before infinite loop on internal error 

**Parameters**: 

  * **cb** custom callback 




























### function error

```cpp
void error(
    const char * fmt,
    ... 
)
```

generate an internal error issueing a print ( if setSystemPrinter used ), calling custom callback ( if setInternalErrorCallback used ) then going for infinite loop 

**Parameters**: 

  * **fmt** printf like msg to print ( newline automatically appended ) 
  * **...** 




























### function error

```cpp
void error()
```

same as error(fmt, ...) but without argument printing "internal error" as message 




























### function debug

```cpp
void debug(
    const char * fmt,
    ... 
)
```

generate debug message issueing a print ( if setSystemPrinter used ) unless -DDISABLE_DEBUG defined 

**Parameters**: 

  * **fmt** 
  * **...** 
































## Source code

```cpp
#ifndef _SYS_DEBUG_H
#define _SYS_DEBUG_H

#include <Arduino.h>

void setSystemPrinter(Stream &printer);

void setInternalErrorCallback(void (*cb)());

void error(const char *fmt, ...);

void error();

#ifdef DISABLE_DEBUG
#define debug(fmt, ...) {}
#else
void debug(const char *fmt, ...);
#endif

#endif
```


-------------------------------


