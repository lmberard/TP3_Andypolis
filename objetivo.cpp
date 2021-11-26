#include <string>
#include <iostream>

#include "objetivo.hpp"

using namespace std;

Objetivo::Objetivo()
{
    objetivo.clear();
    tipo.clear();
    objetivo_cumplido = false;
}

Objetivo::Objetivo(string objetivo, string tipo)
{
    this->objetivo = objetivo;
    this->tipo = tipo;
    objetivo_cumplido = false;
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

bool Objetivo::chequear_estado(Inventario & inventario){return true;}