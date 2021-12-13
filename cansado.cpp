#include <string>
#include <iostream>

#include "cansado.hpp"

using namespace std;

Cansado::Cansado() : Objetivo()
{
    progreso = 0;
}

Cansado::~Cansado()
{
}

void Cansado::chequear_estado(Inventario & inventario, int puntos_energia, Lista<Ubicaciones> & edificios, Constructor & bob, bool fin_turno)
{  
    progreso = puntos_energia;
    if(fin_turno)
        if(progreso == CANTIDAD_MIN_ENERGIA)
            objetivo_cumplido = true;
}

void Cansado::mostrar_objetivo(){
    msjeInstruccion("Cansado: terminar un turno con 0 de energía.");
    cout << TXT_LIGHT_BLUE_6 << "En este turno todavia posee " << progreso << " puntos de energia." << END_COLOR << endl;

    if(objetivo_cumplido)
        msjeInstruccion("El objetivo esta cumplido.");
    else
        msjeInstruccion("El objetivo no esta cumplido.");
}

bool Cansado::es_principal(){
    return false;
}
