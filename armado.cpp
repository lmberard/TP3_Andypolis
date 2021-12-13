#include <string>
#include <iostream>

#include "armado.hpp"

using namespace std;

Armado::Armado() : Objetivo()
{
    progreso = 0;
}

Armado::~Armado()
{
}

void Armado::chequear_estado(Inventario &inventario, int puntos_energia, Lista<Ubicaciones> &edificios, Constructor &bob, bool fin_turno)
{
    progreso = inventario.obtener_material("bomba")->obtener_cantidad();
    if (progreso >= CANTIDAD_BOMBAS_INVENTARIO_OBJETIVO)
        objetivo_cumplido = true;
    else
        objetivo_cumplido = false;
}

void Armado::mostrar_objetivo()
{
    msjeTitulo("* Armado: tener 10 bombas en el inventario.");
    msjeInstruccion("\tHasta el momento posee " + to_string(progreso) + " bombas.");
    if (objetivo_cumplido)
        msjeOK("\tEl objetivo esta cumplido.\n");
    else
        msjeError("\tEl objetivo no esta cumplido.\n");
}

bool Armado::es_principal()
{
    return false;
}
