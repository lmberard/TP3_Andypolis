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
    cout << "Energetico: haber terminado un turno con 100 puntos de energía." << endl;
    cout << '\t' << "en este turno tenes " << progreso << " puntos de energia" << endl;
    if(objetivo_cumplido)
        cout << "el objetivo está cumplido" << endl;
    else
        cout << "el objetivo no está cumplido" << endl;
}

bool Energetico::es_principal(){
    return false;
}
