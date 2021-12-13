#ifndef CAMINO_HPP
#define CAMINO_HPP

#include "casilleroTransitable.hpp"

class Camino : public CasilleroTransitable{

    public: 
        Camino();
        void caracteristicas();
        void desrecorrer();
};

#endif //CAMINO_HPP

