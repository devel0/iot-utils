#include "number-utils.h"

int64_t frexp10(double d, int *expb10)
{
    //
    // IEE.754: double precision format
    //
    // | SIGN | EXPONENT 1023 biased | MANTISSA |
    // +------+----------------------+----------+
    // | 1bit | 11bit                | 52bit    |
    //

    // https://en.wikipedia.org/wiki/Double-precision_floating-point_format

    if (d == 0.0)
    {
        *expb10 = 0;
        return 0;
    }

    int b2exp;
    double b2mantissa = frexp(d, &b2exp); // d = b2mantissa * pow(2, b2exp)

    double a = b2mantissa * exp2(b2exp);
    double c = 0;
    int b10exp = round(log10(abs(a))) + 1;
    int ee = 17 - b10exp;
    double b = pow(10, ee);
    c = a * b;
    *expb10 = -ee;

    return c;
}

bool EqualsTol(double tol, double x, double y)
{
    return abs(x - y) <= tol;
}

bool GreatThanTol(double tol, double x, double y)
{
    return x > y && !EqualsTol(tol, x, y);
}

bool GreatThanOrEqualsTol(double tol, double x, double y)
{
    return x > y || EqualsTol(tol, x, y);
}

bool LessThanTol(double tol, double x, double y)
{
    return x < y && !EqualsTol(tol, x, y);
}

bool LessThanOrEqualsTol(double tol, double x, double y)
{
    return x < y || EqualsTol(tol, x, y);
}

int CompareTol(double tol, double x, double y)
{
    if (EqualsTol(tol, x, y))
        return 0;
    if (x < y)
        return -1;
    return 1;
}