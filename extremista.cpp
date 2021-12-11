#include <string>
#include <iostream>

#include "extremista.hpp"

using namespace std;

Extremista::Extremista() : Objetivo()
{
    progreso = 0;
}

Extremista::~Extremista()
{
}

void Extremista::chequear_estado(Inventario & inventario, int puntos_energia, Lista<Ubicaciones> & edificios, Constructor & bob, bool fin_turno)
{
    progreso = inventario.obtener_bombas_compradas();
    if( progreso >= CANTIDAD_BOMBAS_COMPRADAS_OBJETIVO)
        objetivo_cumplido = true;

}

void Extremista::obtener_objetivo(){
    cout << "Extremista: haber comprado 500 bombas en una partida." << endl;
    cout << '\t' << "compraste " << progreso << " bombas" << endl;
    if(objetivo_cumplido)
        cout << "el objetivo está cumplido" << endl;
    else
        cout << "el objetivo no está cumplido" << endl;
}

bool Extremista::es_principal(){
    return false;
}
