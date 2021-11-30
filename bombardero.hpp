#ifndef BOMBARDERO_HPP
#define BOMBARDERO_HPP

#include "objetivo.hpp"

static const int CANTIDAD_BOMBAS_USADAS_OBJETIVO = 5;

class Bombardero : public Objetivo
{
private:


public:
    Bombardero(string objetivo, string tipo);
    ~Bombardero();

    bool chequear_estado(Inventario & inventario);
};



#endif 