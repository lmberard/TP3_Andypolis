#ifndef ARMADO_HPP
#define ARMADO_HPP

#include "objetivo.hpp"

static const int CANTIDAD_BOMBAS_INVENTARIO_OBJETIVO = 10;

class Armado : public Objetivo
{
private:


public:
    Armado(string objetivo, string tipo);
    ~Armado();

    bool chequear_estado(Inventario & inventario);
};



#endif 