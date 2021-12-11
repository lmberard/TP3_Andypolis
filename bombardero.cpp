#include <string>
#include <iostream>

#include "bombardero.hpp"

using namespace std;

Bombardero::Bombardero() : Objetivo()
{
    progreso = 0;
}

Bombardero::~Bombardero()
{
}

void Bombardero::chequear_estado(Inventario & inventario, int puntos_energia, Lista<Ubicaciones> & edificios, Constructor & bob, bool fin_turno)
{
    progreso = inventario.obtener_bombas_usadas();
    if(progreso >= CANTIDAD_BOMBAS_USADAS_OBJETIVO)
        objetivo_cumplido = true;
}

void Bombardero::obtener_objetivo(){
    cout << "Bombardero: haber usado 5 bombas" << endl;
    cout << '\t' << "usastes " << progreso << " bombas" << endl;
    if(objetivo_cumplido)
        cout << "el objetivo está cumplido" << endl;
    else
        cout << "el objetivo no está cumplido" << endl;
}

bool Bombardero::es_principal(){
    return false;
}
