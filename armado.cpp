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
    msjeInstruccion("Armado: tener 10 bombas en el inventario.");
    cout << TXT_LIGHT_BLUE_6 << '\t' << "Posee " << progreso << " bombas." << END_COLOR << endl;
    if(objetivo_cumplido)
        msjeInstruccion("El objetivo esta cumplido.");
    else
        msjeInstruccion("El objetivo no esta cumplido.");
}

bool Armado::es_principal(){
    return false;
}

