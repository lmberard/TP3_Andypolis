#include "casillero.hpp"

Casillero::Casillero(){
    jugador = NULL;
}

Casillero::~Casillero(){}

bool Casillero::agregar(Edificio * edif_ptr)
{
    cout << "No puedes construir en este casillero" << endl;
    delete edif_ptr;
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
