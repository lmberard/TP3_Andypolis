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

bool ComprarAndypolis::chequear_estado(Inventario & inventario){
    bool aux = false;

    if(inventario.obtener_andycoins_contador() >= CANTIDAD_ANDYCOINS_OBJETIVO){
        aux = true;
        objetivo_cumplido = true;
    }

    return aux;
}

string ComprarAndypolis::obtener_objetivo(){
    return "Comprar Andypolis";
}
