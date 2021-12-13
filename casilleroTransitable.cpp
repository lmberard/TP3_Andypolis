#include "casilleroTransitable.hpp"

CasilleroTransitable ::CasilleroTransitable() : Casillero()
{
    material = NULL;
}

CasilleroTransitable ::~CasilleroTransitable(){}

void CasilleroTransitable::info()
{
    cout << TXT_LIGHT_BLUE_6 << "Es un " << casillero_nombre << ", es un casillero transitable" << END_COLOR << endl;
    if (material)
        cout << TXT_LIGHT_BLUE_6 << "Hay un material del tipo '" << material->obtener_nombre() << "'. La cantidad es: " <<
        material->obtener_cantidad() << ". No se olvide de recolectarlo!" << END_COLOR << endl;
    if (jugador)
        cout << TXT_LIGHT_BLUE_6 << "En este casillero se encuentra el jugador " << jugador->obtener_codigo() << END_COLOR << endl;
    if(!material && !jugador)
        cout << TXT_LIGHT_BLUE_6 << "No hay ningun material en esta parte del camino." << END_COLOR << endl;
}

void CasilleroTransitable::mostrar_por_pantalla()
{
    if (!material && !jugador)
        cout << TXT_BLACK_16 << TXT_UNDERLINE << color << "   " << END_COLOR << " ";
    if(material)
        cout << TXT_BLACK_16 << TXT_UNDERLINE << color << " " << material->obtener_codigo() << " " << END_COLOR << " ";
    if(jugador)
        cout << TXT_BLACK_16 << TXT_UNDERLINE << color << " " << jugador->obtener_codigo() << " " << END_COLOR << " ";
}

bool CasilleroTransitable::agregar(Material *material)
{
    if (this->material)
    {
        msjeError("Ya hay un material en este casillero, no hay lugar para agregar otro :(");
        return false;
    }
    this->material = material;
    return true;
}

bool CasilleroTransitable::agregar(Jugador *jugador)
{
    if (material || this->jugador)
    {
        msjeError("Este casillero ya esta ocupado");
        return false;
    }

    this->jugador = jugador;
    return true;
}

bool CasilleroTransitable::mover_jugador(Jugador *jugador)
{
    if (this->jugador)
    {
        msjeError("Este casillero ya esta ocupado");
        return false;
    }

    this->jugador = jugador;
    return true;
}


void CasilleroTransitable::quitar_elemento()
{
    delete material;
    material = NULL;
}

bool CasilleroTransitable::estransitable()
{
    return true;
}

int CasilleroTransitable::obtener_peso(int jugador_id){
    int peso;

    if(casillero_nombre == "camino"){
        if(jugador_id == 1 || jugador_id == 2) // para ambos jugadores el peso de un camino es el mismo
            peso = 4;
    }
    else if(casillero_nombre == "betun"){
        if(jugador_id == 1 || jugador_id == 2) // para ambos jugadores el peso de un camino es el mismo
            peso = 0;
    }
    else if(casillero_nombre == "muelle"){
        if(jugador_id == 1)
            peso = 5;
        else if(jugador_id == 2)
            peso = 2;
    }

    return peso;
}

Material * CasilleroTransitable::recolectar_material(){
    return material;
}
