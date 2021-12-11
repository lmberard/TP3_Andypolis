#include <string>
#include <iostream>

#include "armado.hpp"

using namespace std;

Armado::Armado() : Objetivo()
{
    progreso = 0;
}

Armado::~Armado()
{
}

void Armado::chequear_estado(Inventario & inventario, int puntos_energia, Lista<Ubicaciones> & edificios, Constructor & bob, bool fin_turno)
{
    progreso = inventario.obtener_material("bomba")->obtener_cantidad();
    if( progreso >= CANTIDAD_BOMBAS_INVENTARIO_OBJETIVO)
        objetivo_cumplido = true;
    else 
        objetivo_cumplido = false;
}

void Armado::mostrar_objetivo(){
    cout << "Armado:  tener 10 bombas en el inventario." << endl;
    cout << '\t' << "tenes " << progreso << " bombas" << endl;
    if(objetivo_cumplido)
        cout << "el objetivo está cumplido" << endl;
    else
        cout << "el objetivo no está cumplido" << endl;
}

bool Armado::es_principal(){
    return false;
}

