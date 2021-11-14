#include "casilleroTransitable.hpp"

CasilleroTransitable ::CasilleroTransitable() : Casillero()
{
    material = 0;
}

CasilleroTransitable ::~CasilleroTransitable() {}

void CasilleroTransitable ::mostrar()
{
    cout << TXT_LIGHT_GRAY_247 << "Es un casillero transitable" << END_COLOR << endl;
    if (material)
        cout << "Hay un material del tipo '" << material->obtener_nombre() << "'. No te olvides de recolectarlo!" << endl;

    else
        cout << "No hay ningun material en esta parte del camino :)" << endl;
}

void CasilleroTransitable ::display()
{
    if (!material)
        cout << TXT_BLACK_16 << TXT_UNDERLINE << BGND_LIGHT_GRAY_247 << "   " << END_COLOR << " ";
    else
        cout << TXT_BLACK_16 << TXT_UNDERLINE << BGND_LIGHT_GRAY_247 << " " << material->obtener_codigo() << " " << END_COLOR << " ";
}

bool CasilleroTransitable ::agregar(Material *material)
{
    if (this->material)
    {
        msjeError("Ya hay un material en este casillero, no hay lugar para agregar otro :(");
        return false;
    }
    this->material = material;
    return true;
}

void CasilleroTransitable ::demoler()
{
    delete material;
    material = NULL;
}

bool CasilleroTransitable ::estransitable()
{
    return true;
}