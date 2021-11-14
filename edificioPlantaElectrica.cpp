#include "edificioPlantaElectrica.hpp"

PlantaElectrica::PlantaElectrica(int s, int w, int m, int p) : Edificio(s, w, m, p)
{
    nombre = "planta electrica";
    codigo = "P";
    cant_mat_que_produce = 0;
    mat_que_produce = "No brinda materiales";

    //material1 = "piedra";
    //material2 = "madera";
    //material3 = "metal";
}

PlantaElectrica::PlantaElectrica(Edificio *edificio): Edificio(edificio){}

PlantaElectrica::~PlantaElectrica(){}

