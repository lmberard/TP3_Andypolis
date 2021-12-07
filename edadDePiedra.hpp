#ifndef EDAD_DE_PIEDRA_HPP
#define EDAD_DE_PIEDRA_HPP
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

static const int CANTIDAD_PIEDRA_OBJETIVO = 50000;


class EdadDePiedra : public Objetivo
{
private:


public:
    EdadDePiedra();
    ~EdadDePiedra();

   bool chequear_estado(Inventario & inventario, int puntos_energia, Lista<Ubicaciones> & edificios);
   string obtener_objetivo();
   bool es_principal();
};



#endif 
