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
    msjeInstruccion("Minero: haber construido una mina de cada tipo. ");
    cout << TXT_LIGHT_BLUE_6 << "Hasta el momento construyo al menos: " << END_COLOR;
    if(mina_chequeado)
        cout << TXT_LIGHT_BLUE_6 << "Una mina" << END_COLOR << endl;
    if(mina_oro_chequeado)
        cout << TXT_LIGHT_BLUE_6 << "Una mina Oro" << END_COLOR << endl;
   /*PONER LISTA*/  
    if(objetivo_cumplido)
        msjeInstruccion("El objetivo esta cumplido.");
    else
        msjeInstruccion("El objetivo no esta cumplido.");
}

bool Minero::es_principal(){
    return false;
}

