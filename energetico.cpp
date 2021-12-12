#include <string>
#include <iostream>

#include "energetico.hpp"

using namespace std;

Energetico::Energetico() : Objetivo()
{
    progreso = 0;
}

Energetico::~Energetico()
{
}

void Energetico::chequear_estado(Inventario & inventario, int puntos_energia, Lista<Ubicaciones> & edificios, Constructor & bob, bool fin_turno)
{
    progreso = puntos_energia;
    if(fin_turno)
        if(puntos_energia == CANTIDAD_MAX_ENERGIA)
            objetivo_cumplido = true;
}

void Energetico::mostrar_objetivo(){
    msjeInstruccion("Energetico: haber terminado un turno con 100 puntos de energia.");
    cout << TXT_LIGHT_BLUE_6 << '\t' << "En este turno posee " << progreso << " puntos de energia" << END_COLOR << endl;
    if(objetivo_cumplido)
        msjeInstruccion("El objetivo esta cumplido");
    else
        msjeInstruccion("El objetivo no esta cumplido");
}

bool Energetico::es_principal(){
    return false;
}
