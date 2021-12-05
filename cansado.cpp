#include <string>
#include <iostream>

#include "cansado.hpp"

using namespace std;

Cansado::Cansado() : Objetivo()
{
}

Cansado::~Cansado()
{
}

bool Cansado::chequear_estado(int puntos_energia){
    bool aux = false;

    if(puntos_energia == CANTIDAD_MIN_ENERGIA){
        aux = true;
        objetivo_cumplido = true;
    }

    return aux;
}

string Cansado::obtener_objetivo(){
    return "Cansado";
}

bool Cansado::es_principal(){
    return false;
}
