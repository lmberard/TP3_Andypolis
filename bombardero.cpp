#include <string>
#include <iostream>

#include "bombardero.hpp"

using namespace std;

Bombardero::Bombardero() : Objetivo()
{
    progreso = 0;
}

Bombardero::~Bombardero()
{
}

void Bombardero::chequear_estado(Inventario &inventario, int puntos_energia, Lista<Ubicaciones> &edificios, Constructor &bob, bool fin_turno)
{
    progreso = inventario.obtener_bombas_usadas();
    if (progreso >= CANTIDAD_BOMBAS_USADAS_OBJETIVO)
        objetivo_cumplido = true;
}

void Bombardero::mostrar_objetivo()
{
    msjeTitulo("* Bombardero: haber usado 5 bombas.");
    msjeInstruccion("Usaste " + to_string(progreso) + " bombas.");
    if (objetivo_cumplido)
        msjeOK("\tEl objetivo esta cumplido.\n");
    else
        msjeError("\tEl objetivo no esta cumplido.\n");
}

bool Bombardero::es_principal()
{
    return false;
}
