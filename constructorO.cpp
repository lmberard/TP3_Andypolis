#include <string>
#include <iostream>

#include "constructorO.hpp"

using namespace std;

ConstructorO::ConstructorO() : Objetivo()
{
    mina_chequeado = false;
    aserradero_chequeado = false;
    fabrica_chequeado = false;
    escuela_chequeado = false;
    planta_electrica_chequeado = false;
    mina_oro_chequeado = false;
}

ConstructorO::~ConstructorO()
{
}

void ConstructorO::chequear_estado(Inventario &inventario, int puntos_energia, Lista<Ubicaciones> &edificios, Constructor &bob, bool fin_turno)
{
    for (int i = 1; i < edificios.mostrar_cantidad() + 1; i++)
    {
        if (obtener_nombre(edificios[i]) == "mina")
            mina_chequeado = true;
        if (obtener_nombre(edificios[i]) == "aserradero")
            aserradero_chequeado = true;
        if (obtener_nombre(edificios[i]) == "fabrica")
            fabrica_chequeado = true;
        if (obtener_nombre(edificios[i]) == "escuela")
            escuela_chequeado = true;
        if (obtener_nombre(edificios[i]) == "planta electrica")
            planta_electrica_chequeado = true;
        if (obtener_nombre(edificios[i]) == "mina oro")
            mina_oro_chequeado = true;
    }

    if (mina_chequeado && aserradero_chequeado && fabrica_chequeado &&
        escuela_chequeado && planta_electrica_chequeado && mina_oro_chequeado)
        objetivo_cumplido = true;
}

void ConstructorO::mostrar_objetivo()
{
    msjeTitulo("* Constructor: construir un edificio de cada tipo.");
    msjeInstruccion("Hasta ahora hay construidos: ");
    if (mina_chequeado)
        msjeInstruccion("\t- Mina");
    if (aserradero_chequeado)
        msjeInstruccion("\t- Aserradero");
    if (fabrica_chequeado)
        msjeInstruccion("\t- Fabrica");
    if (escuela_chequeado)
        msjeInstruccion("\t- Escuela");
    if (planta_electrica_chequeado)
        msjeInstruccion("\t- Planta electrica");
    if (mina_oro_chequeado)
        msjeInstruccion("\t- Mina oro");

    if (objetivo_cumplido)
        msjeOK("\tEl objetivo esta cumplido\n");
    else
        msjeError("\tEl objetivo no esta cumplido\n");
}

bool ConstructorO::es_principal()
{
    return false;
}
