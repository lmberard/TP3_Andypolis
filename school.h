#ifndef _SCHOOL_H_INCLUDED_
#define _SCHOOL_H_INCLUDED_

#include "building.h"

using namespace std;

class School: public Building{
private:


public:

    // PRE: -
    // POST: Este metodo llama al constructor de la clase abstracta building y setea el identificador correspondiente a la clase hija.
    School();

    // PRE: - 
    // POST: Este metodo destruye clase School.
    ~School();
};


#endif
