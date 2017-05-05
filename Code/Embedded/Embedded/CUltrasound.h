#ifndef CULTRASOUND_H
#define CULTRASOUND_H

#include "CSensor.h"

class CUltrasound : public CSensor<float> {
protected:
    unsigned int * pin_list;

public:
    CUltrasound(unsigned int pins_number[4]);

    void trigger() const;

    float getValue() const override;
}; 

#endif
