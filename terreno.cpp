#include "terreno.hpp"

Terreno::Terreno()
{
    caracteristicas();
}

void Terreno::caracteristicas()
{
    casillero_nombre = "terreno";
    color = BGND_GREEN_2;
}

void Terreno::desrecorrer()
{
    color = BGND_GREEN_2;
}
