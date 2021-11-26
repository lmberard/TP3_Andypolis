#ifndef EXTREMISTA_HPP
#define EXTREMISTA_HPP
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

class Extremista : public Objetivo
{
private:


public:
    Extremista(string objetivo, string tipo);
    ~Extremista();
};



#endif 