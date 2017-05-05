#include "CUltrasound.h"

CUltrasound::CUltrasound(unsigned int pins_number[4]) : CSensor<float>(pins_number[1]) {
    pin_list = new unsigned int[4](pins_number);
    PrintDbgValue("Init ultrasound sensor on main pin ", pins_number[1]);
    pinMode(pins_number[0], OUTPUT);
    pinMode(pins_number[1], OUTPUT);
    pinMode(pins_number[2], INPUT);
    pinMode(pins_number[3], OUTPUT);
    digitalWrite(pins_number[0], LOW);
    digitalWrite(pins_number[1], LOW);
    digitalWrite(pins_number[3], LOW);
}

void CUltrasound::trigger() const {
    // /!\ est-ce la bonne pin ?
    digitalWrite(_pin, HIGH);
    delay(10);
    digitalWrite(_pin, LOW);
}

float CUltrasound::getValue() const {
    PrintDbg("Reading value on sensor");
    if (enabled) {
        trigger();
        return pulseIn(pin_list[2], HIGH) / 58;
    } else return -1;
}
