#include <string>
#include <iostream>

#include "cansado.hpp"

using namespace std;

Cansado::Cansado() : Objetivo()
{
    progreso = 0;
}

Cansado::~Cansado()
{
}

void Cansado::chequear_estado(Inventario &inventario, int puntos_energia, Lista<Ubicaciones> &edificios, Constructor &bob, bool fin_turno)
{
    progreso = puntos_energia;
    if (fin_turno)
        if (progreso == CANTIDAD_MIN_ENERGIA)
            objetivo_cumplido = true;
}

void Cansado::mostrar_objetivo()
{
    msjeTitulo("* Cansado: terminar un turno con 0 de energía.");
    msjeInstruccion("En este turno todavia posee " + to_string(progreso) + " puntos de energia.");

    if (objetivo_cumplido)
        msjeOK("\tEl objetivo esta cumplido.\n");
    else
        msjeError("\tEl objetivo no esta cumplido.\n");
}

bool Cansado::es_principal()
{
    return false;
}
