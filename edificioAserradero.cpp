#include "edificio.hpp"
#include "edificioAserradero.hpp"

Aserradero::Aserradero(int s, int w, int m, int p) : Edificio(s, w, m, p)
{
    nombre = "aserradero";
    codigo = "A";
    cant_mat_que_produce = 25;
    mat_que_produce = "madera";

    //material1 = "piedra";
    //material2 = "madera";
    //material3 = "metal";

}

Aserradero::Aserradero(Edificio *edificio): Edificio(edificio){}

Aserradero ::~Aserradero(){}
