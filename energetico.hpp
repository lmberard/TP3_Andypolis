#ifndef ENERGETICO_HPP
#define ENERGETICO_HPP
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

class Energetico : public Objetivo
{
private:


public:
    Energetico(string objetivo, string tipo);
    ~Energetico();
};



#endif 