//
// Created by yop on 30/03/17.
//

#ifndef EMBEDDED_CSENSOR_H
#define EMBEDDED_CSENSOR_H

#include "CInterface.h"

/*  Template de classe CSensor
 *  Herite de CInterface. Classe representant un capteur.
 *  Differents capteurs retournent des valeurs de differents types
 */
template<typename ValueType>
class CSensor : public CInterface {
    protected:
    ValueType value;

    public:
    CSensor<ValueType>() : CInterface() {}

    CSensor<ValueType>(const unsigned int pinNumber) : CInterface(pinNumber) {}

    virtual ValueType getValue() const { return value; };
};

class CAccelero : public CSensor<float **> {
};

#endif //EMBEDDED_CSENSOR_H
