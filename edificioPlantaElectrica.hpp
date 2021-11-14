#ifndef EDIFICIOPLANTAELECTRICA_HPP
#define EDIFICIOPLANTAELECTRICA_HPP
#include "edificio.hpp"

class PlantaElectrica : public Edificio
{
public:
    // PRE:
    // POS: Se crea un edificio Planta Electrica con los parametros para la piedra(s), madera(w), metal(s) y cantidad permitida de construccion(p)
    PlantaElectrica(int s, int w, int m, int p);

    PlantaElectrica(Edificio *edificio);

    // PRE:
    // POS: se destruye el edificio planta electrica
    ~PlantaElectrica();
};

#endif // EDIFICIOPLANTAELECTRICA_HPP
