#ifndef EDIFICIOYACIMIENTO_HPP
#define EDIFICIOYACIMIENTO_HPP
#include "edificio.hpp"

class Yacimiento : public Edificio
{
public:
    // PRE:
    // POS:
    Yacimiento(int s, int w, int m, int p);

    Yacimiento(Edificio *edificio);

    // PRE:
    // POS:
    ~Yacimiento();
};

#endif // EDIFICIOPLANTAELECTRICA_HPP
