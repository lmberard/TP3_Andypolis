#ifndef JUEGO_HPP
#define JUEGO_HPP
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
#include "jugador.hpp"
#include "mapa.hpp"
#include "funciones.hpp"
#include "edificio.hpp"

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
class Juego
{
private:
    Superficie superficie;
    Constructor bob;
    Recurso recurso;

    Mapa mapa;
    //Lista<Coordenada> coordenadasTransitables; //ESTO VA EN MAPA O ACA? LO USAMOS?
    // tb hay materiales sueltos, donde los guardamos?
    //Lista<Coordenada> materiales;
    //Lista<Ubicaciones> materiales;

    int id_jugador_actual;
    /* esto se setea al principio de cada partida. lo que hace es que todas las 
    funciones trabajen con ese jugador, es decir jugadores[id_jugador_actual -1]*/
    Jugador jugadores[CANT_JUGADORES];

public:
    //--------------------CONSTRUCTORES DESTRUCTORES-------------------
    Juego();
    ~Juego();

    //--------------------------GETTERS--------------------------------
    int obtener_filas_mapa();
    int obtener_columnas_mapa();
    Jugador& obtener_jugador_1(); //YO
    Jugador& obtener_jugador_2(); //YO
    Jugador* obtener_jugador(); // YO 
    int obtener_cant_construidos(string nombre_edificio);
    int obtener_id_jugador_actual();
    //--------------------------SETTERS--------------------------------
    void setear_coordenada_jugador(int id_jugador);
    void setear_id_jugador_actual(int id_jugador);

    //---------------------MAPA PARSER---------------------------------
    void crear_mapa(int filas, int columnas);
    void agregar_casillero(Coordenada coord, string casillero);
    //TODO: Revisar nombre y metodo
    void agregar_material_coordenada_lista(string nombre, Coordenada coord); //YO 
    void agregar_material_coordenada(string nombre, Coordenada coord);
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