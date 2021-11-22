#include "casilleroInaccesible.hpp"

CasilleroInaccesible ::CasilleroInaccesible() : Casillero(){}

CasilleroInaccesible ::~CasilleroInaccesible(){}

void CasilleroInaccesible ::info()
{
    cout << "Es un " << casillero_nombre << ", es un casillero inaccesible" << endl;
}

void CasilleroInaccesible ::mostrar_por_pantalla()
{
    cout << TXT_BLACK_16 << TXT_UNDERLINE << color << "   " << END_COLOR << " ";
}

