---
title: include/sys-debug.h


---

# include/sys-debug.h
























## Source code

```cpp
#ifndef _SYS_DEBUG_H
#define _SYS_DEBUG_H

#ifdef ARDUINO

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

#endif
```


-------------------------------

Updated on 17 May 2021 at 20:39:28 CEST
