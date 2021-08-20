#ifdef ARDUINO

#include "sys-debug.h"

Stream *sys_printer = NULL;

void setSystemPrinter(Stream &printer)
{
    sys_printer = &printer;
}

void (*customCallback)() = NULL;

void setInternalErrorCallback(void (*cb)())
{
    customCallback = cb;
}

void error(const char *fmt, ...)
{
    if (sys_printer != NULL)
    {
        // print error
        const int dstBufSize = 256;
        char dstBuf[dstBufSize];
        sys_printer->print("\nERROR : ");

        va_list args;
        va_start(args, fmt);
        vsnprintf(dstBuf, dstBufSize, fmt, args);
        va_end(args);

        sys_printer->print(dstBuf);

        sys_printer->print("\n");

        sys_printer->flush();
    }

    if (customCallback != NULL)
        customCallback();

    while (true)
        ;
}

void error()
{
    error("internal error");
}

#ifndef DISABLE_DEBUG
void debug(const char *fmt, ...)
{
    if (sys_printer != NULL)
    {        
        const int dstBufSize = 256;
        char dstBuf[dstBufSize];
        sys_printer->print("\nDEBUG : ");

        va_list args;
        va_start(args, fmt);
        vsnprintf(dstBuf, dstBufSize, fmt, args);
        va_end(args);

        sys_printer->print(dstBuf);

        sys_printer->print("\n");

        sys_printer->flush();
    }
}
#endif

#endif