#include <string>
#include <iostream>

#include "constructorO.hpp"

using namespace std;

ConstructorO::ConstructorO(string objetivo, string tipo) : Objetivo(objetivo, tipo)
{
}

ConstructorO::~ConstructorO()
{
}

bool ConstructorO::chequear_estado(Lista<Ubicaciones> & edificios){
    bool aux = false;
    
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

    if( mina_chequeado && aserradero_chequeado && fabrica_chequeado &&
        escuela_chequeado && planta_electrica_chequeado && mina_oro_chequeado)
            aux = true;
    
    return aux;
}