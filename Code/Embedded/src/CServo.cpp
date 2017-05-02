#include "CServo.h"

CServo::CServo() : CInterface(DEFAULT_SERVO_PIN), angle(0) {
    init();
    enable();
    setAngle(angle);
}

CServo::CServo(const int pin_number) : CInterface(pin_number), angle(0) {
    init();
    enable();
    setAngle(angle);
}

void CServo::enable() {}

void CServo::disable() { mraa_pwm_enable(pwmPin, 0); }


void CServo::setAngle(const float target_angle) {
    if (target_angle != angle) {
        PrintDbg("Servo[" << pin << "]: Angle setted to " << target_angle);
        angle = target_angle;
        mraa_pwm_write(pwmPin, ((float(angle) / 180.0f) * (MAX_ALPHA - MIN_ALPHA) + MIN_ALPHA));
        usleep(5000);
    }
}

void CServo::init() {
    PrintDbg("Init servo on pin " << pin);
    pwmPin = mraa_pwm_init(pin);
    mraa_pwm_period_us(pwmPin, PERIOD_US);
    mraa_pwm_enable(pwmPin, 1);
}

float CServo::getAngle() const {
    return angle;
}










