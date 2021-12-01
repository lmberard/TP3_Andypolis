#ifndef EDAD_DE_PIEDRA_HPP
#define EDAD_DE_PIEDRA_HPP

#include "objetivo.hpp"

static const int CANTIDAD_PIEDRA_OBJETIVO = 50000;


class EdadDePiedra : public Objetivo
{
private:


public:
    EdadDePiedra(string objetivo, string tipo);
    ~EdadDePiedra();

   bool chequear_estado(Inventario & inventario);
};



#endif 