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
//#include "juego.hpp"
#include "mapa.hpp"
#include "jugador.hpp"

const string PATH_MAPA = "mapa.txt";
const string PATH_UBICACIONES = "ubicaciones.txt";
const string PATH_EDIFICIOS = "edificios.txt";
const string PATH_MATERIALES = "materiales.txt";

/*CAMBIOS EN PARSER*/
/*
-LOS MÉTODOS QUE CHEQUEAN SI EXISTE EL ARCHIVO AHORA ES UNO SOLO, NO HAY UN MÉTODO 
INDIVIDUAL PARA CHEQUEAR SI EXISTE EL ARCHIVO DE MATERIALES, OTRO PARA VER SI EXISTE EL ARCHIVO
DE EDIFICIOS ETC. 

-A LOS METODOS EXTRA LOS PUSE EN PRIVATE YA QUE SIRVEN PARA EL FUNCIONAMIENTO INTERNO DE LA CLASE

-UBICACIONES.TXT TIENE UN FLAG AHORA PARA SETEAR EL ESTADO DE LA PARTIDA, SI EMPEZADO O NO 

-CARGAR MAPA LLAMA A CARGAR UBICACIONES, YA QUE ESTOS DOS METODOS VAN EN CONJUNTO
*/

class Parser
{
public:
    /*---------------------------LECTURA--------------------------*/
    // PRE:
    // POS: Se carga la informacion de materiales.txt en ambos jugadores
    void cargar(Recurso &recurso, Jugador &jugador1, Jugador &jugador2);

    // PRE:
    // POS: Se carga la informacion de edificios.txt
    void cargar(Constructor &bob);

    // PRE:
    // POS: Se carga la informacion de ubicaciones.txt
    void cargar_ubicaciones(Mapa & mapa, Jugador & jugador1, Jugador & jugador2);

    // PRE:
    // POS: Se carga la informacion de mapa.txt
    void cargar(Superficie & superficie,Mapa & mapa);

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

private:
    /*----------------------------EXTRAS----------------------------*/

    //PRE:
    //POS:
    bool existe_archivo(const string & PATH);

    // PRE:
    // POS:
    void crear_archivo_vacio(const string &PATH, fstream &archivo);

};

#endif // PARSER_HPP