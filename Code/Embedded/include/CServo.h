//
// Created by yop on 30/03/17.
//

#ifndef EMBEDDED_SERVO_H
#define EMBEDDED_SERVO_H

#include "CInterface.h"
#include <mraa.h>
#include <signal.h>

#define DEFAULT_SERVO_PIN 2
#define MIN_ALPHA 10
#define MAX_ALPHA 60
#define PERIOD_US 20000

/* Macro Init
 * Permet d'initialiser un servo
 * Initialise la pin d'attache pour l'utiliser en pwm
 */
#define Init pwmPin = mraa_pwm_init(pin);\
             mraa_pwm_period_us(pwmPin, PERIOD_US);\
             mraa_pwm_enable(pwmPin, 1);

/* Macro SetAngle()
 * Calcule la taille de pulse a envoyer pour deplacer le servo a l'angle souhaite
 * Envoie ce pulse
 */
#define SetAngle(x) PrintDbg("Servo[" << pin << "]: Angle setted to " << x/180.0f);\
                    mraa_pwm_write(pwmPin, (float(x)/180.0f * (MAX_ALPHA - MIN_ALPHA) + MIN_ALPHA));\
                    usleep(5000);




class CServo : public CInterface {
    protected:
        mraa_pwm_context pwmPin;
        float angle;
    public:
        CServo() : CInterface(DEFAULT_SERVO_PIN), angle(0) {
            PrintDbg("Init servo on pin " << pin);
            Init;
            SetAngle(angle);
        };

        CServo(const int pin_number) : CInterface(pin_number), angle(0) {
            Init;
            SetAngle(angle);
        };

        float getAngle() const;

        void setAngle(const float target_angle);

        void enable() { mraa_pwm_enable(pwmPin, 1); };

        void disable() { mraa_pwm_enable(pwmPin, 0); }

};

#endif //EMBEDDED_SERVO_H