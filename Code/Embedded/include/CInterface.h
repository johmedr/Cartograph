//
// Created by yop on 30/03/17.
//

#ifndef EMBEDDED_INTERFACE_H
#define EMBEDDED_INTERFACE_H

#include "CUtils.h"

/** Classe abstraite CInterface
 *  Classe mere de tous les capteurs et actionneurs permettant
 *  d'interfacer avec l'environnement.
 */
class CInterface {
    protected:
        unsigned int pin;
    public:
        CInterface(const unsigned int pin_number) : pin(pin_number) {};

        void attach(const unsigned int pin_number) { pin = pin_number; }

        unsigned int getPinNumber() const { return pin; }

        virtual void enable() = 0;

        virtual void disable() = 0;
};

#endif //EMBEDDED_INTERFACE_H
