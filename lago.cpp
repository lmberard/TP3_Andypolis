#include "lago.hpp"

Lago::Lago()
{
    caracteristicas();
}

void Lago::caracteristicas()
{
    casillero_nombre = "lago";
    color = BGND_BLUE_25;
}

void Lago::desrecorrer()
{
    color = BGND_BLUE_25;
}
