#ifndef PARSER_H
#define PARSER_H

#include <fstream>

#include "constructor.hpp"
#include "recurso.hpp"
#include "superficie.hpp"

#include "mapa.hpp"
#include "jugador.hpp"

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

    //PRE:
    //POS:
    bool guardar(Constructor & bob);

    //PRE:
    //POS:
    bool guardar_inventario(Jugador * jugador);

    //PRE:
    //POS:
    bool guardar_partida(Mapa & mapa,Jugador * jugador);

private:
    /*----------------------------EXTRAS----------------------------*/

    //PRE:
    //POS:
    bool existe_archivo(const string & PATH);

    // PRE:
    // POS:
    void crear_archivo_vacio(const string &PATH, fstream &archivo);

    //PRE:
    //POS:
    bool es_palabra(string & aux);

    //PRE:
    //POS:
    Coordenada obtener_coordenada(fstream &archivo_ubicaciones, string & aux_coordenada);

    //PRE:
    //POS:
    void cargar_materiales(fstream & archivo_ubicaciones, Recurso & recurso, Mapa & mapa, string & aux);

    //PRE:
    //POS:
    void cargar_edificios(fstream & archivo_ubicaciones, Jugador & jugador, Mapa & mapa, Constructor & bob, string & aux);

    //PRE:
    //POS:
    void cargar_posicion(fstream & archivo_ubicaciones,Jugador & jugador, Mapa & mapa, int i, string & aux);

    //PRE:
    //POS:
    void guardar_ubicaciones(Lista<Ubicaciones> & lista, ofstream & archivo_ubicaciones);

    //PRE:
    //POS:
    void guardar_ubicacion_jugador(Mapa & mapa, int i, ofstream & archivo_ubicaciones);

    //PRE:
    //POS:
    void guardar_coordenadas(Coordenada & coordenada, ofstream & archivo_ubicaciones);

};

#endif // PARSER_HPP