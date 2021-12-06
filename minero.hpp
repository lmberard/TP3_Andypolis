#ifndef MINERO_HPP
#define MINERO_HPP
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

class Minero : public Objetivo
{
private:


public:
    Minero();
    ~Minero();

    bool chequear_estado(Lista<Ubicaciones> & edificios);
    string obtener_objetivo();
    bool es_principal();
};



#endif 
