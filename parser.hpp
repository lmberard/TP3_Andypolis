#ifndef PARSER_H
#define PARSER_H

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