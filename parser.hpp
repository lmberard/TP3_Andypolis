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
#include "superficie.hpp"

const string PATH_MAPA = "mapa.txt";
const string PATH_UBICACIONES = "ubicaciones.txt";
const string PATH_EDIFICIOS = "edificios.txt";
const string PATH_MATERIALES = "materiales.txt";

class Parser
{
public:
    bool existe_archivo_ubicaciones();

    bool existe_archivo_mapa();

    bool existe_archivo_edificios();

    bool existe_archivo_materiales();

    void crear_archivo_vacio(const string &PATH, fstream &archivo);

    //para cargar materiales.txt
    void cargar_inventario(Inventario &inventario, Recurso &recurso);

    //para cargar edificios.txt
    void cargar_edificios(Constructor &bob);

    //para cargar las ubicaciones.txt
    //void cargar_ubicaciones(Ciudad &ciudad);

    //para cargar mapa.txt
    //void cargar_mapa(Ciudad &ciudad, Terreno &terreno);
};

#endif // PARSER_HPP
