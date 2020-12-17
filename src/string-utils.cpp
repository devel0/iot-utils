#include <sstream>

#include "string-utils.h"
#include "number-utils.h"

std::string tostr(double d, int decimals, bool trim_leading_zeroes)
{
    stringstream ss;

    // provide rounding
    int b10exp = 0;
    int64_t b10mantissa = frexp10(d, &b10exp);
    int mantLen = round(log10(abs(b10mantissa))) + 1;
    bool sciMode = abs(mantLen + b10exp) > 15 || decimals < 0;
    int absDecimals = decimals < 0 ? -decimals : decimals;

    double q = pow(10, sciMode ? -(mantLen - absDecimals - 1) : (b10exp + absDecimals));
    double d2 = ((double)b10mantissa * q);
    d = round(d2) * pow(10, sciMode ? (b10exp + mantLen - absDecimals - 1) : -absDecimals);

    // final processing
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

    bool someDecimals = false;

    if (sciMode)
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
        if (l + b10exp < 0)
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
            int dst = abs(l + b10exp);
            while (i < l)
            {
                if (i >= dst + decimals)
                    break;

                if (i == dst)
                {
                    ss << '.';
                    someDecimals = true;
                }

                ss << strtmp[i];

                if (i >= dst)
                {
                    ++decCnt;
                    if (decCnt >= decimals)
                        break;
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
            int u = j - (sciMode ? 1 : 0);
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
                if (j <= u)
                    j = u + 1;

                for (int k = j; k < sl; ++k)
                {
                    sst << s[k];
                }

                return sst.str();
            }
        }
    }

    return s;
}
