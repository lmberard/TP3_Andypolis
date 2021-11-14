#ifndef MATERIAL_HPP
#define MATERIAL_HPP

#include <iostream>
#include <string>
#include <fstream>
#include "colors.hpp"

using namespace std;

class Material
{
protected:
    string nombre;
    string codigo;
    int cantidad;

public:
    // PRE:
    // POS: Se construye un material
    Material();

    // PRE:
    // POS: Se construye un material con una cantidad determinada
    Material(int cantidad);

    // PRE:
    // POS: Se destruye el material
    ~Material();

    // PRE:
    // POS: Devuelve el nombre del material
    string obtener_nombre();

    // PRE:
    // POS: Devuelve el codigo del material (primera letra del nombre en ingles)
    string obtener_codigo();

    // PRE:
    // POS: Devuelve la cantidad del material
    int obtener_cantidad();

    // PRE:
    // POS: Modifica la cantidad del material al valor ingresado
    void modificar_cantidad(int cantidad);
};
#endif // MATERIAL_HPP