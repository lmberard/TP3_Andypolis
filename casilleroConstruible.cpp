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

void CasilleroConstruible ::info()
{
    cout << "Es un " << casillero_nombre <<  ", es un casillero construible" << endl;
    if (edificio)
        cout << "Hay un edificio del tipo '" << edificio->obtener_nombre() << "' construido en esta coordenada" << endl;
    else
        cout << "Tengo lugar para construir un edificio" << endl;
}

void CasilleroConstruible ::mostrar_por_pantalla()
{
    if (!edificio)
        cout << TXT_BLACK_16 << TXT_UNDERLINE << color << "   " << END_COLOR << " ";
    else
        cout << TXT_BLACK_16 << TXT_UNDERLINE << color << " " << edificio->obtener_codigo() << " " << END_COLOR << " ";
}

Edificio *CasilleroConstruible::info_edificio()
{
    return edificio;
}

void CasilleroConstruible::quitar_elemento()
{
    if (edificio)
    {
        delete edificio;
        edificio = NULL;
    }
}
