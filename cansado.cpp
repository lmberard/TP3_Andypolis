#include <string>
#include <iostream>

#include "cansado.hpp"

using namespace std;

Cansado::Cansado() : Objetivo()
{
}

Cansado::~Cansado()
{
}

bool Cansado::chequear_estado(Inventario & inventario, int puntos_energia, Lista<Ubicaciones> & edificios, Constructor & bob, bool fin_turno){
    
    bool aux = false;
    
    if(fin_turno)
        if(puntos_energia == CANTIDAD_MIN_ENERGIA){
            aux = true;
            objetivo_cumplido = true;
        }

    return aux;
}

void Cansado::obtener_objetivo(){
    cout << "Cansado: terminar un turno con 0 de energía" << endl;
    //cout << '\t' << "en este turno todavía tenes " << puntos_energia << " puntos de energia" << endl;
    cout << '\t' << "gastalos en algo y listo" << endl;
    if(objetivo_cumplido)
        cout << "el objetivo está cumplido" << endl;
    else
        cout << "el objetivo no está cumplido" << endl;
}

bool Cansado::es_principal(){
    return false;
}
