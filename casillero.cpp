#include "casillero.hpp"

Casillero::Casillero(){
    jugador = NULL;
}

Casillero::~Casillero(){}

bool Casillero::agregar(Edificio * edif_ptr)
{
    msjeError("No puede construir en este casillero");
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

void Casillero::borrar_jugador(){
    jugador = NULL;
}