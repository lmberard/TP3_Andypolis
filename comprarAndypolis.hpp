#ifndef COMPRAR_ANDYPOLIS_HPP
#define COMPRAR_ANDYPOLIS_HPP
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