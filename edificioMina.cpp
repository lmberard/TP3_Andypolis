#include "edificioMina.hpp"
#include "edificio.hpp"

Mina::Mina(int s, int w, int m, int p) : Edificio(s, w, m, p)
{
    nombre = "mina";
    codigo = "M";
    cant_mat_que_produce = 15;
    mat_que_produce = "piedra";
}

Mina::Mina(Edificio *edificio) : Edificio(edificio) {}

Mina::~Mina() {}
