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


public:
    ConstructorO();
    ~ConstructorO();

    bool chequear_estado(Inventario & inventario, int puntos_energia, Lista<Ubicaciones> & edificios, Constructor & bob, bool fin_turno);
    string obtener_objetivo();
    bool es_principal();
};



#endif 
