#ifndef TERRENO_HPP
#define TERRENO_HPP

#include "colors.hpp"
#include "casilleroConstruible.hpp"

class Terreno : public CasilleroConstruible{

    public: 
        Terreno(){
            color = BGND_GREEN_2; 
            casillero_nombre = "terreno";
        }
};

#endif //TERRENO_HPP