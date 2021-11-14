#ifndef CASILLEROTRANSITABLE_HPP
#define CASILLEROTRANSITABLE_HPP
#include "casillero.hpp"

class CasilleroTransitable : public Casillero
{
    Material *material;

public:
    // PRE:
    // POS: Se construye un casillero transitable
    CasilleroTransitable();

    // PRE:
    // POS: Se elimina un casillero transitable
    ~CasilleroTransitable();

    // PRE:
    // POS: Muestra por la terminal que tipo de casillero es y si tiene material o no.
    void mostrar();

    // PRE:
    // POS: Muestra por la terminal un cuadrado con el color del casillero construible y si hay un material, su primera letra del nombre.
    void display();

    // PRE: -
    // POS: Devuelve true
    bool estransitable();

    // PRE: -
    // POS: Se crea el material que se mando como argumento en el casillero. Devuelve true si se pudo agregar y false si no.
    bool agregar(Material *material);

    // PRE:
    // POS: Elimina el material en el casillero y apunta a null a su atributo.
    void demoler();
};

#endif // CASILLEROTRANSITABLE_HPP
