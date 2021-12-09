#include "edificioYacimiento.hpp"

Yacimiento::Yacimiento(int s, int w, int m, int p) : Edificio(s, w, m, p)
{
    nombre = "yacimiento";
    codigo = "Y";

    vida = 1;

    produccion = "no produce";
    cant_produccion = 0;
}

Yacimiento::Yacimiento(Edificio *edificio) : Edificio(edificio) {}

