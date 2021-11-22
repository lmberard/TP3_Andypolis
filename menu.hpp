#ifndef MENU_H
#define MENU_H
#include <iostream>
#include <string>
#include <algorithm>
#include <fstream>
#include <cstdlib>
#include <iomanip>
#include <cctype>
#include "colors.hpp"
#include "lista.hpp"
#include "juego.hpp"

const int OPCION_MINIMA = 1;
const int OPCION_MAXIMA_NUEVA_PARTIDA = 5;
const int OPCION_MAXIMA_JUEGO = 13;

const int MODIFICAR_EDIFICIO_POR_NOMBRE = 1;
const int LISTAR_TODOS_EDIFICIOS = 2;
const int MOSTRAR_MAPA = 3;
const int COMENZAR_PARTIDA = 4;
const int SALIR_INICIAL = 5;

const int CONSTRUIR_EDIFICIO = 1;
const int LISTAR_CONSTRUIDOS = 2;
const int DEMOLER_POR_COORDENADA = 3;
const int ATACAR_POR_COORDENADA = 4;
const int REPARAR_POR_COORDENADA = 5;
const int COMPRAR_BOMBAS = 6;
const int CONSULTAR_COORDENADA = 7;
const int MOSTRAR_INVENTARIO = 8;
const int MOSTRAR_OBJETIVOS = 9;
const int RECOLECTAR_RECURSOS = 10;
const int MOVERSE_COORDENADA = 11;
const int FINALIZAR_TURNO = 12;
const int SALIR_JUEGO = 13;

#ifdef __linux__
#define CLR_SCREEN "clear"
#endif // __linux__

#ifdef __APPLE__
#define CLR_SCREEN "clear"
#endif // __MacOsß__ß

#ifdef __MINGW32__
#define CLR_SCREEN "CLS"
#endif // __MINGW32__

class Menu
{
public:
    // pre: -
    // post: Imprime por pantalla el menu
    void mostrar_menu_partida_nueva();

    // pre: -
    // post: Imprime por pantalla el menu
    void mostrar_menu_juego();

    void menu_partida_nueva(Juego &andypolis, int opcion_elegida);

    void menu_juego(Juego &andypolis, int opcion_elegida);

    ////////////////////////////////
    // pre: El texto ingresado por el usuario tiene que ser un NUMERO entero
    // post: Realiza la opcion pedida
    void procesar_opcion_juego(int opcion_elegida, Juego &andypolis); // material *materiales_array, edificio *edificios_array, casillero **mapa, ubicacion *ubicaciones_array

    void procesar_opcion_partida_nueva(int opcion_elegida, Juego &andypolis);

    ////////////////////////////////
    // pre: El texto ingresado por el usuario tiene que ser un NUMERO entero
    // post: devuelve true si la opcion recibida esta en el rango valido y sino devuelve false.
    bool es_opcion_valida(int elegida, const int opcion_minima, const int opcion_maxima);

    void validar_opcion_juego(int opcion_elegida);

    void validar_opcion_partida_nueva(int opcion_elegida4);

    int obtener_opcion_usuario();
    ////////////////////////////////
    // pre: -
    // post: Obtiene una respuesta del usuario y la devuelve en minusculas.
    string devolver_rta_usuario();

    bool confirmacion_usuario();

    ////////////////////////////////
    void limpiar_pantalla();

    // pre: -
    // post: Pregunta para volver al menu
    void volver();

    void despedir();
    /////////////////////////////////
    bool comenzo_nueva_partida(int opcion_elegida);

    bool cerro_menu_inicial(int opcion_elegida);

    bool cerro_juego(int opcion_elegida);
};

bool char_son_iguales(char &c1, char &c2);

bool strings_son_iguales(string &str1, string &str2);
#endif // MENU_H
