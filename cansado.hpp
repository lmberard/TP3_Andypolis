#ifndef CANSADO_HPP
#define CANSADO_HPP
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

class Cansado : public Objetivo
{
private:


public:
    Cansado(string objetivo, string tipo);
    ~Cansado();
};



#endif 