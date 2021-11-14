#ifndef MATERIALMETAL_HPP
#define MATERIALMETAL_HPP
#include "material.hpp"

#include <iostream>
#include <string>
#include <fstream>
#include "colors.hpp"

using namespace std;

class Metal : public Material
{

public:
    // PRE:
    // POS: Crea un material metal
    Metal();

    // PRE:
    // POS: Crea un material metal con una cantidad determinada
    Metal(int);

    // PRE:
    // POS: destruye el material metal
    ~Metal();
};

#endif // MATERIAL_HPP