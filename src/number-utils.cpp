#include "number-utils.h"

#ifdef ARDUINO
#include <string>
#include <limits>
//#include <math.h>
#endif

//#include <cmath>

using namespace std;

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

    // double a = b2mantissa * exp2(b2exp);
    // double c = 0;
    // int b10exp = round(log10(abs(a))) + 1;
    // int ee = 17 - b10exp;
    // double b = pow(10, ee);
    // c = a * b;
    // *expb10 = -ee;

    // return c;
    return 0;
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

double ToRad(double angleDeg)
{
    return angleDeg / 180.0 * PI;
}

double ToDeg(double angleRad)
{
    return angleRad / PI * 180.0;
}

double MRound(double value, double multiple)
{
    // if (abs(multiple) < std::numeric_limits<double>::epsilon())
    //     return value;

    // auto p = ::round(value / multiple);

    // return trunc(p) * multiple;
    return 0;
}

double Sign(int n)
{
    if (n >= 0)
        return 1.0;
    return -1.0;
}

double Sign(double n)
{
    if (n >= 0)
        return 1.0;
    return -1.0;
}

int Magnitude(double value)
{
    return 0;
    // auto a = abs(value);

    // if (a < std::numeric_limits<double>::epsilon())
    //     return 0;

    // auto y = log10(a);

    // return (int)floor(y);
}