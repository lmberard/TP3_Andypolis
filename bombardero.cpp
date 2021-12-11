#include <string>
#include <iostream>

#include "bombardero.hpp"

using namespace std;

Bombardero::Bombardero() : Objetivo()
{
}

Bombardero::~Bombardero()
{
}

bool Bombardero::chequear_estado(Inventario & inventario, int puntos_energia, Lista<Ubicaciones> & edificios, Constructor & bob, bool fin_turno){
    bool aux = false;

    if(inventario.obtener_bombas_usadas() >= CANTIDAD_BOMBAS_USADAS_OBJETIVO){
        aux = true;
        objetivo_cumplido = true;
    }

    return aux;
}

void Bombardero::obtener_objetivo(){
    cout << "Bombardero: haber usado 5 bombas" << endl;
    //cout << '\t' << "usastes " << inventario.obtener_bombas_usadas() << " bombas" << endl;
    if(objetivo_cumplido)
        cout << "el objetivo está cumplido" << endl;
    else
        cout << "el objetivo no está cumplido" << endl;
}

bool Bombardero::es_principal(){
    return false;
}
