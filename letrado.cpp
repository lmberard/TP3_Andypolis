#include <string>
#include <iostream>

#include "letrado.hpp"

using namespace std;

Letrado::Letrado() : Objetivo()
{
}

Letrado::~Letrado()
{
}

bool Letrado::chequear_estado(Inventario & inventario, int puntos_energia, Lista<Ubicaciones> & edificios, Constructor & bob, bool fin_turno)
{   
    return false;
}

string Letrado::obtener_objetivo(){
    return "Letrado";
}

bool Letrado::es_principal(){
    return false;
}
