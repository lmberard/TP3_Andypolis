#include <string>
#include <iostream>

#include "bombardero.hpp"

using namespace std;

Bombardero::Bombardero() : Objetivo()
{
}

Bombardero::~Bombardero()
{
}

bool Bombardero::chequear_estado(Inventario & inventario){
    bool aux = false;

    if(inventario.obtener_bombas_usadas() >= CANTIDAD_BOMBAS_USADAS_OBJETIVO){
        aux = true;
        objetivo_cumplido = true;
    }

    return aux;
}

string Bombardero::obtener_objetivo(){
    return "Bombardero";
}

bool Bombardero::es_principal(){
    return false;
}
