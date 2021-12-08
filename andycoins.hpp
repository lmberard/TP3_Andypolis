#ifndef ANDYCOINS_HPP
#define ANDYCOINS_HPP

#include "material.hpp"

using namespace std;

class Andycoins : public Material
{

public:
    // PRE:
    // POS: Crea un andycoin
    Andycoins();

    // PRE:
    // POS: Crea un andycoin con una cantidad determinada
    Andycoins(int);

    // PRE:
    // POS: destruye el andycoin
    ~Andycoins();
};

#endif // ANDYCOINS_HPP