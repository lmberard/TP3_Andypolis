#include "superficie.hpp"

Casillero *Superficie::agregar(const string casillero_tipo)
{
    Casillero *casillero = NULL;

    if (casillero_tipo == "L")
        casillero = new Lago();

    if (casillero_tipo == "T")
        casillero = new Terreno();

    if (casillero_tipo == "C")
        casillero = new Camino();

    if (casillero_tipo == "B")
        casillero = new Betun();
    
    if (casillero_tipo == "M")
        casillero = new Muelle();

    return casillero;
}
