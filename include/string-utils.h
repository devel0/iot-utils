#ifndef _SEARCHATHING_STRING_UTILS_H
#define _SEARCHATHING_STRING_UTILS_H

#ifdef ARDUINO
#include <Arduino.h>
#include <string>
#endif

#ifdef __MBED__
#include <mbed.h>
#endif

using namespace std;

#ifndef ESP8266

/**
 * @brief convert given double to string
 * 
 * @param d value to convert to string
 * @param decimals number of decimals to show rounding on last decimal; if negative or digits+b10exp exceed 15 length then scimode is selected automatically
 * @param trim_leading_zeroes trim_leading_zeroes if true autoremove decimals ending zeroes
 * @return std::string representation of given value
 */
string tostr(double d, int decimals = -16, bool trim_leading_zeroes = true);

#endif

/**
 * @brief trim beginning spaces
 */
string ltrim(const string &str);

/**
 * @brief trim ending spaces
 */
string rtrim(const string &str);

/**
 * @brief trim begin and ending spaces
 */
string trim(const string &str);

/**
 * @brief create a new string with crc32 appended
 */
string appendCRC(const string &str);

/**
 * @brief remove CRC from string ( latest 8 chars )
 */
string removeCRC(const string &str);

/**
 * @brief returns true if string of form "str...AABBCCDD" contains valid crc32
 */
bool verifyCRC(const string& str);

#endif
