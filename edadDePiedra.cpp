#include <string>
#include <iostream>

#include "edadDePiedra.hpp"

using namespace std;

EdadDePiedra::EdadDePiedra() : Objetivo()
{
}

EdadDePiedra::~EdadDePiedra()
{
}

bool EdadDePiedra::chequear_estado(Inventario & inventario, int puntos_energia, Lista<Ubicaciones> & edificios, Constructor & bob, bool fin_turno){
    bool aux = false;

    if(inventario.obtener_material("piedra")->obtener_cantidad() >= CANTIDAD_PIEDRA_OBJETIVO){
        aux = true;
        objetivo_cumplido = true;
    }
        
    return aux;
}

void EdadDePiedra::obtener_objetivo(){
    cout << "Edad de Piedra: tener en el inventario 50000 piedras" << endl;
    //cout << '\t' << "tenes " << inventario.obtener_material("piedra")->obtener_cantidad() << " piedras" << endl;
    if(objetivo_cumplido)
        cout << "el objetivo está cumplido" << endl;
    else
        cout << "el objetivo no está cumplido" << endl;
}

bool EdadDePiedra::es_principal(){
    return false;
}

