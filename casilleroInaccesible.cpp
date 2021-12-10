#include "casilleroInaccesible.hpp"

CasilleroInaccesible ::CasilleroInaccesible() : Casillero(){}

CasilleroInaccesible ::~CasilleroInaccesible(){}

void CasilleroInaccesible ::info()
{
    cout << "Es un " << casillero_nombre << ", es un casillero inaccesible" << endl;
}

void CasilleroInaccesible ::mostrar_por_pantalla()
{
    if(!jugador)
        cout << TXT_BLACK_16 << TXT_UNDERLINE << color << "   " << END_COLOR << " ";
    else
        cout << TXT_BLACK_16 << TXT_UNDERLINE << color << " " << jugador->obtener_codigo() << " " << END_COLOR << " ";
}

bool CasilleroInaccesible::agregar(Jugador *jugador)
{
    if (this->jugador)
    {
        msjeError("Ya hay un edificio en esta posicion. No se puede agregar otro");
        return false;
    }

    this->jugador = jugador;
    return true;
}
