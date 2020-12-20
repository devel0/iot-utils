#include <mbed.h>
#include <unity.h>

#include <string-utils.h>
#include <number-utils.h>
#include <constant-utils.h>
#include <slist.h>

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

    n = 1234.5678;
    TEST_ASSERT_EQUAL_STRING("1235", tostr(n, 0).c_str());

    n = 1234.5678;
    TEST_ASSERT_EQUAL_STRING("1234.6", tostr(n, 1).c_str());

    n = 0.00012345678;
    TEST_ASSERT_EQUAL_STRING("0", tostr(n, 0).c_str());

    n = 0.00012345678;
    TEST_ASSERT_EQUAL_STRING("0.0001", tostr(n, 4).c_str());

    n = 0.00012345678;
    TEST_ASSERT_EQUAL_STRING("0.00012346", tostr(n, 8).c_str());

    n = -0.00012345678;
    TEST_ASSERT_EQUAL_STRING("-0.00012346", tostr(n, 8).c_str());

    n = 400;
    TEST_ASSERT_EQUAL_STRING("400.0", tostr(n, 1, false).c_str());

    n = 400;
    TEST_ASSERT_EQUAL_STRING("400", tostr(n, 1).c_str());
}

void test_slist()
{
    SList<int> l;

    l.Add(1);
    l.Add(2);
    l.Add(3);

    TEST_ASSERT_EQUAL(3, l.Size());

    TEST_ASSERT_EQUAL(1, l.Get(0));
    TEST_ASSERT_EQUAL(2, l.Get(1));
    TEST_ASSERT_EQUAL(3, l.Get(2));

    auto n = l.GetNode(0);
    TEST_ASSERT_EQUAL(1, n->data);
    TEST_ASSERT_NOT_EQUAL(NULL, n->next);
    n = n->next;
    TEST_ASSERT_EQUAL(2, n->data);
    TEST_ASSERT_NOT_EQUAL(NULL, n->next);
    n = n->next;
    TEST_ASSERT_EQUAL(3, n->data);
    TEST_ASSERT_EQUAL(NULL, n->next);

    SList<int> l2 = l; // l2 is a copy because = overloaded

    l.Remove(1);
    TEST_ASSERT_EQUAL(2, l.Size());
    TEST_ASSERT_EQUAL(3, l2.Size());

    n = l.GetNode(0);
    TEST_ASSERT_EQUAL(1, n->data);
    TEST_ASSERT_NOT_EQUAL(NULL, n->next);
    n = n->next;    
    TEST_ASSERT_EQUAL(3, n->data);
    TEST_ASSERT_EQUAL(NULL, n->next);
}

int main()
{
    UNITY_BEGIN();
    RUN_TEST(test_frexp10);
    RUN_TEST(test_tostr);
    RUN_TEST(test_slist);
    UNITY_END();
}