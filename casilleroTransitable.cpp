#include "casilleroTransitable.hpp"

CasilleroTransitable ::CasilleroTransitable() : Casillero()
{
    material = NULL;
}

CasilleroTransitable ::~CasilleroTransitable(){}

void CasilleroTransitable::info()
{
    cout << "Es un " << casillero_nombre << ", es un casillero transitable" << endl;
    if (material)
        cout << "Hay un material del tipo '" << material->obtener_nombre() << "'. No te olvides de recolectarlo!" << endl;
    else
        cout << "No hay ningun material en esta parte del camino :)" << endl;
}

void CasilleroTransitable::mostrar_por_pantalla()
{
    if (!material)
        cout << TXT_BLACK_16 << TXT_UNDERLINE << color << "   " << END_COLOR << " ";
    else
        cout << TXT_BLACK_16 << TXT_UNDERLINE << color << " " << material->obtener_codigo() << " " << END_COLOR << " ";
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

void CasilleroTransitable ::quitar_elemento()
{
    delete material;
    material = NULL;
}

bool CasilleroTransitable ::estransitable()
{
    return true;
}
