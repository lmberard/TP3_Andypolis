#ifndef ENERGETICO_HPP
#define ENERGETICO_HPP
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

static const int CANTIDAD_MAX_ENERGIA = 100;

class Energetico : public Objetivo
{
private:

    int progreso;

public:
    Energetico();
    ~Energetico();

    void chequear_estado(Inventario & inventario, int puntos_energia, Lista<Ubicaciones> & edificios, Constructor & bob, bool fin_turno);
    void mostrar_objetivo();
    bool es_principal();
};



#endif 
