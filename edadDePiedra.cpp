#include <string>
#include <iostream>

#include "edadDePiedra.hpp"

using namespace std;

EdadDePiedra::EdadDePiedra(string objetivo, string tipo) : Objetivo(objetivo, tipo)
{
}

EdadDePiedra::~EdadDePiedra()
{
}

bool EdadDePiedra::chequear_estado(Inventario & inventario){
    bool aux;

    if(inventario.obtener_material("piedra")->obtener_cantidad() >= CANTIDAD_PIEDRA_OBJETIVO){
        aux = true;
        objetivo_cumplido = true;
    }
    else
        aux = false;
        
    return aux;
}

