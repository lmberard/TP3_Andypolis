#ifndef EDIFICIOASERRADERO_HPP
#define EDIFICIOASERRADERO_HPP
#include "edificio.hpp"

class Aserradero : public Edificio
{

public:
    // PRE:
    // POS: Se crea un edificio Aserradero con los parametros para la piedra(s), madera(w), metal(s) y cantidad permitida de construccion(p)
    Aserradero(int s, int w, int m, int p);

    Aserradero(Edificio *edificio);

    // PRE:
    // POS: Se destruye el edificio aserradero
    ~Aserradero();
};
#endif // EDIFICIOASERRADERO_HPP
