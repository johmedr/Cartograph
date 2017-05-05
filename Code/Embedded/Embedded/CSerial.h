//
// Created by yop on 05/05/17.
//

#ifndef EMBEDDED_CSERIAL_H
#define EMBEDDED_CSERIAL_H

#include "Arduino.h"

class CSerial {
protected:
    unsigned int baudrate;

public:
    CSerial(unsigned int baudrate);

    void send(unsigned int angle, unsigned int spread, unsigned int distance) const;
};

#endif //EMBEDDED_CSERIAL_H
