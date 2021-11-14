#ifndef CASILLEROCONSTRUIBLE_HPP
#define CASILLEROCONSTRUIBLE_HPP
#include "casillero.hpp"

class CasilleroConstruible : public Casillero
{
    Edificio *edificio;

public:
    // PRE: -
    // POS: Se construye un casillero construible
    CasilleroConstruible();

    // PRE: Existe el constructor del casillero construible
    // POS: Se destruye el casillero construible
    ~CasilleroConstruible();

    // PRE: -
    // POS: Se crea el edificio que se mando como argumento en el casillero. Devuelve true si se pudo agregar y false si no.
    bool agregar(Edificio *edificio);

    // PRE: -
    // POS: Muestra por la terminal que tipo de casillero es y si tiene un edificio construido o no.
    void mostrar();

    // PRE: -
    // POS: Muestra por la terminal un cuadrado con el color del casillero construible y si hay un edificio construido, su primera letra del nombre.
    void display();

    // PRE: -
    // POS: Elimina el edificio en el casillero y apunta a null a su atributo.
    void demoler();

    // PRE: -
    // POS: Devuelve el edificio que esta construido en el casillero. Si no hay edificio construido devuelve NULL (cero)
    Edificio *mostrar_edificio();
};
#endif // CASILLEROONSTRUIBLE_HPP
