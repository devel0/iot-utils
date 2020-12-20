#ifndef _SEARCHATHING_NUMBER_UTILS_H
#define _SEARCHATHING_NUMBER_UTILS_H

#include <mbed.h>

/*
compute mantissa and exp base10
@param d value to compute mantissa,exp from
@param ptr to exp where store exp info
@return mantissa base10 of given number so that d=res*10^expb10
*/
int64_t frexp10(double d, int *expb10);

#endif
