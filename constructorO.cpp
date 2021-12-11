#include <string>
#include <iostream>

#include "constructorO.hpp"

using namespace std;

ConstructorO::ConstructorO() : Objetivo()
{
    mina_chequeado = false;
    aserradero_chequeado = false;
    fabrica_chequeado = false;
    escuela_chequeado = false;
    planta_electrica_chequeado = false;
    mina_oro_chequeado = false;
}

ConstructorO::~ConstructorO()
{
}

void ConstructorO::chequear_estado(Inventario & inventario, int puntos_energia, Lista<Ubicaciones> & edificios, Constructor & bob, bool fin_turno)
{
    for(int i = 1; i < edificios.mostrar_cantidad() + 1; i++){
        if( obtener_nombre(edificios[i]) == "mina")
            mina_chequeado = true;
        if( obtener_nombre(edificios[i]) == "aserradero" )
            aserradero_chequeado = true;
        if( obtener_nombre(edificios[i]) == "fabrica")
            fabrica_chequeado = true;
        if( obtener_nombre(edificios[i]) == "escuela")
            escuela_chequeado = true;
        if( obtener_nombre(edificios[i]) == "planta electrica")
            planta_electrica_chequeado = true;
        if( obtener_nombre(edificios[i]) == "mina oro")
            mina_oro_chequeado = true;            
    }

    if(mina_chequeado && aserradero_chequeado && fabrica_chequeado &&
        escuela_chequeado && planta_electrica_chequeado && mina_oro_chequeado)
            objetivo_cumplido = true;

}

void ConstructorO::mostrar_objetivo(){
   cout << "Constructor: construir un edificio de cada tipo." << endl;
   cout << "Por ahora construistes: " << endl;
    if(mina_chequeado)
        cout << "una mina" << endl; 
    if(aserradero_chequeado)
        cout << "un aserradero" << endl; 
    if(fabrica_chequeado)
        cout << "una fabrica" << endl;
    if(escuela_chequeado)
        cout << "una escuela" << endl;
    if(planta_electrica_chequeado)
        cout << "una planta electrica" << endl;
    if(mina_oro_chequeado)
        cout << "una mina oro" << endl;   

   if(objetivo_cumplido)
        cout << "el objetivo está cumplido" << endl;
    else
        cout << "el objetivo no está cumplido" << endl;
}

bool ConstructorO::es_principal(){
    return false;
}

