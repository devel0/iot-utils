#ifndef _STRING_UTILS_H
#define _STRING_UTILS_H

#include <mbed.h>

/*
convert given double to string
@param d value to convert to string
@param decimals any value negative means scientific notation forced;
if positive value given fixed decimals representation rounding to last decimal
(if great than 15 turn scientific mode automatically)
@return string representation of given value
*/
std::string tostr(double d, int decimals = -17);

#endif
