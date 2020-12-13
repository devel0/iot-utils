#ifndef UNIT_TEST

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

#endif
