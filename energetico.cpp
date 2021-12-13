#include <string>
#include <iostream>

#include "energetico.hpp"

using namespace std;

Energetico::Energetico() : Objetivo()
{
    progreso = 0;
}

Energetico::~Energetico()
{
}

void Energetico::chequear_estado(Inventario &inventario, int puntos_energia, Lista<Ubicaciones> &edificios, Constructor &bob, bool fin_turno)
{
    progreso = puntos_energia;
    if (fin_turno)
        if (puntos_energia == CANTIDAD_MAX_ENERGIA)
            objetivo_cumplido = true;
}

void Energetico::mostrar_objetivo()
{
    msjeTitulo("* Energetico: haber terminado un turno con 100 puntos de energia.");
    msjeInstruccion("\tEn este turno posee " + to_string(progreso) + " puntos de energia");
    if (objetivo_cumplido)
        msjeOK("\tEl objetivo esta cumplido\n");
    else
        msjeError("\tEl objetivo no esta cumplido\n");
}

bool Energetico::es_principal()
{
    return false;
}
