#ifndef EDIFICIOOBELISCO_HPP
#define EDIFICIOOBELISCO_HPP
#include "edificio.hpp"

class Obelisco : public Edificio
{
public:
    // PRE:
    // POS: Se crea un edificio Obelisco con los parametros para la piedra(s), madera(w), metal(s) y cantidad permitida de construccion(p)
    Obelisco(int s, int w, int m, int p);

    // PRE:
    // POS:
    Obelisco(Edificio *edificio);
};

#endif // EDIFICIOOBELISCO_HPP
