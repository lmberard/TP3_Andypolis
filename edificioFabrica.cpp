#include "edificioFabrica.hpp"

Fabrica::Fabrica(int s, int w, int m, int p) : Edificio(s, w, m, p)
{
    nombre = "fabrica";
    codigo = "F";

    vida = 2;

    produccion = "metal";
    cant_produccion = 40;

    deposito = 0;
}

Fabrica::Fabrica(Edificio *edificio): Edificio(edificio){}

