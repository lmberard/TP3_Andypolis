#ifndef LAGO_HPP
#define LAGO_HPP

#include "colors.hpp"
#include "casilleroInaccesible.hpp"

class Lago : public CasilleroInaccesible{
  

    public: 
        Lago(){
            color = BGND_BLUE_25; 
            casillero_nombre = "lago";
        }
        ~Lago(){};
};

#endif //LAGO_HPP
