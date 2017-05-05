#ifndef CACCELERO_H
#define CACCELERO_H
#include "CSensor.h"

/* Classe CAccelero : 
 * Hérite de CSensor<float **> : c'est un capteur qui travail avec un tableau 3 * 3 
 */
class CAccelero : public CSensor<float **> {
  public: 
    CAccelero(); 
    CAccelero(unsigned int pin_number); 
};

#endif