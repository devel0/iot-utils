#ifndef UNIT_TEST

#include <mbed.h>

#include "number-utils.h"
#include "string-utils.h"

int main()
{
    printf("START\n");
    
    printf("%s\n", tostr(1234.5678901234567, 4).c_str());       // 1234.5679
    printf("%s\n", tostr(-1234.5678901234567, 4).c_str());      // -1234.5679

    printf("%s\n", tostr(1234.5678901234567, 10).c_str());      // 1234.5678901235
    printf("%s\n", tostr(-1234.5678901234567, 10).c_str());     // -1234.5678901235

    printf("%s\n", tostr(1234.5678901234567e-8, 6).c_str());    // 0.000012
    printf("%s\n", tostr(-1234.5678901234567e-8, 6).c_str());   // -0.000012

    printf("%s\n", tostr(1234.5678901234567e100, 6).c_str());   // 1.234568e103
    printf("%s\n", tostr(-1234.5678901234567e100, 6).c_str());  // -1.234568e103

    printf("%s\n", tostr(1234.5678901234567e-100, 6).c_str());  // 1.234568e-97
    printf("%s\n", tostr(-1234.5678901234567e-100, 6).c_str()); // -1.234568e-97
    
    printf("%s\n", tostr(1).c_str());                       // 1e0
    printf("%s\n", tostr(1e20).c_str());                    // 1e20
    printf("%s\n", tostr(1e20, 4).c_str());                 // 1e20
    printf("%s\n", tostr(1e20, 4, false).c_str());          // 1.0000e20
    printf("%s\n", tostr(1, 4, false).c_str());             // 1.0000
    printf("%s\n", tostr(1.01200).c_str());                 // 1.012e0    

    printf("%s\n", tostr(1234.5678, 0, false).c_str());     // 1235
    printf("%s\n", tostr(1234.5678, 1, false).c_str());     // 1234.6
    printf("%s\n", tostr(0.00012345678, 0, false).c_str()); // 0
    printf("%s\n", tostr(0.00012345678, 4, false).c_str()); // 0.0001
    printf("%s\n", tostr(0.00012345678, 8, false).c_str()); // 0.00012346

    printf("%s\n", tostr(400, 1, false).c_str());           // 400.0
    printf("%s\n", tostr(400, 1).c_str());                  // 400
}

#endif
