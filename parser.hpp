#ifndef PARSER_H
#define PARSER_H

#include <fstream>
<<<<<<< HEAD
#include <cstdlib>
#include <iomanip>
#include <cctype>
#include "colors.hpp"
#include "lista.hpp"
#include "ubicaciones.hpp"
=======

>>>>>>> marian
#include "constructor.hpp"
#include "recurso.hpp"
<<<<<<< HEAD
#include "terreno.hpp"
#include "juego.hpp"
=======
#include "superficie.hpp"

#include "mapa.hpp"
#include "jugador.hpp"
>>>>>>> marian

const string PATH_MAPA = "mapa.txt";
const string PATH_UBICACIONES = "ubicaciones.txt";
const string PATH_EDIFICIOS = "edificios.txt";
const string PATH_MATERIALES = "materiales.txt";

class Parser
{
public:
    /*---------------------------LECTURA--------------------------*/
    // PRE:
    // POS: Se carga la informacion de materiales.txt en ambos jugadores
    void cargar_inventario(Recurso &recurso, Juego &juego);

    // PRE:
    // POS: Se carga la informacion de edificios.txt
    void cargar_edificios(Constructor &bob);

    // PRE:
    // POS: Se carga la informacion de ubicaciones.txt
    void cargar_ubicaciones(Juego &juego);

    // PRE:
    // POS: Se carga la informacion de mapa.txt
    void cargar_mapa(Juego &juego);

    /*---------------------------GUARDADO--------------------------*/
    // PRE:
    // POS:
    // void guardar_archivos(Lista<Ubicacion> edificios, Inventario &inventario);

    // PRE:
    // POS:
    // bool guardar_ubicaciones(Lista<Ubicacion> edificios);

    // PRE:
    // POS:
    // bool guardar_inventario(Inventario &inventario);

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