#ifndef _SEARCHATHING_TIMER_UTILS_H
#define _SEARCHATHING_TIMER_UTILS_H

#include <mbed.h>

/// retrieve seconds from given chrono representation
#define chrono_s(x)     std::chrono::duration_cast<chrono::seconds>(x).count()

/// retrieve milliseconds from given chrono representation
#define chrono_ms(x)    std::chrono::duration_cast<chrono::milliseconds>(x).count()

/// retrieve microseconds from given chrono representation
#define chrono_us(x)    std::chrono::duration_cast<chrono::microseconds>(x).count()

/// retrieve current kernel time_point ( diff between will generate std::chrono::milliseconds type )
#define clock_now()     Kernel::Clock::now()

#endif
