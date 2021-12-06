#include <string>
#include <iostream>

#include "construirObelisco.hpp"

using namespace std;

ConstruirObelisco::ConstruirObelisco() : Objetivo()
{
}

ConstruirObelisco::~ConstruirObelisco()
{
}

string ConstruirObelisco::obtener_objetivo(){
    return "Construir Obelisco";
}

bool ConstruirObelisco::es_principal(){
    return true;
}

