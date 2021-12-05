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

string Letrado::obtener_objetivo(){
    return "Letrado";
}

bool Letrado::es_principal(){
    return false;
}
