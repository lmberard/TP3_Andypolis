#include <string>
#include <iostream>

#include "minero.hpp"
#include "ubicaciones.hpp"

using namespace std;

Minero::Minero() : Objetivo()
{
}

Minero::~Minero()
{
}

bool Minero::chequear_estado(Lista<Ubicaciones> & edificios){
    bool aux = false;
    bool mina_chequeado = false;
    bool mina_oro_chequeado = false;

    for(int i = 1; i < edificios.mostrar_cantidad() + 1; i++){
        if( obtener_nombre(edificios[i]) == "mina")
            mina_chequeado = true;
        if( obtener_nombre(edificios[i]) == "mina oro" )
            mina_oro_chequeado = true;
    }

    if(mina_chequeado && mina_oro_chequeado)
        aux = true;
    
    return aux;
}
