#include "edificioMinaOro.hpp"

MinaOro::MinaOro(int s, int w, int m, int p) : Edificio(s, w, m, p)
{
    nombre = "mina oro";
    codigo = "G";

    vida = 2;

    produccion = "andycoins";
    cant_produccion = 50;
}

MinaOro::MinaOro(Edificio *edificio) : Edificio(edificio) {}