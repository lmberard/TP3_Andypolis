#ifndef CONSTRUCTOR_O_HPP
#define CONSTRUCTOR_O_HPP
#include <iostream>
#include <string>

/*
#include "colors.hpp"
#include "lista.hpp"
#include "ciudad.hpp"
#include "ubicaciones.hpp"
#include "constructor.hpp"
#include "inventario.hpp"
#include "recurso.hpp"
#include "terreno.hpp"*/
#include "objetivo.hpp"

class ConstructorO : public Objetivo
{
private:

    bool mina_chequeado;
    bool aserradero_chequeado;
    bool fabrica_chequeado;
    bool escuela_chequeado;
    bool planta_electrica_chequeado;
    bool mina_oro_chequeado;
    
public:
    ConstructorO();
    ~ConstructorO();

    void chequear_estado(Inventario & inventario, int puntos_energia, Lista<Ubicaciones> & edificios, Constructor & bob, bool fin_turno);
    void mostrar_objetivo();
    bool es_principal();
};



#endif 
