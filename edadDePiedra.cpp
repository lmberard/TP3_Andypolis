#include <string>
#include <iostream>

#include "edadDePiedra.hpp"

using namespace std;

EdadDePiedra::EdadDePiedra() : Objetivo()
{
    progreso = 0;
}

EdadDePiedra::~EdadDePiedra()
{
}

void EdadDePiedra::chequear_estado(Inventario &inventario, int puntos_energia, Lista<Ubicaciones> &edificios, Constructor &bob, bool fin_turno)
{
    progreso = inventario.obtener_material("piedra")->obtener_cantidad();
    if (progreso >= CANTIDAD_PIEDRA_OBJETIVO)
        objetivo_cumplido = true;
}

void EdadDePiedra::mostrar_objetivo()
{
    msjeTitulo("* Edad de Piedra: tener en el inventario 50000 piedras");
    cout << TXT_LIGHT_BLUE_6 << "\tPosee " << progreso << " piedras en el inventario" << END_COLOR << endl;
    if (objetivo_cumplido)
        msjeOK("\tEl objetivo esta cumplido\n");
    else
        msjeError("\tEl objetivo no esta cumplido\n");
}

bool EdadDePiedra::es_principal()
{
    return false;
}
