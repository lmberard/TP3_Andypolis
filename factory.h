#ifndef _FACTORY_H_INCLUDED_
#define _FACTORY_H_INCLUDED_

#include "building.h"

using namespace std;

class Factory: public Building{
private:

public:
    // PRE: -
    // POST: Este metodo llama al constructor de la clase abstracta building y setea el identificador correspondiente a la clase hija.
    Factory();

    // PRE: - 
    // POST: Este metodo destruye isntancia de clase Factory.
    ~Factory();
};

#endif