#include "edificioPlantaElectrica.hpp"

PlantaElectrica::PlantaElectrica(int s, int w, int m, int p) : Edificio(s, w, m, p)
{
    nombre = "planta electrica";
    codigo = "P";

    vida = 1;
    
    produccion = "energia";
    cant_produccion = 15;

    deposito = 0;
}

PlantaElectrica::PlantaElectrica(Edificio *edificio): Edificio(edificio){}


