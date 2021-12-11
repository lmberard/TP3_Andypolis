#include <string>
#include <iostream>

#include "minero.hpp"
#include "ubicaciones.hpp"

using namespace std;

Minero::Minero() : Objetivo()
{
    mina_chequeado = false;
    mina_oro_chequeado = false;
}

Minero::~Minero()
{
}

void Minero::chequear_estado(Inventario & inventario, int puntos_energia, Lista<Ubicaciones> & edificios, Constructor & bob, bool fin_turno)
{


    for(int i = 1; i < edificios.mostrar_cantidad() + 1; i++){
        if( obtener_nombre(edificios[i]) == "mina")
            mina_chequeado = true;
        if( obtener_nombre(edificios[i]) == "mina oro" )
            mina_oro_chequeado = true;
    }

    if(mina_chequeado && mina_oro_chequeado)
        objetivo_cumplido = true;
}

void Minero::mostrar_objetivo(){
    cout << "Minero: haber construido una mina de cada tipo. " << endl;
    cout << "Por ahora construistes por lo menos: ";
    if(mina_chequeado)
        cout << "Una mina" << endl;
    if(mina_oro_chequeado)
        cout << "Una mina Oro" << endl;
   /*PONER LISTA*/  
   if(objetivo_cumplido)
        cout << "el objetivo está cumplido" << endl;
    else
        cout << "el objetivo no está cumplido" << endl;
}

bool Minero::es_principal(){
    return false;
}

