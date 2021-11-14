#ifndef RECURSO_HPP
#define RECURSO_HPP

#include "lista.hpp"

#include "material.hpp"
#include "materialMadera.hpp"
#include "materialMetal.hpp"
#include "materialPiedra.hpp"

class Recurso
{

public:
    // PRE:
    // POS: construye el material con un nombre ingresado (material) con su cantidad y lo devuelve
    Material *dar_material(const string &material, int cantidad);

    // PRE:
    // POS: construye el material con un nombre ingresado (material) con cantidad=1 por default y lo devuelve
    Material *dar_material(const string &material);
};

#endif //RECURSO_HPP