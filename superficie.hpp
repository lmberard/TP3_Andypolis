#ifndef SUPERFICIE_HPP
#define SUPERFICIE_HPP

#include "camino.hpp"
#include "lago.hpp"
#include "terreno.hpp"
#include "betun.hpp"
#include "muelle.hpp"

class Superficie
{

public:
    // PRE: -
    // POST: Crea un casillero segun el tipo ingresado (L, T o C) y lo devuelve. Si se ingresa mal el nombre del casillero devuelve null(0)
    Casillero *agregar(const string casillero_tipo);
};

#endif //SUPERFICIE_HPP
