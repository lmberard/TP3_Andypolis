#include "terreno.hpp"

Casillero *Terreno::agregar(const string casillero_tipo)
{
    Casillero *casillero = 0;

    if (casillero_tipo == "L")
        casillero = new CasilleroInaccesible();

    if (casillero_tipo == "T")
        casillero = new CasilleroConstruible();

    if (casillero_tipo == "C")
        casillero = new CasilleroTransitable();

    return casillero;
}