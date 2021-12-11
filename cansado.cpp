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

void Cansado::obtener_objetivo(){
    cout << "Cansado: terminar un turno con 0 de energía" << endl;
    cout << '\t' << "en este turno todavía tenes " << progreso << " puntos de energia" << endl;
    cout << '\t' << "gastalos en algo y listo" << endl;
    if(objetivo_cumplido)
        cout << "el objetivo está cumplido" << endl;
    else
        cout << "el objetivo no está cumplido" << endl;
}

bool Cansado::es_principal(){
    return false;
}
