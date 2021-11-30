#ifndef EDIFICIO_HPP
#define EDIFICIO_HPP

#include "colors.hpp"

class Edificio
{
protected:
    string nombre;
    string codigo;

    int piedra;
    int madera;
    int metal;

    int cantidad_permitida;

    string produccion;
    int cant_produccion;

    int vida;

public:
    // PRE: -
    // POS: Instancia el edificio con los parametros para la piedra(s), madera(w), metal(s) y cantidad permitida de construccion(p)
    Edificio(int s, int w, int m, int p);

    // PRE: -
    // POS: Se construye un edificio que es la copia del ingresado. (Constructor copia)
    Edificio(Edificio *edificio);

    // PRE: -
    // POS: Devuelve el nombre del edificio
    string obtener_nombre();

    // PRE: -
    // POS: Devuelve la cantidad de unidades de madera necesaria para su construccion
    int obtener_madera();

    // PRE: -
    // POS: Devuelve la cantidad de unidades de metal necesaria para su construccion
    int obtener_metal();

    // PRE: -
    // POS: Devuelve la cantidad de unidades de piedra necesaria para su construccion
    int obtener_piedra();

    // PRE: -
    // POS: Devuelve la cantidad maxima de edificios que se pueden construir
    int obtener_cant_max();

    // PRE: -
    // POS: Devuelve el codigo del edificio (primera letra de su nombre)
    string obtener_codigo();

    // PRE: -
    // POS: Devuelve la cantidad del material que produce
    int obtener_cant_produccion();

    // PRE: -
    // POS: Devuelve el nombre del material que produce
    string obtener_tipo_produccion();

    // PRE: -
    // POS: -
    int obtener_vida();

    // PRE: -
    // POS: -
    void bajar_vida();

    // PRE: -
    // POS: -
    void subir_vida();
};

#endif // EDIFICIO_HPP
