#ifndef JUEGO_HPP
#define JUEGO_HPP

#include "lista.hpp"
#include "ubicaciones.hpp"

#include "constructor.hpp"
#include "recurso.hpp"
#include "superficie.hpp"

#include "jugador.hpp"
#include "mapa.hpp"

#include "parser.hpp"

const int LLUVIA_METAL_MIN = 2;
const int LLUVIA_METAL_MAX = 4;
const int LLUVIA_MADERA_MIN = 0;
const int LLUVIA_MADERA_MAX = 2;
const int LLUVIA_PIEDRA_MIN = 1;
const int LLUVIA_PIEDRA_MAX = 2;

const int CANT_JUGADORES = 2;

const int CANT_ENERGIA_FIN_PARTIDA = 20;
const int CANT_ENERGIA_NUEVA_PARTIDA = 50;
const int CANT_ENERGIA_MAXIMA = 100;
const int CANT_ENERGIA_MINIMA = 0;

const int CANT_ENERGIA_CONSTRUIR = 15;
const int CANT_ENERGIA_LISTAR_EDIF = 0;
const int CANT_ENERGIA_DEMOLER = 15;
const int CANT_ENERGIA_ATACAR = 30;
const int CANT_ENERGIA_REPARAR = 25;
const int CANT_ENERGIA_COMPRAR_BOMBAS = 5;
const int CANT_ENERGIA_CONSULTAR = 0;
const int CANT_ENERGIA_MOSTRAR_OBJ = 0;
const int CANT_ENERGIA_MOSTRAR_INV = 0;
const int CANT_ENERGIA_RECOLECTAR = 20;

const int CANT_OBJETIVOS_SECUNDARIOS_JUGADOR = 3;

class Juego
{
private:

    /*El juego andypolis consta de casilleros (Superficie) dispuestos en un mapa (Mapa) que puede 
    tener edificios (Constructor) y materiales (Recursos), en donde 2 jugadores (Jugador) toman 
    decisiones (Jugada) para lograr sus objetivos (Objetivo) y ganar la partida  */

    //elementos del juego: casilleros, edificios y materiales
    Superficie superficie;
    Constructor bob;
    Recurso recurso;

    //mapa del juego
    Mapa mapa;
 
    //jugadores:
    Jugador jugadores[CANT_JUGADORES];

    //Objetivo:
    Objetivo *objetivo;

    //Jugada:
    //Jugada *jugada;

    //Gestor de archivos para cargar una partida del juego y sus elementos 
    Parser archivo;

    //Menú del juego
    //Menu menu;

    //Estado del juego, quien esta jugando ahora mismo y si la partida es nueva o no
    int id_jugador_actual;
    bool partida_nueva = true; 

public:
    //--------------------CONSTRUCTORES DESTRUCTORES-------------------
    Juego();
    ~Juego();

    //--------------------------GETTERS--------------------------------

    //int obtener_cant_construidos(string nombre_edificio);
    int obtener_id_jugador_actual();
    bool es_partida_nueva();
    //--------------------------SETTERS--------------------------------
    void setear_coordenada_jugador(int id_jugador);
    void setear_id_jugador_actual(int id_jugador);
    //---------------------MAPA PARSER---------------------------------
  
    //TODO: Revisar nombre y metodo

    void construir_edificio(Coordenada coord, const string &edificio); //falta detalles

    //-------------------OPCIONES MENU PRINCIPAL-----------------------
    void modificar_edificio_por_nombre(); //falta (diccionario)
    void mostrar_todos_edificios();
    void mostrar_mapa();
    bool comenzar_partida(); //falta detalles

    //-----------------------OPCIONES JUEGO----------------------------
    void construir_por_nombre_coordenada();
    void mostrar_edificios_construidos();
    void demoler_por_coordenada();
    void atacar_por_coordenada();  //FALTAA
    void reparar_por_coordenada(); //FALTAA
    void comprar_bombas();
    void consultar_coordenada();
    void mostrar_objetivos();
    void mostrar_inventario();
    void recolectar();           //FALTAA
    void moverse_a_coordenada(); //falta pero en jugador (camino minimo)
    void finalizar_turno();      //FALTAA

    void lluvia();          //FALTAA
    bool gano_el_juego();   //FALTAA
    void cambiar_jugador(); //arreglar

    //-----------------------FUNCIONES UTILES--------------------------
    bool id_jugador_es_valido(int id_jugador);
    bool chequear_permisos_edificio(const string &eledificio);
    bool jugador_tiene_energia(const int cantidad);

    Coordenada pedir_coordenadas();
    string pedir_nombre_edificio();
    int pedir_id_jugador();

    void demoler_edificio(Coordenada coord);

};
#endif //JUEGO_HPP