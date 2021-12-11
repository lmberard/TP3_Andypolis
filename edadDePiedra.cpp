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

void EdadDePiedra::chequear_estado(Inventario & inventario, int puntos_energia, Lista<Ubicaciones> & edificios, Constructor & bob, bool fin_turno)
{
    progreso = inventario.obtener_material("piedra")->obtener_cantidad();
    if(progreso >= CANTIDAD_PIEDRA_OBJETIVO)
        objetivo_cumplido = true;
}

void EdadDePiedra::obtener_objetivo(){
    cout << "Edad de Piedra: tener en el inventario 50000 piedras" << endl;
    cout << '\t' << "tenes " << progreso << " piedras en el inventario" << endl;
    if(objetivo_cumplido)
        cout << "el objetivo está cumplido" << endl;
    else
        cout << "el objetivo no está cumplido" << endl;
}

bool EdadDePiedra::es_principal(){
    return false;
}

