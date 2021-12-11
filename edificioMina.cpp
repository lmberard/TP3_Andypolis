#include "edificioMina.hpp"

Mina::Mina(int s, int w, int m, int p) : Edificio(s, w, m, p)
{
    nombre = "mina";
    codigo = "M";

    vida = 2;

    produccion = "piedra";
    cant_produccion = 15;

    deposito = 0;
}

Mina::Mina(Edificio *edificio) : Edificio(edificio) {}
