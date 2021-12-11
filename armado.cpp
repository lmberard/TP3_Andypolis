#include <string>
#include <iostream>

#include "armado.hpp"

using namespace std;

Armado::Armado() : Objetivo()
{
}

Armado::~Armado()
{
}

bool Armado::chequear_estado(Inventario & inventario, int puntos_energia, Lista<Ubicaciones> & edificios, Constructor & bob, bool fin_turno){
    bool aux = false;

    if(inventario.obtener_material("bomba")->obtener_cantidad() >= CANTIDAD_BOMBAS_INVENTARIO_OBJETIVO){
        aux = true;
        objetivo_cumplido = true;
    }
    else 
        objetivo_cumplido = false;
        
    return aux;
}

void Armado::obtener_objetivo(){
    cout << "Armado:  tener 10 bombas en el inventario." << endl;
    //cout << '\t' << "tenes " << inventario.obtener_material("bomba")->obtener_cantidad() << " bombas" << endl;
    if(objetivo_cumplido)
        cout << "el objetivo está cumplido" << endl;
    else
        cout << "el objetivo no está cumplido" << endl;
}

bool Armado::es_principal(){
    return false;
}

