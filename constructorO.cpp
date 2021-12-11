#include <string>
#include <iostream>

#include "constructorO.hpp"

using namespace std;

ConstructorO::ConstructorO() : Objetivo()
{
    progreso = 0;
}

ConstructorO::~ConstructorO()
{
}

void ConstructorO::chequear_estado(Inventario & inventario, int puntos_energia, Lista<Ubicaciones> & edificios, Constructor & bob, bool fin_turno)
{
    bool mina_chequeado = false;
    bool aserradero_chequeado = false;
    bool fabrica_chequeado = false;
    bool escuela_chequeado = false;
    bool planta_electrica_chequeado = false;
    bool mina_oro_chequeado = false;

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

void ConstructorO::obtener_objetivo(){
   cout << "Constructor: construir un edificio de cada tipo." << endl;
   cout << "Por ahora construistes: " << endl;
   /*PONER LISTA*/  
   if(objetivo_cumplido)
        cout << "el objetivo está cumplido" << endl;
    else
        cout << "el objetivo no está cumplido" << endl;
}

bool ConstructorO::es_principal(){
    return false;
}

