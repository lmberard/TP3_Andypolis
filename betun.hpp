#ifndef BETUN_HPP
#define BETUN_HPP

#include "colors.hpp"
#include "casilleroTransitable.hpp"

class Betun : public CasilleroTransitable{

    public: 
        Betun(){
            color = BGND_DARK_GRAY_59; 
            casillero_nombre = "betun";
        }
        ~Betun(){};
};

#endif //BETUN_HPP