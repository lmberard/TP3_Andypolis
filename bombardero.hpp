#ifndef BOMBARDERO_HPP
#define BOMBARDERO_HPP
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

static const int CANTIDAD_BOMBAS_USADAS_OBJETIVO = 5;

class Bombardero : public Objetivo
{
private:


public:
    Bombardero();
    ~Bombardero();

    bool chequear_estado(Inventario & inventario, int puntos_energia, Lista<Ubicaciones> & edificios, Constructor & bob, bool fin_turno);
    string obtener_objetivo();
    bool es_principal();
};



#endif 
