//
// Created by yop on 30/03/17.
//
#define __DEBUG__
#define __ARDUINO__

#include "CServo.h"
#include "CUltrasound.h"
#include "CSerial.h"

volatile int keepRunning;
unsigned int CInterface::nbOfInstances = 0;


/** Signal handler used to stop this application cleanly */
void handler(int arg) {
    (arg);
    keepRunning = 0;
}

unsigned int ussensorpinlist[4] = {A1, A2, A3, A4}; 
CServo servo(3);
CUltrasound sensor(ussensorpinlist);
CSerial pc(9600);

void setup() {}

void loop() {
    int i = 0;
    keepRunning = 1;
    while(1) {
        servo.setAngle(i++);
        sensor.getValue();
        pc.send(servo.getAngle(), 15, sensor.getValue());
        if(i > 180) i = 0;
    }
}
