#ifndef EXTREMISTA_HPP
#define EXTREMISTA_HPP

#include "objetivo.hpp"

static const int CANTIDAD_BOMBAS_COMPRADAS_OBJETIVO = 500;

class Extremista : public Objetivo
{
private:


public:
    Extremista(string objetivo, string tipo);
    ~Extremista();

    bool chequear_estado(Inventario & inventario);
};



#endif 