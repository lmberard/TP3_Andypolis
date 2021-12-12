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

void Extremista::mostrar_objetivo(){
    msjeInstruccion("Extremista: haber comprado 500 bombas en una partida.");
    cout << TXT_LIGHT_BLUE_6 << '\t' << "Hasta el momento compro " << progreso << " bombas" << END_COLOR << endl;
    if(objetivo_cumplido)
        msjeInstruccion("El objetivo esta cumplido");
    else
        msjeInstruccion("El objetivo no esta cumplido");
}

bool Extremista::es_principal(){
    return false;
}
