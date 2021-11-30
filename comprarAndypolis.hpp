#ifndef COMPRAR_ANDYPOLIS_HPP
#define COMPRAR_ANDYPOLIS_HPP

#include "objetivo.hpp"

static const int CANTIDAD_ANDYCOINS_OBJETIVO = 100000;

class ComprarAndypolis : public Objetivo
{
private:


public:
    ComprarAndypolis(string objetivo, string tipo);
    ~ComprarAndypolis();

    bool chequear_estado(Inventario & inventario);
};



#endif 