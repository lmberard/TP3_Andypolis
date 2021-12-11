#include <string>
#include <iostream>

#include "comprarAndypolis.hpp"

using namespace std;

ComprarAndypolis::ComprarAndypolis() : Objetivo()
{
}

ComprarAndypolis::~ComprarAndypolis()
{
}

bool ComprarAndypolis::chequear_estado(Inventario & inventario, int puntos_energia, Lista<Ubicaciones> & edificios, Constructor & bob, bool fin_turno){
    bool aux = false;

    if(inventario.obtener_andycoins_contador() >= CANTIDAD_ANDYCOINS_OBJETIVO){
        aux = true;
        objetivo_cumplido = true;
    }

    return aux;
}

void ComprarAndypolis::obtener_objetivo(){
    cout << "Comprar andypolis: haber juntado 100.000 andycoins a lo largo de la partida" << endl;
    //cout << "juntestes ..." << endl;
    if(objetivo_cumplido)
        cout << "el objetivo está cumplido" << endl;
    else
        cout << "el objetivo no está cumplido" << endl;
}

bool ComprarAndypolis::es_principal(){
    return false;
}
