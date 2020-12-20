#ifndef _SEARCHATHING_STRING_UTILS_H
#define _SEARCHATHING_STRING_UTILS_H

#include <mbed.h>

/*
convert given double to string
@param d value to convert to string
@param decimals number of decimals to show rounding on last decimal; if negative or digits+b10exp exceed 15 length then scimode is selected automatically
@param trim_leading_zeroes if true autoremove decimals ending zeroes
@return string representation of given value
*/
std::string tostr(double d, int decimals = -17, bool trim_leading_zeroes = true);

#endif
