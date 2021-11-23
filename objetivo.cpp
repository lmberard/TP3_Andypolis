#include <string>
#include <iostream>

#include "objetivo.hpp"

using namespace std;

Objetivo::Objetivo()
{
    objetivo.clear();
    tipo.clear();
}

Objetivo::Objetivo(string objetivo, string tipo)
{
    this->objetivo = objetivo;
    this->tipo = tipo;
}

Objetivo::~Objetivo()
{
}

string Objetivo::obtener_objetivo() const
{
    return objetivo;
}

bool Objetivo::es_principal()
{
    bool aux = false;

    if (tipo == OBJETIVO_PRINCIPAL)
        aux = true;
    else if (tipo == OBJETIVO_SECUNDARIO)
        aux = false;

    return aux;
}
