#ifndef ARMADO_HPP
#define ARMADO_HPP
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

class Armado : public Objetivo
{
private:


public:
    Armado(string objetivo, string tipo);
    ~Armado();
};



#endif 