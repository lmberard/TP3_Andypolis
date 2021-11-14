#ifndef CASILLEROINACCESIBLE_HPP
#define CASILLEROINACCESIBLE_HPP
#include "casillero.hpp"

class CasilleroInaccesible : public Casillero
{
public:
    // PRE: -
    // POS: Se construye un casillero innacesible
    CasilleroInaccesible();

    // PRE: Existe un casillero innacesible
    // POS: Se destruye el casillero innacesible
    ~CasilleroInaccesible();

    // PRE: -
    // POS: Muestra por la terminal que tipo de casillero es
    void mostrar();

    // PRE: -
    // POS: Muestra por la terminal un cuadrado con el color del casillero innacesible
    void display();

    // PRE: -
    // POS: No hace nada
    void demoler();
};

#endif // CASILLEROINACCESIBLE_HPP
