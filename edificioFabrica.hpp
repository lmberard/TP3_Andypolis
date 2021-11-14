#ifndef EDIFICIOFABRICA_HPP
#define EDIFICIOFABRICA_HPP
#include "edificio.hpp"

class Fabrica : public Edificio
{
public:
    // PRE:
    // POS: Se crea un edificio Fabrica con los parametros para la piedra(s), madera(w), metal(s) y cantidad permitida de construccion(p)
    Fabrica(int s, int w, int m, int p);

    Fabrica(Edificio *edificio);

    // PRE:
    // POS: Se destruye el edificio Fabrica
    ~Fabrica();
};

#endif // EDIFICIOFABRICA_HPP
