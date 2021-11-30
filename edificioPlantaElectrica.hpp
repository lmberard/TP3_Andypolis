#ifndef EDIFICIOPLANTAELECTRICA_HPP
#define EDIFICIOPLANTAELECTRICA_HPP
#include "edificio.hpp"

class PlantaElectrica : public Edificio
{
public:
    // PRE:
    // POS: Se crea un edificio Planta Electrica con los parametros para la piedra(s), madera(w), metal(s) y cantidad permitida de construccion(p)
    PlantaElectrica(int s, int w, int m, int p);

    // PRE:
    // POS: 
    PlantaElectrica(Edificio *edificio); 
};

#endif // EDIFICIOPLANTAELECTRICA_HPP
