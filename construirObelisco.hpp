#ifndef CONSTRUIR_OBELISCO_HPP
#define CONSTRUIR_OBELISCO_HPP
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

class ConstruirObelisco : public Objetivo
{
private:


public:
    ConstruirObelisco();
    ~ConstruirObelisco();
    void chequear_estado(Inventario & inventario, int puntos_energia, Lista<Ubicaciones> & edificios, Constructor & bob, bool fin_turno);

    void mostrar_objetivo();
    bool es_principal();
};



#endif 
