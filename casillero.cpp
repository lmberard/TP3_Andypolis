#include "casillero.hpp"

Casillero::Casillero() {}

bool Casillero::agregar(Edificio *)
{
    cout << "No puedes construir en este casillero" << endl;
    return false;
}

Edificio *Casillero::mostrar_edificio()
{
    return NULL;
}