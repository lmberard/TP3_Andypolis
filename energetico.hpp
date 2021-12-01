#ifndef ENERGETICO_HPP
#define ENERGETICO_HPP

#include "objetivo.hpp"

static const int CANTIDAD_MAX_ENERGIA = 100;

class Energetico : public Objetivo
{
private:


public:
    Energetico(string objetivo, string tipo);
    ~Energetico();

    bool chequear_estado(int energia);
};



#endif