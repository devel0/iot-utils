#include <mbed.h>
#include <unity.h>

#include "string-utils.h"
#include "number-utils.h"
#include "constant-utils.h"

double test_frexp10_helper(double input)
{
    int b10exp = 0;
    int64_t res = frexp10(input, &b10exp);
    return res * pow(10, b10exp);
}

void test_frexp10()
{
    double n = 0;

    n = 1234.5678901234567;
    TEST_ASSERT_EQUAL_DOUBLE(n, test_frexp10_helper(n));

    n = -1234.5678901234567;
    TEST_ASSERT_EQUAL_DOUBLE(n, test_frexp10_helper(n));

    n = 1234.5678901234567e100;
    TEST_ASSERT_EQUAL_DOUBLE(n, test_frexp10_helper(n));

    n = -1234.5678901234567e100;
    TEST_ASSERT_EQUAL_DOUBLE(n, test_frexp10_helper(n));

    n = 1234.5678901234567e-100;
    TEST_ASSERT_EQUAL_DOUBLE(n, test_frexp10_helper(n));

    n = -1234.5678901234567e-100;
    TEST_ASSERT_EQUAL_DOUBLE(n, test_frexp10_helper(n));
}

void test_tostr()
{
    double n = 0;

    n = 1234.5678901234567;
    TEST_ASSERT_EQUAL_STRING("1234.5679", tostr(n, 4).c_str());

    n = -1234.5678901234567;
    TEST_ASSERT_EQUAL_STRING("-1234.5679", tostr(n, 4).c_str());

    n = 1234.5678901234567;
    TEST_ASSERT_EQUAL_STRING("1234.5678901235", tostr(n, 10).c_str());

    n = -1234.5678901234567;
    TEST_ASSERT_EQUAL_STRING("-1234.5678901235", tostr(n, 10).c_str());

    n = 1234.5678901234567e-8;
    TEST_ASSERT_EQUAL_STRING("0.000012", tostr(n, 6).c_str());

    n = -1234.5678901234567e-8;
    TEST_ASSERT_EQUAL_STRING("-0.000012", tostr(n, 6).c_str());

    n = 1234.5678901234567e100;
    TEST_ASSERT_EQUAL_STRING("1.234568e103", tostr(n, 6).c_str());

    n = -1234.5678901234567e100;
    TEST_ASSERT_EQUAL_STRING("-1.234568e103", tostr(n, 6).c_str());

    n = 1234.5678901234567e-100;
    TEST_ASSERT_EQUAL_STRING("1.234568e-97", tostr(n, 6).c_str());

    n = -1234.5678901234567e-100;
    TEST_ASSERT_EQUAL_STRING("-1.234568e-97", tostr(n, 6).c_str());

    n = 1;
    TEST_ASSERT_EQUAL_STRING("1e0", tostr(n).c_str());

    n = 1e20;
    TEST_ASSERT_EQUAL_STRING("1e20", tostr(n).c_str());

    n = 1e20;
    TEST_ASSERT_EQUAL_STRING("1e20", tostr(n, 4).c_str());

    n = 1e20;
    TEST_ASSERT_EQUAL_STRING("1.0000e20", tostr(n, 4, false).c_str());

    n = 1;
    TEST_ASSERT_EQUAL_STRING("1.0000", tostr(n, 4, false).c_str());

    n = 1.01200;
    TEST_ASSERT_EQUAL_STRING("1.012e0", tostr(n).c_str());
}

int main()
{
    UNITY_BEGIN();
    RUN_TEST(test_frexp10);
    RUN_TEST(test_tostr);
    UNITY_END();
}