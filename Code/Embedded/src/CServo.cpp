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
        mraa_pwm_write(pwmPin, (float(angle) / 180.0f * (MAX_ALPHA - MIN_ALPHA) + MIN_ALPHA));
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

//volatile int keepRunning;
//
///** Signal handler used to stop this application cleanly */
//void handler(int arg) {
//    (arg);
//    keepRunning = 0;
//}
//
//int main(void) {
//    mraa_pwm_context pwmPin;   /* The PWM pin context */
//    float duty;     /* Will hold the duty cycle */
//    float delta;    /* holds the ammount by which the
//duty cycle is to vary */
//
//    /* Step1: Intialize the mraa system */
//    mraa_init();
//
//    /* Step2: Initialize D5 for PWM operation */
//    pwmPin = mraa_pwm_init(PWM_PIN);
//
//    /*
//     * Control the period with "mraa_pwm_period_us"
//     *
//     *      mraa_pwm_period_us(5000)
//     */
//
//    /* Step3: Set the period on the PWM pin */
//    mraa_pwm_period_us(pwmPin, 5000);      // Set the period as 5000 us
//
//    /* Step4: Enable the PWM pulse on the pin */
//    mraa_pwm_enable(pwmPin, 1);
//
//    delta = 0.05;   /* Variation on the duty cycle */
//    duty = 0;       /* 0% duty cycle */
//
//    keepRunning = 1;
//
//    /*
//     * Associate ctrl+c with our handler that clears the 'keepRunning'
//     * flag that allows us to stop the PWM when exiting
//     */
//    signal(SIGINT, handler);
//
//    while (keepRunning) {
//        if (duty >= 1) {
//            duty = 1;          // Intensity of LED at highest
//            delta = -0.05;     // Need to decrease the duty cycle
//        } else if (duty <= 0) {
//            duty = 0;          // Intensity of LED at the lowest
//            delta = +0.05;     // Need to increase the duty cycle
//        }
//        /*
//         *  Control the duty cycle with "write"
//         *  mraa_pwm_write(pwmPin, 0.2)
//         *
//         */
//
//        /* Step5: Use the function 'mraa_pwm_write' to set the duty
//cycle */
//        mraa_pwm_write(pwmPin, duty);
//        /* Wait for some time */
//        usleep(50000);
//
//        duty = duty + delta;
//    }
//
//    /* Step6: Stop the PWM when not required */
//    mraa_pwm_enable(pwmPin, 0);
//
//    return 0;
//}
//










