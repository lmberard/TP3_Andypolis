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
#include "terreno.hpp"
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
class Juego
{
private:
    Terreno terreno;
    Constructor bob;
    Recurso recurso;

    Mapa mapa;
    Lista<Coordenada> coordenadasTransitables; //ESTO VA EN MAPA O ACA? LO USAMOS?
    // tb hay materiales sueltos, donde los guardamos?
    //Lista<Coordenada> materiales;
    //Lista<Ubicaciones> materiales;

    Jugador jugadores[CANT_JUGADORES];

public:
    //--------------------CONSTRUCTORES DESTRUCTORES-------------------
    Juego();
    ~Juego();

    //--------------------------GETTERS--------------------------------
    int obtener_filas_mapa();
    int obtener_columnas_mapa();

    //---------------------MAPA PARSER---------------------------------
    void crear_mapa(int filas, int columnas);
    void agregar_casillero(Coordenada coord, string casillero);
    void agregar_material_coordenada(string nombre, Coordenada coord);
    void construir_edificio(Coordenada coord, const string &edificio, Constructor &bob, int id_jugador);

    //-------------------OPCIONES MENU PRINCIPAL-----------------------
    void modificar_edificio_por_nombre();
    void mostrar_todos_edificios();
    void mostrar_mapa();
    void comenzar_partida();

    //-----------------------OPCIONES JUEGO----------------------------
    void construir_por_nombre_coordenada(int id_jugador, Constructor &bob);
    void mostrar_edificios_construidos(int id_jugador);
    void demoler_por_coordenada(int id_jugador);
    void atacar_por_coordenada(int id_jugador);
    void reparar_por_coordenada(int id_jugador);
    void comprar_bombas(int id_jugador);
    void consultar_coordenada();
    void mostrar_objetivos(int id_jugador);
    void mostrar_inventario(int id_jugador);
    void recolectar(int id_jugador);
    void moverse_a_coordenada(int id_jugador);
    void finalizar_turno(int id_jugador);

    //-----------------------FUNCIONES UTILES--------------------------
    bool id_jugador_es_valido(int id_jugador);
    bool chequear_permisos_edificio(const string &eledificio, Constructor &bob, int id_jugador);

    Coordenada pedir_coordenadas();
    string pedir_nombre_edificio();

    void demoler_edificio(Coordenada coord, int id_jugador);
    void llenar_coordenada_transitable();
};
#endif //JUEGO_HPP
