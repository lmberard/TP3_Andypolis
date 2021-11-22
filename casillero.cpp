#include "casillero.hpp"

Casillero::Casillero(){}

Casillero::~Casillero(){}

bool Casillero::agregar(Edificio *)
{
    cout << "No puedes construir en este casillero" << endl;
    return false;
}

bool Casillero::agregar(Material *)
{
    return false;
}

Edificio *Casillero::info_edificio()
{
    return NULL;
}

void Casillero::quitar_elemento(){}

bool Casillero::estransitable()
{
    return false;
}
