#include <string>
#include <iostream>

#include "cansado.hpp"

using namespace std;

Cansado::Cansado(string objetivo, string tipo) : Objetivo(objetivo, tipo)
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

