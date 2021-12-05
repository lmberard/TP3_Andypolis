#include <string>
#include <iostream>

#include "extremista.hpp"

using namespace std;

Extremista::Extremista() : Objetivo()
{
}

Extremista::~Extremista()
{
}

bool Extremista::chequear_estado(Inventario & inventario){
    bool aux = false;

    if(inventario.obtener_bombas_contador() >= CANTIDAD_BOMBAS_COMPRADAS_OBJETIVO){
        aux = true;
        objetivo_cumplido = true;
    }

    return aux;
}

