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

void ComprarAndypolis::obtener_objetivo(){
    cout << "Comprar andypolis: haber juntado 100.000 andycoins a lo largo de la partida" << endl;
    cout << "juntastes a lo largo de la partida " << progreso << " andycoins" << endl;
    if(objetivo_cumplido)
        cout << "el objetivo está cumplido" << endl;
    else
        cout << "el objetivo no está cumplido" << endl;
}

bool ComprarAndypolis::es_principal(){
    return false;
}
