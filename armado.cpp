#include "armado.hpp"

using namespace std;

Armado::Armado(string objetivo, string tipo) : Objetivo(objetivo, tipo)
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

// TODO: BORRAR PIPO 