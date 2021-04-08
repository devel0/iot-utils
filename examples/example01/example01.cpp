#ifndef UNIT_TEST

#include <number-utils.h>
#include <string-utils.h>
#include <timer-utils.h>
#include <slist.h>
#include <vector-utils.h>

#if defined(ARDUINO)
void setup()
#else
int main()
#endif
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
        printf("%s\n", tostr(1, 4, false).c_str()); // 1.0000
        printf("%s\n", tostr(0, 2).c_str());        // 0
        printf("%s\n", tostr(0, 2, false).c_str()); // 0.00

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
#ifdef __MBED__
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
#endif

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

#if defined(ARDUINO)
void loop()
{
}
#endif

#endif