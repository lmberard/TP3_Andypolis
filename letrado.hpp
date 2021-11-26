#ifndef LETRADO_HPP
#define LETRADO_HPP
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

class Letrado : public Objetivo
{
private:


public:
    Letrado(string objetivo, string tipo);
    ~Letrado();
};



#endif 