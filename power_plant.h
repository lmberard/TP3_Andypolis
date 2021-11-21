#ifndef _POWER_PLANT_H_INCLUDED_
#define _POWER_PLANT_H_INCLUDED_

#include "building.h"

using namespace std;

class PowerPlant: public Building{
private:


public:

    // PRE: -
    // POST: Este metodo llama al constructor de la clase abstracta building y setea el identificador correspondiente a la clase hija.
    PowerPlant();

    // PRE: - 
    // POST: Este metodo destruye clase PowerPlant.
    ~PowerPlant();
};

#endif