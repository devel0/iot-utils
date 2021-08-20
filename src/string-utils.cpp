#include <sstream>
#include <math.h>
#include <CRC32.h>

#include "string-utils.h"
#include "number-utils.h"

using namespace std;

string tostr(double d, int decimals, bool trim_leading_zeroes)
{
    stringstream ss;
    if (d == 0)
    {
        printf("d==0\n");
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

    printf("b10mantissa=%ld\n", b10mantissa);
    printf("log10(%ld)=%f\n", abs(b10mantissa), log10(abs(b10mantissa)));
    printf("absDecimals=%d\n", absDecimals);
    printf("b10exp=%d\n", b10exp);
    printf("mantLen=%d\n", mantLen);

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
                    sst << s[k];
            }

            return sst.str();
        }
    }

    return s;
}

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

string appendCRC(const string &str)
{
    string res = str;

    int l = str.length();
    if (l == 0)
        return "00000000";

    CRC32 crc;
    for (int i = 0; i < l; ++i)
    {
        crc.update(str[i]);
    }
    uint32_t chksum = crc.finalize();

    char crcStr[8 + 1];
    sprintf(crcStr, "%08X", chksum);

    res += crcStr;

    return res;
}

string removeCRC(const string &str)
{
    int l = str.length();
    if (l > 8)
        return str.substr(0, l - 8);
    return "";
}

bool verifyCRC(const string &str)
{
    int l = str.length();
    if (l <= 8)
        return str == "00000000";

    CRC32 crc;
    for (int i = 0; i < l - 8; ++i)
    {
        crc.update(str[i]);
    }
    uint32_t chksum = crc.finalize();

    char crcStr[8 + 1];
    sprintf(crcStr, "%08X", chksum);

    for (int j = l - 8; j < l; ++j)
    {
        if (str[j] != crcStr[j - (l - 8)])
            return false;
    }
    return true;
}