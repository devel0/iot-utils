#ifndef _SEARCHATHING_TIMER_UTILS_H
#define _SEARCHATHING_TIMER_UTILS_H

#ifdef ARDUINO
#include <Arduino.h>
#endif

#ifdef __MBED__
#include <mbed.h>
#endif

/**
 * @brief retrieve (double) seconds from given chrono representation
 */
#define chrono_s(x) std::chrono::duration<double>(x).count()

/**
 * @brief retrieve (double) milliseconds from given chrono representation
 */
#define chrono_ms(x) (chrono_s(x) * 1e3)

/**
 * @brief retrieve (double) microseconds from given chrono representation
 */
#define chrono_us(x) (chrono_s(x) * 1e6)

/**
 * @brief retrieve current kernel time_point ( diff between will generate std::chrono::milliseconds type )
 */
#define clock_now() Kernel::Clock::now()

#endif
