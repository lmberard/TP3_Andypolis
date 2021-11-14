#include "casilleroInaccesible.hpp"

CasilleroInaccesible ::CasilleroInaccesible() : Casillero() {}

CasilleroInaccesible ::~CasilleroInaccesible() {}

void CasilleroInaccesible ::mostrar()
{
    cout << TXT_BLUE_25 << "Es un casillero inaccesible" << END_COLOR << endl;
}

void CasilleroInaccesible ::display()
{
    cout << TXT_BLACK_16 << TXT_UNDERLINE << BGND_BLUE_25 << "   " << END_COLOR << " ";
}

void CasilleroInaccesible ::demoler()
{
}
