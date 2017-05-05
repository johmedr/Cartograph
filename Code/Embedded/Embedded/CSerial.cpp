#include "CSerial.h"

CSerial::CSerial(unsigned int baudrate) {
    Serial.begin(baudrate);
}

void CSerial::send(unsigned int angle, unsigned int spread, unsigned int distance) const {
    Serial.print('a:');
    Serial.print(angle);
    Serial.print(',s:');
    Serial.print(spread);
    Serial.print(',d:');
    Serial.print(distance);
    Serial.println();
}