#ifndef MATERIALMADERA_HPP
#define MATERIALMADERA_HPP
#include "material.hpp"

#include <iostream>
#include <string>
#include <fstream>
#include "colors.hpp"

using namespace std;

class Madera : public Material
{

public:
    // PRE:
    // POS: Crea un material madera
    Madera();

    // PRE:
    // POS: Crea un material madera con una cantidad determinada
    Madera(int);

    // PRE:
    // POS: destruye el material madera
    ~Madera();
};

#endif // MATERIAL_HPP
