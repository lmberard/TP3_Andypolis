#include <string>
#include <iostream>

#include "extremista.hpp"

using namespace std;

Extremista::Extremista() : Objetivo()
{
    progreso = 0;
}

Extremista::~Extremista()
{
}

void Extremista::chequear_estado(Inventario &inventario, int puntos_energia, Lista<Ubicaciones> &edificios, Constructor &bob, bool fin_turno)
{
    progreso = inventario.obtener_bombas_compradas();
    if (progreso >= CANTIDAD_BOMBAS_COMPRADAS_OBJETIVO)
        objetivo_cumplido = true;
}

void Extremista::mostrar_objetivo()
{
    msjeTitulo("* Extremista: haber comprado 500 bombas en una partida.");
    msjeInstruccion("\tHasta el momento compro " + to_string(progreso) + " bombas");
    if (objetivo_cumplido)
        msjeOK("\tEl objetivo esta cumplido\n");
    else
        msjeError("\tEl objetivo no esta cumplido\n");
}

bool Extremista::es_principal()
{
    return false;
}
