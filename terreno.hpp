#ifndef TERRENO_HPP
#define TERRENO_HPP

#include "casillero.hpp"
#include "casilleroTransitable.hpp"
#include "casilleroInaccesible.hpp"
#include "casilleroConstruible.hpp"

class Terreno
{

public:
    // PRE: -
    // POST: Crea un casillero segun el tipo ingresado (L, T o C) y lo devuelve. Si se ingresa mal el nombre del casillero devuelve null(0)
    Casillero *agregar(const string casillero_tipo);
};

#endif //TERRENO_HPP