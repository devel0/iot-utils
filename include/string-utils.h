#ifndef _SEARCHATHING_STRING_UTILS_H
#define _SEARCHATHING_STRING_UTILS_H

#include <Arduino.h>
#include <string>

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
 * @brief compute xor checksum of given string
 */
int computeChecksum(const String &str);

/**
 * @brief create a new string with xor checksum appended
 */
String appendChecksum(const String &str);

/**
 * @brief remove xor checksum from string ( latest 2 chars )
 */
String removeChecksum(const String &str);

/**
 * @brief returns true if string of form "str...XX" contains valid xor checksum
 */
bool verifyChecksum(const String& str);

#endif
