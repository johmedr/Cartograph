//
// Created by yop on 30/03/17.
//
#define DEBUG

#include "CServo.h"
#include "CSensor.h"


int main(int argc, char *argv[]) {
    CServo bas(5);
    bas.setAngle(50.0);
    bas.setAngle(179.0);
    bas.setAngle(1.0);
}