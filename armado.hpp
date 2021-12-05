#ifndef ARMADO_HPP
#define ARMADO_HPP
#include <iostream>
#include <string>

/*
#include "colors.hpp"
#include "lista.hpp"
#include "ciudad.hpp"
#include "ubicaciones.hpp"
#include "constructor.hpp"
#include "inventario.hpp"
#include "recurso.hpp"
#include "terreno.hpp"*/
#include "objetivo.hpp"

static const int CANTIDAD_BOMBAS_INVENTARIO_OBJETIVO = 10;

class Armado : public Objetivo
{
private:


public:
    Armado();
    ~Armado();

    bool chequear_estado(Inventario & inventario);
};



#endif 
