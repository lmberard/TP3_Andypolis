#include <string>
#include <iostream>

#include "extremista.hpp"

using namespace std;

Extremista::Extremista() : Objetivo()
{
}

Extremista::~Extremista()
{
}

bool Extremista::chequear_estado(Inventario & inventario, int puntos_energia, Lista<Ubicaciones> & edificios, Constructor & bob, bool fin_turno){
    bool aux = false;

    if(inventario.obtener_bombas_compradas() >= CANTIDAD_BOMBAS_COMPRADAS_OBJETIVO){
        aux = true;
        objetivo_cumplido = true;
    }

    return aux;
}

void Extremista::obtener_objetivo(){
    cout << "Extremista: haber comprado 500 bombas en una partida." << endl;
    //cout << '\t' << "compraste " << inventario.obtener_material("bomba")->obtener_cantidad() << " bombas" << endl;
    if(objetivo_cumplido)
        cout << "el objetivo está cumplido" << endl;
    else
        cout << "el objetivo no está cumplido" << endl;
}

bool Extremista::es_principal(){
    return false;
}
