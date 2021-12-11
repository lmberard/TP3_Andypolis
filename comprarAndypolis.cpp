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

void ComprarAndypolis::chequear_estado(Inventario & inventario, int puntos_energia, Lista<Ubicaciones> & edificios, Constructor & bob, bool fin_turno)
{
    progreso = inventario.obtener_andycoins_gastadas() + inventario.obtener_material("andycoins")->obtener_cantidad();
    if(progreso >= CANTIDAD_ANDYCOINS_OBJETIVO)
        objetivo_cumplido = true;
}

void ComprarAndypolis::mostrar_objetivo(){
    cout << TXT_LIGHT_BLUE_6 << "Comprar andypolis: haber juntado 100.000 andycoins a lo largo de la partida." << END_COLOR << endl;
    cout << TXT_LIGHT_BLUE_6 << "A lo largo de la partida recolecto " << progreso << " andycoins" << END_COLOR << endl;
    if(objetivo_cumplido)
        msjeInstruccion("El objetivo esta cumplido");
    else
        msjeInstruccion("El objetivo no esta cumplido");
}

bool ComprarAndypolis::es_principal(){
    return false;
}
