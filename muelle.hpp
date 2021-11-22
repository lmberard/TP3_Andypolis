#ifndef MUELLE_HPP
#define MUELLE_HPP

#include "colors.hpp"
#include "casilleroTransitable.hpp"

class Muelle : public CasilleroTransitable{

    public: 
        Muelle(){
            color = BGND_BROWN_94; 
            casillero_nombre = "muelle";
        }
};

#endif //TERRENO_HPP