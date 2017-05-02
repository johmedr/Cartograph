//
// Created by yop on 30/03/17.
//
#define __DEBUG__

#include "CServo.h"
#include "CSensor.h"

volatile int keepRunning;
unsigned int CInterface::nbOfInstances = 0;

/** Signal handler used to stop this application cleanly */
void handler(int arg) {
    (arg);
    keepRunning = 0;
}


int main(int argc, char *argv[]) {
    keepRunning = 1;


    /** Associate ctrl+c with our handler that clears the 'keepRunning'
    * flag that allows us to stop the PWM when exiting*/
    signal(SIGINT, handler);
    mraa_init();
    CServo bas(5);
    while (keepRunning) {
    bas.setAngle(50.0);
    bas.setAngle(179.0);
    bas.setAngle(1.0);
    }
    bas.disable();
    return 0;
}