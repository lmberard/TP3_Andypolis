#ifndef MATERIALPIEDRA_HPP
#define MATERIALPIEDRA_HPP
#include "material.hpp"

#include <iostream>
#include <string>
#include <fstream>
#include "colors.hpp"

using namespace std;

class Piedra : public Material
{

public:
    // PRE:
    // POS: construye el material piedra
    Piedra();

    // PRE:
    // POS: construye el material piedra con una cantidad determinada
    Piedra(int);

    // PRE:
    // POS: destruye el material piedra
    ~Piedra();
};

#endif // MATERIAL_HPP