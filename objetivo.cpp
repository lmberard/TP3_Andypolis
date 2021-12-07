#include <string>
#include <iostream>

#include "objetivo.hpp"

using namespace std;

Objetivo::Objetivo()
{
    objetivo_cumplido = false;
}


Objetivo::~Objetivo()
{
}

/*
bool Objetivo::es_principal()
{
    bool aux = false;

    if (tipo == OBJETIVO_PRINCIPAL)
        aux = true;
    else if (tipo == OBJETIVO_SECUNDARIO)
        aux = false;

    return aux;
}
*/
bool Objetivo::chequear_estado(Inventario & inventario, int puntos_energia, Lista<Ubicaciones> & edificios)
{
    return true;
}

bool Objetivo::cumplido()
{
    return objetivo_cumplido;
}
/*
bool Objetivo::chequear_estado(int puntos_energia)
{
    return true;
}*/

/*
bool Objetivo::chequear_estado(Diccionario & diccionario, Lista<Ubicaciones> edificios;)
{
    return true;
}
*/
/*
bool Objetivo::chequear_estado(Lista<Ubicaciones> & edificios)
{
    return true;
}*/