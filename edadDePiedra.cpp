#include <string>
#include <iostream>

#include "edadDePiedra.hpp"

using namespace std;

EdadDePiedra::EdadDePiedra() : Objetivo()
{
}

EdadDePiedra::~EdadDePiedra()
{
}

bool EdadDePiedra::chequear_estado(Inventario & inventario){
    bool aux = false;

    if(inventario.obtener_material("piedra")->obtener_cantidad() >= CANTIDAD_PIEDRA_OBJETIVO){
        aux = true;
        objetivo_cumplido = true;
    }
        
    return aux;
}
