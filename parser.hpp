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
    // PRE:
    // POS: Se carga la informacion de edificios.txt
    void cargar(Constructor &bob);


    // POS:
    bool existe_archivo(const string & PATH);

  
    // POS:
    void crear_archivo_vacio(const string &PATH, fstream &archivo);
};

#endif // PARSER_HPP