#ifndef _SAWMILL_H_INCLUDED_
#define _SAWMILL_H_INCLUDED_

#include "building.h"

using namespace std;

class Sawmill: public Building{
private:


public:

    // PRE: -
    // POST: Este metodo llama al constructor de la clase abstracta building y setea el identificador correspondiente a la clase hija.
    Sawmill();

    // PRE: - 
    // POST: Este metodo destruye clase Sawmill.
    ~Sawmill();
};

#endif