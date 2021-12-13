#include <string>
#include <iostream>

#include "comprarAndypolis.hpp"

using namespace std;

ComprarAndypolis::ComprarAndypolis() : Objetivo()
{
    progreso = 0;
}

ComprarAndypolis::~ComprarAndypolis()
{
}

void ComprarAndypolis::chequear_estado(Inventario &inventario, int puntos_energia, Lista<Ubicaciones> &edificios, Constructor &bob, bool fin_turno)
{
    progreso = inventario.obtener_andycoins_gastadas() + inventario.obtener_material("andycoins")->obtener_cantidad();
    if (progreso >= CANTIDAD_ANDYCOINS_OBJETIVO)
        objetivo_cumplido = true;
}

void ComprarAndypolis::mostrar_objetivo()
{
    msjeTitulo("* Comprar andypolis: haber juntado 100.000 andycoins a lo largo de la partida.");
    msjeInstruccion("\tA lo largo de la partida recolecto " + to_string(progreso) + " andycoins");
    if (objetivo_cumplido)
        msjeInstruccion("\tEl objetivo esta cumplido\n");
    else
        msjeInstruccion("\tEl objetivo no esta cumplido\n");
}

bool ComprarAndypolis::es_principal()
{
    return false;
}
