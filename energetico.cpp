#include <string>
#include <iostream>

#include "energetico.hpp"

using namespace std;

Energetico::Energetico() : Objetivo()
{
}

Energetico::~Energetico()
{
}

bool Energetico::chequear_estado(int puntos_energia){
    bool aux = false;

    if(puntos_energia == CANTIDAD_MAX_ENERGIA){
        aux = true;
        objetivo_cumplido = true;
    }

    return aux;
}

string Energetico::obtener_objetivo(){
    return "Energetico";
}
