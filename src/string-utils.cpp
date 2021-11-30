#include <sstream>
#include <math.h>

#include "string-utils.h"
#include "number-utils.h"

using namespace std;

#ifdef ARDUINO_ARCH_STM32

string tostr(double d, int decimals, bool trim_leading_zeroes)
{
    stringstream ss;
    if (d == 0)
    {
        // printf("d==0\n");
        if (decimals < 0)
            return string("0e0");

        ss << '0';

        if (decimals > 0 && !trim_leading_zeroes)
        {
            ss << '.';
            while (decimals--)
                ss << '0';
        }

        return ss.str();
    }

    // provide rounding
    int b10exp = 0;
    int64_t b10mantissa = frexp10(d, &b10exp);
    auto l10 = log10(abs(b10mantissa));
    int mantLen = round(l10) + 1;
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

    // printf("b10mantissa=%ld\n", b10mantissa);
    // printf("log10(%ld)=%f\n", abs(b10mantissa), log10(abs(b10mantissa)));
    // printf("absDecimals=%d\n", absDecimals);
    // printf("b10exp=%d\n", b10exp);
    // printf("mantLen=%d\n", mantLen);

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
            int v = 0;
            while (sciMode && j >= 0)
            {
                if (s[j] == 'e')
                {
                    v = j;
                    --j;
                    break;
                }
                --j;
            }

            //         jv
            // 1234.5600e9
            //
            while (j >= 0 && s[j] == '0')
                --j;

            int w = j;
            //       w  v
            // 1234.5600e9
            //
            stringstream sst;

            for (int k = 0; k <= w; ++k) // 1234.56
            {
                if (s[k] == '.' && w == k) // 400.00 => 400. -> 400
                    break;                
                sst << s[k];
            }

            if (sciMode)
            {
                for (int k = v; k < sl; ++k) // 1234.56e9
                {
                    sst << s[k];                    
                }
            }

            return sst.str();
        }
    }

    return s;
}

#endif

string ltrim(const string &str)
{
    int i = 0;
    auto pstr = str.c_str();
    while (pstr[i] && isspace(pstr[i]))
        ++i;
    return str.substr(i);
}

string rtrim(const string &str)
{
    int l = str.length();
    int i = l - 1;
    auto pstr = str.c_str();
    while (i > 0 && isspace(pstr[i]))
        --i;
    return str.substr(0, i + 1);
}

string trim(const string &str)
{
    int i = 0;
    int l = str.length();
    auto pstr = str.c_str();
    while (pstr[i] && isspace(pstr[i]))
        ++i;
    int ir = l - 1;
    while (ir > i && ir > 0 && isspace(pstr[ir]))
        --ir;
    return str.substr(i, ir - i + 1);
}

int computeChecksum(const String &str)
{
    int res = 0;
    int l = str.length();
    for (int i = 0; i < l; ++i)
    {
        if (i == 0)
            res = str[i];
        else
            res = res ^ str[i];
    }
    return res;
}

String appendChecksum(const String &str)
{
    String res = str;

    int l = str.length();
    if (l == 0)
        return "00";

    char crcStr[2 + 1];
    sprintf(crcStr, "%02X", computeChecksum(str));

    res += crcStr;

    return res;
}

String removeChecksum(const String &str)
{
    int l = str.length();
    if (l > 2)
        return str.substring(0, l - 2);
    return "";
}

bool verifyChecksum(const String &str)
{
    int l = str.length();
    if (l <= 2)
        return str == "00";

    int chksum = computeChecksum(str.substring(0, l - 2));

    char crcStr[2 + 1];
    sprintf(crcStr, "%02X", chksum);

    for (int j = l - 2; j < l; ++j)
    {
        if (str[j] != crcStr[j - (l - 2)])
            return false;
    }
    return true;
}