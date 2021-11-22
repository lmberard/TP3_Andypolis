#ifndef CAMINO_HPP
#define CAMINO_HPP

#include "colors.hpp"
#include "casilleroTransitable.hpp"

class Camino : public CasilleroTransitable{

    public: 
        Camino(){
            color = BGND_LIGHT_GRAY_247 ; 
            casillero_nombre = "camino";
        }
        ~Camino(){};
};

#endif //CAMINO_HPP

