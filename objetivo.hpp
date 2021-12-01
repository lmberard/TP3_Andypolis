#ifndef OBJETIVO_HPP
#define OBJETIVO_HPP

#include "lista.hpp"
#include "ubicaciones.hpp"
#include "constructor.hpp"
#include "inventario.hpp"

static const string OBJETIVO_PRINCIPAL = "principal";
static const string OBJETIVO_SECUNDARIO = "secundario";

class Objetivo
{
protected:
    string objetivo;
    string tipo;
    bool objetivo_cumplido;

public:

    Objetivo();
    Objetivo(string objetivo, string tipo);
    ~Objetivo();

    string obtener_objetivo() const;
    bool es_principal();

    virtual bool chequear_estado(Inventario & inventario);
    virtual bool chequear_estado(int puntos_energia);
    //virtual bool chequear_estado(Diccionario & diccionario, Lista<Ubicaciones> edificios); /*esto para objetivo Letrado*/
    virtual bool chequear_estado(Lista<Ubicaciones> & edificios);
};


#endif 