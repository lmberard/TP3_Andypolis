#ifndef EDIFICIOMINA_HPP
#define EDIFICIOMINA_HPP
#include "edificio.hpp"

class Mina : public Edificio
{
public:
    // PRE:
    // POS: Se crea un edificio Mina con los parametros para la piedra(s), madera(w), metal(s) y cantidad permitida de construccion(p)
    Mina(int s, int w, int m, int p);

    Mina(Edificio *edificio);

    // PRE:
    // POS: Se destruye el edificio mina
    ~Mina();
};
#endif // EDIFICIOMINA_HPP
