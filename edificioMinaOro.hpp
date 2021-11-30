#ifndef EDIFICIOMINAORO_HPP
#define EDIFICIOMINAORO_HPP
#include "edificio.hpp"

class MinaOro : public Edificio
{
public:
    // PRE:
    // POS: Se crea un edificio Mina con los parametros para la piedra(s), madera(w), metal(s) y cantidad permitida de construccion(p)
    MinaOro(int s, int w, int m, int p);

    // PRE:
    // POS:
    MinaOro(Edificio *edificio);
};
#endif // EDIFICIOMINAORO_HPP
