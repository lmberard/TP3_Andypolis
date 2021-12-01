#include "bombardero.hpp"

using namespace std;

Bombardero::Bombardero(string objetivo, string tipo) : Objetivo(objetivo, tipo)
{
}

Bombardero::~Bombardero()
{
}

bool Bombardero::chequear_estado(Inventario & inventario){
    bool aux = false;

    if(inventario.obtener_bombas_usadas() >= CANTIDAD_BOMBAS_USADAS_OBJETIVO){
        aux = true;
        objetivo_cumplido = true;
    }

    return aux;
}