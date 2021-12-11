#ifndef MATERIALBOMBA_HPP
#define MATERIALBOMBA_HPP

#include "material.hpp"

using namespace std;

class Bomba : public Material
{

public:
    // PRE:
    // POS: Crea un material metal
    Bomba();

    // PRE:
    // POS: Crea un material metal con una cantidad determinada
    Bomba(int);

    // PRE:
    // POS: destruye el material metal
    ~Bomba();
};

#endif // MATERIALBOMBA_HPP