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
    void cargar(Recurso &recurso, Jugador*);

    // PRE:
    // POS: Se carga la informacion de edificios.txt
    void cargar(Constructor &bob);

    // PRE:
    // POS: Se carga la informacion de mapa.txt
    void cargar(Superficie & superficie,Mapa & mapa);

    // PRE:
    // POS: Se carga la informacion de ubicaciones.txt
    bool cargar_partida_guardada(Mapa & mapa, Jugador* jugador, Constructor & bob, Recurso & recurso);

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

    bool guardar_inventario(Jugador * jugadores);
    bool guardar(Constructor & bob);
    bool guardar_partida(Mapa & mapa,Jugador * jugadores);

private:
    /*----------------------------EXTRAS----------------------------*/

    //PRE:
    //POS:
    bool existe_archivo(const string & PATH);

    // PRE:
    // POS:
    void crear_archivo_vacio(const string &PATH, fstream &archivo);

    bool no_numero(string & aux);

    Coordenada obtener_coordenada(fstream & archivo_ubicaciones);

    void cargar_materiales(fstream & archivo_ubicaciones, Recurso & recurso, Mapa & mapa, string & aux);

    void cargar_edificios(fstream & archivo_ubicaciones, Jugador & jugador, Mapa & mapa, Constructor & bob, string & aux);

    void cargar_posicion(fstream & archivo_ubicaciones,Jugador & jugador, string & aux);

};

#endif // PARSER_HPP