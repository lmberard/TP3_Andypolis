#include <string>
#include <iostream>

#include "armado.hpp"

using namespace std;

Armado::Armado() : Objetivo()
{
}

Armado::~Armado()
{
}

bool Armado::chequear_estado(Inventario & inventario){
    bool aux = false;

    if(inventario.obtener_material("bomba")->obtener_cantidad() >= CANTIDAD_BOMBAS_INVENTARIO_OBJETIVO){
        aux = true;
        objetivo_cumplido = true;
    }
        
    return aux;
}

string Armado::obtener_objetivo(){
    return "Armado";
}

bool Armado::es_principal(){
    return false;
}

