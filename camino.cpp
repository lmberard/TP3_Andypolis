#include "camino.hpp"

Camino::Camino()
{
    caracteristicas();
}

void Camino::caracteristicas()
{
    casillero_nombre = "camino";
    color = BGND_LIGHT_GRAY_247;
}

void Camino::desrecorrer()
{
    color = BGND_LIGHT_GRAY_247;
}
