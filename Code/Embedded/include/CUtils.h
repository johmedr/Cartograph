//
// Created by yop on 30/03/17.
//

#ifndef EMBEDDED_UTILS_H
#define EMBEDDED_UTILS_H

#include "Arduino.h"

#define InitPlatform() InitArduino();

#ifdef __DEBUG__

/* Fonction utilisée pour debugger grace a la communication serie */
void printDebugArduino(char * text, const char * fileName, const int lineNumber);

/* Fonction utilisée pour poser des assertions (celles non-validées quittent le programme) */
void assertArduino(int expression, const char * fileName, const int lineNumber);

#define Assert(expr) assertArduino(expr, __FILE__, __LINE);
#define PrintDbg(text) printDebugArduino(text, __FILE__, __LINE__);

#else

#define Assert(expr)
#define PrintDbg(text)

#endif



#endif //EMBEDDED_UTILS_