#include "edificioAserradero.hpp"

Aserradero::Aserradero(int s, int w, int m, int p) : Edificio(s, w, m, p)
{
    nombre = "aserradero";
    codigo = "A";

    vida = 1;
    
    produccion = "madera";
    cant_produccion = 25;

    deposito = 0;
}

Aserradero::Aserradero(Edificio *edificio): Edificio(edificio){}

