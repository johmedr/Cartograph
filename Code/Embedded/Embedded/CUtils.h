#ifndef EMBEDDED_UTILS_H
#define EMBEDDED_UTILS_H

#define __DEBUG__
#include <Arduino.h>

void initArduino(const unsigned int baudrate); 

#define InitPlatform() initArduino(57600);

#ifdef __DEBUG__

/* Fonction utilisée pour debugger grace a la communication serie */
void printDebugArduino(String text, const char * fileName, const int lineNumber);

/* Fonction utilisée pour poser des assertions (celles non-validées quittent le programme) */
void assertArduino(int expression, const char * fileName, const int lineNumber);

#define Assert(expr) assertArduino(expr, __FILE__, __LINE__);
#define PrintDbg(text) printDebugArduino(text, __FILE__, __LINE__);
#define PrintDbgValue(name, value) printDebugArduino(String(name) + " : " + value, __FILE__, __LINE__);

#else

#define Assert(expr)
#define PrintDbg(text)
#define PrintDbgValue(name, value) 

#endif



#endif //EMBEDDED_UTILS_

