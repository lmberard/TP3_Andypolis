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

    int progreso;

public:
    Letrado();
    ~Letrado();

    void chequear_estado(Inventario & inventario, int puntos_energia, Lista<Ubicaciones> & edificios, Constructor & bob, bool fin_turno);
    void mostrar_objetivo();
    bool es_principal();
};



#endif 
