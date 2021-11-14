#include "edificioObelisco.hpp"

Obelisco::Obelisco(int s, int w, int m, int p) : Edificio(s, w, m, p)
{
    nombre = "obelisco";
    codigo = "O";
    cant_mat_que_produce = 0;
    mat_que_produce = "No produce materiales";

    //material1 = "piedra";
    //material2 = "madera";
    //material3 = "metal";
}

Obelisco::Obelisco(Edificio *edificio): Edificio(edificio){}

Obelisco::~Obelisco(){}
