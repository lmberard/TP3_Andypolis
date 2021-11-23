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
    Inventario inventario;
    Terreno terreno;
    Constructor bob;
    Recurso recurso;

    Mapa mapa;
    Lista<Ubicacion> coordenadasTransitables;
    Lista<Ubicacion> edificios;
    Lista<Ubicacion> materiales;

    //Jugador jugadores[CANT_JUGADORES];

public:
    Juego();

    ~Juego();

    // PRE:
    // POS: Elimina los edificios y materiales construidos
    void demoler_todo();

    void crear_mapa(int filas, int columnas);

    void agregar_casillero(int x, int y, string casillero);

    int obtener_filas_mapa();

    int obtener_columnas_mapa();

    //----------------------------------------------------------------
    // PRE:
    // POS: Muestra el mapa por la terminal con sus respectivos colores para cada tipo de casillero y con la inicial de lo que haya en el mismo (material o edificio)
    void mostrar_mapa();

    // PRE:
    // POS:
    void consultar_coordenada();

    //----------------------------------------------------------------
    // PRE:
    // POS:
    void construir_por_nombre_coordenada(Constructor &bob);

    // PRE:
    // POS:
    void demoler_por_coordenada();

    // PRE:
    // POS:
    void mostrar_ubicaciones();

    // PRE:
    // POS:
    void recolectar();

    // PRE:
    // POS:
    void lluvia();
    //----------------------------------------------------------------
    // PRE:
    // POS:
    void construir(int x, int y, const string &edificio, Constructor &bob);

    // PRE:
    // POS:
    void agregar_ubicacion_edificio(Ubicacion ubicacion);

    void agregar_materiales_casillero_random(string nombre, int cantidad);

    bool chequear_permisos_edificio(const string &eledificio, Constructor &bob);

    int cant_construidos(const string &edificio);

    void agregar_ubicacion(int x, int y, string edificio);

    void demoler_edificio(int x, int y);

    void quitar_ubicacion(int x, int y);

    void llenar_coordenada_transitable();

    void cargar_ubicaciones();

    void listar_edificios();
};
#endif //JUEGO_HPP
