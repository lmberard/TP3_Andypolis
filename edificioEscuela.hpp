#ifndef EDIFICIOESCUELA_HPP
#define EDIFICIOESCUELA_HPP
#include "edificio.hpp"

class Escuela : public Edificio
{

public:
    // PRE:
    // POS: Se crea un edificio Escuela con los parametros para la piedra(s), madera(w), metal(s) y cantidad permitida de construccion(p)
    Escuela(int s, int w, int m, int p);

    Escuela(Edificio *edificio);

    // PRE:
    // POS: Se destruye el edificio Escuela
    ~Escuela();
};
#endif // EDIFICIOESCUELA_HPP
