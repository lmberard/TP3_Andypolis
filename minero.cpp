#include <string>
#include <iostream>

#include "minero.hpp"
#include "ubicaciones.hpp"

using namespace std;

Minero::Minero() : Objetivo()
{
    mina_chequeado = false;
    mina_oro_chequeado = false;
}

Minero::~Minero()
{
}

void Minero::chequear_estado(Inventario &inventario, int puntos_energia, Lista<Ubicaciones> &edificios, Constructor &bob, bool fin_turno)
{

    for (int i = 1; i < edificios.mostrar_cantidad() + 1; i++)
    {
        if (obtener_nombre(edificios[i]) == "mina")
            mina_chequeado = true;
        if (obtener_nombre(edificios[i]) == "mina oro")
            mina_oro_chequeado = true;
    }

    if (mina_chequeado && mina_oro_chequeado)
        objetivo_cumplido = true;
}

void Minero::mostrar_objetivo()
{
    msjeTitulo("* Minero: haber construido una mina de cada tipo. ");
    if (mina_chequeado || mina_oro_chequeado)
    {
        msjeInstruccion("\tHasta el momento construyo al menos: ");
        if (mina_chequeado)
            msjeInstruccion("\t- Una mina");
        if (mina_oro_chequeado)
            msjeInstruccion("\t- Una mina Oro");
    }
    else
        msjeInstruccion("\tHasta el momento no construyo ninguna");

    if (objetivo_cumplido)
        msjeOK("\tEl objetivo esta cumplido.\n");
    else
        msjeError("\tEl objetivo no esta cumplido.\n");
}

bool Minero::es_principal()
{
    return false;
}
