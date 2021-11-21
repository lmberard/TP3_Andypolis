#ifndef _OBELISK_H_INCLUDED_
#define _OBELISK_H_INCLUDED_

#include "building.h"

using namespace std;

class Obelisk: public Building{
private:


public:

    // PRE: -
    // POST: Este metodo llama al constructor de la clase abstracta building y setea el identificador correspondiente a la clase hija.
    Obelisk();

    // PRE: - 
    // POST: Este metodo destruye clase Obelisk.
    ~Obelisk();
};

#endif