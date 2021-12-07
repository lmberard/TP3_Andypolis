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

bool Energetico::chequear_estado(Inventario & inventario, int puntos_energia, Lista<Ubicaciones> & edificios, Constructor & bob, bool fin_turno){
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

bool Energetico::es_principal(){
    return false;
}
