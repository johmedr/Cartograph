#include "CServo.h"
#include <Arduino.h>

CServo::CServo() : CInterface(DEFAULT_SERVO_PIN), Servo(), angle(0) {
    PrintDbg("Init servo on default pin")
    init();
    enable();
    setAngle(angle);
}

CServo::CServo(const int pin_number) : CInterface(pin_number), Servo(), angle(0) {
    PrintDbgValue("Init servo on pin ", pin_number);
    init();
    enable();
    setAngle(angle);
}

void CServo::setAngle(const float target_angle) {
     if(enabled) {
         Assert(target_angle <= 180 && target_angle >= 0); 
         if (target_angle != angle) {
            PrintDbgValue(String("Servo[") + _pin + "]", target_angle);
            angle = target_angle;
            write(angle); 
        }
     }
}

void CServo::init() {
    PrintDbgValue("Init servo on pin ", _pin);
    attach(_pin); 
    enabled = 1; 
}

float CServo::getAngle() const {
    return angle;
}

void CServo::enable() { 
  enabled = 1; 
}

void CServo::disable() { 
  enabled = 0; 
}

void CServo::attach(const unsigned int pin_number) { 
  _pin = pin_number; 
  Servo::attach(pin_number); 
}












