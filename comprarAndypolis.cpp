#include "comprarAndypolis.hpp"

using namespace std;

ComprarAndypolis::ComprarAndypolis(string objetivo, string tipo) : Objetivo(objetivo, tipo)
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