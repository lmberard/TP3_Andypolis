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
    Minero(string objetivo, string tipo);
    ~Minero();

    bool chequear_estado(Lista<Ubicaciones> & edificios);
};



#endif 
