#ifndef MUELLE_HPP
#define MUELLE_HPP

#include "casilleroTransitable.hpp"

class Muelle : public CasilleroTransitable
{

public:
    Muelle();
    void caracteristicas();
    void desrecorrer();
};

#endif // MUELLE_HPP
