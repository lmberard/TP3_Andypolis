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
    msjeInstruccion("Bombardero: haber usado 5 bombas.");
    cout << TXT_LIGHT_BLUE_6 << '\t' << "Usaste " << progreso << " bombas." << END_COLOR << endl;
    if (objetivo_cumplido)
        msjeOK("\tEl objetivo esta cumplido.");
    else
        msjeError("\tEl objetivo no esta cumplido.");
}

bool Bombardero::es_principal()
{
    return false;
}
