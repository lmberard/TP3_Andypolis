#ifndef _MINE_H_INCLUDED_
#define _MINE_H_INCLUDED_

#include "building.h"

using namespace std;

class Mine: public Building{
private:


public:

    // PRE: -
    // POST: Este metodo llama al constructor de la clase abstracta building y setea el identificador correspondiente a la clase hija.
    Mine();

    // PRE: - 
    // POST: Este metodo destruye clase Mine.
    ~Mine();
};

#endif