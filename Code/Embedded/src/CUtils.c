#include "CUtils.h"

/* Fonction utilisée pour debugger grace a la communication serie */
void printDebugArduino(const char *fileName, const int lineNumber, char *text) {
    Serial.print("[DD] In file ");
    Serial.print(fileName);
    Serial.print(" line ");
    Serial.print(lineNumber);
    Serial.print(" : ");
    Serial.println(text);
}

/* Fonction utilisée pour poser des assertions (celles non-validées quittent le programme) */
void assertArduino(int expression, const char *fileName, const int lineNumber) {
    if (!expression) {
        Serial.print("[EE] In file ");
        Serial.print(fileName);
        Serial.print(" line ");
        Serial.print(lineNumber);
        Serial.println(" : Assertion failed.");
        delay(75);
        exit(1);
    }
}

