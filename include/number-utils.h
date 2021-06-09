#ifndef _SEARCHATHING_NUMBER_UTILS_H
#define _SEARCHATHING_NUMBER_UTILS_H

#ifdef ARDUINO
#include <Arduino.h>
#endif

#ifdef __MBED__
#include <mbed.h>
#endif

/**
 * @brief compute mantissa and exp base10
 * 
 * @param d value to compute mantissa,exp from
 * @param expb10 ptr to exp where store exp info
 * @return int64_t mantissa base10 of given number so that d=res*10^expb10
 */
int64_t frexp10(double d, int *expb10);

/**
 * @brief true if ( |x-y| <= tol )
 */
bool EqualsTol(double tol, double x, double y);

/**
 * @brief true if (x > y) AND NOT ( |x-y| <= tol )
 */
bool GreatThanTol(double tol, double x, double y);

/**
 * @brief true if (x > y) AND ( |x-y| <= tol )
 */
bool GreatThanOrEqualsTol(double tol, double x, double y);

/**
 * @brief true if (x < y) AND NOT ( |x-y| <= tol )
 */
bool LessThanTol(double tol, double x, double y);

/**
 * @brief true if (x < y) AND ( |x-y| <= tol )
 */
bool LessThanOrEqualsTol(double tol, double x, double y);

/**
 * @brief return 0 if equalstol, -1 if x<~y or 1 if x>~y
 */
int CompareTol(double tol, double x, double y);

/**
 * @brief convert given angle(deg) to rad 
 */
double ToRad(double angleDeg);

/**
 * @brief convert given angle(rad) to deg
 */
double ToDeg(double angleRad);

/**
 * @brief Round the given value using the multiple basis
 */
double MRound(double value, double multiple);

/**
 * @brief returns 1.0 if n>=0 ; -1 otherwise
 */
double Sign(int n);

/**
 * @brief returns 1.0 if n>=0 ; -1 otherwise
 */
double Sign(double n);

/**
 * @brief Magnitude of given number. (eg. 190 -> 1.9e2 -> 2)
 *  (eg. 0.0034 -> 3.4e-3 -> -3)
 */
int Magnitude(double value);

#endif
