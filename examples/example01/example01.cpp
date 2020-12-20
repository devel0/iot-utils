#ifndef UNIT_TEST

#include <mbed.h>

#include <number-utils.h>
#include <string-utils.h>
#include <timer-utils.h>

int main()
{
    printf("START\n");

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

    Timer t;
    t.start();
    auto clkStart = clock_now(); // rtos::Kernel::Clock::time_point

    ThisThread::sleep_for(1250ms);

    auto tDiff = t.elapsed_time();         // std::chrono::microseconds
    auto clkDiff = clock_now() - clkStart; // std::chrono::milliseconds

    auto clk_s = chrono_s(clkDiff);
    auto clk_ms = chrono_ms(clkDiff);
    auto clk_us = chrono_us(clkDiff);

    auto t_s = chrono_s(tDiff);
    auto t_ms = chrono_ms(tDiff);
    auto t_us = chrono_us(tDiff);

    // diff using clock 1 s ; 1250 ms ; 1250000 us
    printf("diff using clock %llu s ; %llu ms ; %llu us\n", clk_s, clk_ms, clk_us);

    // diff using timer 1 s ; 1249 ms ; 1249293 us
    printf("diff using timer %llu s ; %llu ms ; %llu us\n", t_s, t_ms, t_us);
}

#endif
