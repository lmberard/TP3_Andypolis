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

    int progreso;


public:
    ComprarAndypolis();
    ~ComprarAndypolis();

    void chequear_estado(Inventario & inventario, int puntos_energia, Lista<Ubicaciones> & edificios, Constructor & bob, bool fin_turno);
    void mostrar_objetivo();
    bool es_principal();
};



#endif 
