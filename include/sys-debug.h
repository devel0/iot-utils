#ifndef _SYS_DEBUG_H
#define _SYS_DEBUG_H

#ifdef ARDUINO

#include <Arduino.h>

/**
 * @brief set printer to receive debug and internal error messages
 * 
 * @param printer Serial, Serial2, ...
 */
void setSystemPrinter(Stream &printer);

/**
 * @brief set fn callback before infinite loop on internal error
 * 
 * @param cb custom callback
 */
void setInternalErrorCallback(void (*cb)());

/**
 * @brief generate an internal error issueing a print ( if setSystemPrinter used ), calling custom callback ( if setInternalErrorCallback used ) then going for infinite loop
 * 
 * @param fmt printf like msg to print ( newline automatically appended )
 * @param ... 
 */
void error(const char *fmt, ...);

/**
 * @brief same as error(fmt, ...) but without argument printing "internal error" as message
 */
void error();

/**
 * @brief generate debug message issueing a print ( if setSystemPrinter used ) unless -DDISABLE_DEBUG defined
 * 
 * @param fmt 
 * @param ... 
 */
#ifdef DISABLE_DEBUG
#define debug(fmt, ...) {}
#else
void debug(const char *fmt, ...);
#endif

#endif

#endif
