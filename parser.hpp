#ifndef PARSER_H
#define PARSER_H
#include <iostream>
#include <string>
#include <algorithm>
#include <fstream>
#include <cstdlib>
#include <iomanip>
#include <cctype>
#include "colors.hpp"
#include "lista.hpp"
#include "ciudad.hpp"
#include "ubicaciones.hpp"
#include "constructor.hpp"
#include "inventario.hpp"
#include "recurso.hpp"
#include "terreno.hpp"

const string PATH_MAPA = "mapa.txt";
const string PATH_UBICACIONES = "ubicaciones.txt";
const string PATH_EDIFICIOS = "edificios.txt";
const string PATH_MATERIALES = "materiales.txt";

class Parser
{
public:
    /*---------------------------LECTURA--------------------------*/
    // PRE:
    // POS: Se carga la informacion de materiales.txt
    void cargar_inventario(Inventario &inventario, Recurso &recurso);

    // PRE:
    // POS: Se carga la informacion de edificios.txt
    void cargar_edificios(Constructor &bob);

    // PRE:
    // POS: Se carga la informacion de ubicaciones.txt
    //void cargar_ubicaciones(Ciudad &ciudad);

    // PRE:
    // POS: Se carga la informacion de mapa.txt
    //void cargar_mapa(Ciudad &ciudad, Terreno &terreno);

    /*---------------------------GUARDADO--------------------------*/
    // PRE:
    // POS:
    void guardar_archivos(Lista<Ubicacion> edificios, Inventario &inventario);

    // PRE:
    // POS:
    bool guardar_ubicaciones(Lista<Ubicacion> edificios);

    // PRE:
    // POS:
    bool guardar_inventario(Inventario &inventario);

    /*----------------------------EXTRAS----------------------------*/
    // PRE:
    // POS:
    bool existe_archivo_ubicaciones();

    // PRE:
    // POS:
    bool existe_archivo_mapa();

    // PRE:
    // POS:
    bool existe_archivo_edificios();

    // PRE:
    // POS:
    bool existe_archivo_materiales();

    // PRE:
    // POS:
    void crear_archivo_vacio(const string &PATH, fstream &archivo);
};

#endif // PARSER_HPP
