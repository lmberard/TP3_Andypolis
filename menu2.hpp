#ifndef MENU_H
#define MENU_H

#include "colors.hpp"
#include "juego.hpp"

#include "comenzarpartida.hpp"
#include "listaredificios.hpp"
#include "mostrarmapa.hpp"
#include "modificaredificio.hpp"

#include "construir.hpp"
#include "listarconstruidos.hpp"
#include "demoler.hpp"
#include "atacar.hpp"
#include "reparar.hpp"
#include "comprar.hpp"
#include "consultarcoordenada.hpp"
#include "mostrarinventario.hpp"
#include "mostrarobjetivos.hpp"
#include "recolectar.hpp"
#include "moverse.hpp"
#include "finalizarturno.hpp"

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

/*---------------------------MENUS----------------------------------*/

    Jugada* inicial();

    Jugada* menu_juego(int id_jugador_actual);

/*--------------------------MENSAJES ------------------------------*/
    // pre: -
    // post: Imprime por pantalla el menu
    void partida_nueva_mostrar();

    // pre: -
    // post: Imprime por pantalla el menu
    void mostrar_menu_juego(int id_jugador);

    void despedir();

/*-------------------------OBTENER DATOS---------------------------*/

    int obtener_opcion_usuario();

/*-------------------------VALIDACIONES----------------------------*/

    // pre: El texto ingresado por el usuario tiene que ser un NUMERO entero
    // post: devuelve true si la opcion recibida esta en el rango valido y sino devuelve false.
    bool es_opcion_valida(int elegida, const int opcion_minima, const int opcion_maxima);

    void validar_opcion_juego(int & opcion_elegida, int id_jugador_actual);

    void validar_opcion_partida_nueva(int & opcion_elegida4);

/*------------------------PROCESAR OPCIONES----------------------------*/

    // pre: El texto ingresado por el usuario tiene que ser un NUMERO entero
    // post: Realiza la opcion pedida
    Jugada* procesar_opcion_juego(int opcion_elegida); // material *materiales_array, edificio *edificios_array, casillero **mapa, ubicacion *ubicaciones_array

    Jugada* procesar_opcion_partida_nueva(int opcion_elegida);

/*------------------------OPCIONES DISPLAY-------------------------------*/   
    
    void limpiar_pantalla();

    // pre: -
    // post: Pregunta para volver al menu
    void volver();
};

#endif // MENU_H