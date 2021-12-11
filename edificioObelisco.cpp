#include "edificioObelisco.hpp"

Obelisco::Obelisco(int s, int w, int m, int p) : Edificio(s, w, m, p)
{
    nombre = "obelisco";
    codigo = "O";

    vida = 1;

    produccion = "no produce";
    cant_produccion = 0;

    deposito = 0;
}

Obelisco::Obelisco(Edificio *edificio): Edificio(edificio){}

