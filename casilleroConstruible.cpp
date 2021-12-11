#include "casilleroConstruible.hpp"

CasilleroConstruible ::CasilleroConstruible() : Casillero()
{
    edificio = 0;
}

CasilleroConstruible ::~CasilleroConstruible() {}

bool CasilleroConstruible ::agregar(Edificio *edificio)
{
    if (this->edificio || jugador)
    {
        msjeError("Este casillero ya esta ocupado");
        delete edificio;
        return false;
    }

    this->edificio = edificio;
    return true;
}

bool CasilleroConstruible ::agregar(Jugador *jugador)
{
    if (edificio || this->jugador)
    {
        msjeError("Ya hay un edificio en esta posicion. No se puede agregar otro");
        return false;
    }

    this->jugador = jugador;
    return true;
}

void CasilleroConstruible ::info()
{
    cout << TXT_LIGHT_BLUE_6 << "Es un " << casillero_nombre <<  ", es un casillero construible." << END_COLOR << endl;
    if (edificio)
        cout << TXT_LIGHT_BLUE_6 << "Hay un edificio del tipo '" << edificio->obtener_nombre() << "' construido en esta coordenada." << END_COLOR << endl;
    if (jugador)
        cout << TXT_LIGHT_BLUE_6 << "En este casillero se encuentra el jugador " << jugador->obtener_codigo() << END_COLOR << endl;
    if(!edificio && !jugador)
        cout << TXT_LIGHT_BLUE_6 << "El casillero no contiene un edificio construido" << END_COLOR << endl;
}

void CasilleroConstruible ::mostrar_por_pantalla()
{
    if (!edificio && !jugador)
        cout << TXT_BLACK_16 << TXT_UNDERLINE << color << "   " << END_COLOR << " ";
    if(edificio)
        cout << TXT_BLACK_16 << TXT_UNDERLINE << color << " " << edificio->obtener_codigo() << " " << END_COLOR << " ";
    if(jugador)
        cout << TXT_BLACK_16 << TXT_UNDERLINE << color << " " << jugador->obtener_codigo() << " " << END_COLOR << " ";
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
