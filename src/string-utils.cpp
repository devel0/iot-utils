#include <sstream>

#include "string-utils.h"
#include "number-utils.h"

std::string tostr(double d, int decimals, bool trim_leading_zeroes)
{
    stringstream ss;

    // provide rounding
    int b10exp = 0;
    int64_t b10mantissa = frexp10(d, &b10exp);
    int absDecimals = decimals < 0 ? -decimals : decimals;
    int exc = 0;
    if (b10exp < -17)
        exc = abs(b10exp) - 17 + 1;
    else if (b10exp > 17)
        exc = -abs(b10exp) - 17 + 1;

    double q = pow(10, b10exp + absDecimals + exc);
    double d2 = ((double)b10mantissa * q);
    double pp = pow(10, -absDecimals - exc);
    d = round(d2) * pp;

    // final processing
    double k = 1;
    if (exc != 0)
        k = pow(10, -exc);
    b10mantissa = frexp10(d, &b10exp);

    bool neg = b10mantissa < 0 ? 1 : 0;
    if (neg)
    {
        ss << "-";
        b10mantissa = -b10mantissa;
    }

    stringstream sstmp;
    sstmp << b10mantissa;
    const string &strtmp = sstmp.str();

    int l = strtmp.length();
    bool sciMode = false;
    bool someDecimals = false;

    if (abs(l + b10exp) > 15 || decimals < 0)
    {
        int decCnt = 0;
        for (int i = 0; i < l && decCnt < absDecimals; ++i)
        {
            if (i == 1)
            {
                ss << '.';
                someDecimals = true;
            }
            if (i > 0)
                ++decCnt;
            ss << strtmp[i];
        }
        ss << "e" << b10exp + l - 1;
        sciMode = true;
    }
    else
    {
        if (b10exp < 0)
        {
            int decCnt = 0;
            int ee = -b10exp;
            bool onDec = ee > l;
            if (onDec)
            {
                ss << "0.";
                someDecimals = true;
                while (ee-- > l)
                {
                    ss << '0';
                    ++decCnt;
                }
            }
            int eeDot = l + b10exp;
            for (int i = 0; i < l && decCnt < decimals; ++i)
            {
                if (i == eeDot)
                {
                    ss << '.';
                    someDecimals = true;
                    onDec = true;
                }
                if (onDec)
                    ++decCnt;
                ss << strtmp[i];
            }
        }
        else
        {
            int decCnt = 0;
            int i = 0;
            while (i < l)
            {
                ss << strtmp[i];

                if (i > b10exp)
                    ++decCnt;
                if (decCnt >= decimals)
                    break;
                if (i == b10exp)
                {
                    ss << '.';
                    someDecimals = true;
                }
                ++i;
            }
        }
    }

    string s = ss.str();

    if (trim_leading_zeroes && someDecimals)
    {
        int sl = s.length();
        if (sl > 0)
        {
            int j = sl - 1;
            while (sciMode && j >= 0)
            {
                if (s[j] == 'e')
                    break;
                --j;
            }
            int u = j - 1;
            while (u >= 0)
            {
                if (s[u] != '0')
                {
                    if (s[u] == '.')
                        --u;
                    break;
                }
                --u;
            }
            if (u != j - 1)
            {
                stringstream sst;

                for (int k = 0; k <= u; ++k)
                {
                    sst << s[k];
                }
                for (int k = j; k <= sl; ++k)
                {
                    sst << s[k];
                }

                return sst.str();
            }
        }
    }

    return s;
}
