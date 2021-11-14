#include "casilleroConstruible.hpp"

CasilleroConstruible ::CasilleroConstruible() : Casillero()
{
    edificio = 0;
}

CasilleroConstruible ::~CasilleroConstruible() {}

bool CasilleroConstruible ::agregar(Edificio *edificio)
{
    if (this->edificio)
    {
        msjeError("Ya hay un edificio en esta posicion. No se puede agregar otro");
        return false;
    }

    this->edificio = edificio;
    return true;
}

void CasilleroConstruible ::mostrar()
{
    cout << TXT_GREEN_2 << "Es un casillero construible" << END_COLOR << endl;
    if (edificio)
        cout << "Hay un edificio del tipo '" << edificio->obtener_nombre() << "' construido en esta coordenada" << endl;
    else
        cout << "Tengo lugar para construir un edificio" << endl;
}

void CasilleroConstruible ::display()
{
    if (!edificio)
        cout << TXT_BLACK_16 << TXT_UNDERLINE << BGND_GREEN_2 << "   " << END_COLOR << " ";
    else
        cout << TXT_BLACK_16 << TXT_UNDERLINE << BGND_GREEN_2 << " " << edificio->obtener_codigo() << " " << END_COLOR << " ";
}

Edificio *CasilleroConstruible::mostrar_edificio()
{
    return edificio;
}

void CasilleroConstruible::demoler()
{
    if (edificio)
    {
        delete edificio;
        edificio = NULL;
    }
}