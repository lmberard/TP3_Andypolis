#ifndef CAMINO_HPP
#define CAMINO_HPP

#include "colors.hpp"
#include "casilleroTransitable.hpp"

class Camino : public CasilleroTransitable{

    public: 
        Camino();
        void caracteristicas();
};

#endif //CAMINO_HPP

