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

class Juego
{
private:
    /*
    //NO ESTOY SEGURA DE ESTOS ACA O AFUERA
    Menu menu;
    Parser lector_archivos;
    */
    Inventario inventario;
    Terreno terreno;
    Constructor bob;
    //Recurso recurso;
    Mapa mapa;

    Lista<Ubicacion> edificios;
    Lista<Ubicacion> materiales;
    Lista<Ubicacion> coordenadasTransitables;

    Lista<Jugador> jugadores;
    int cant_jugadores;

public:
    Juego(int _cant_jugadores);

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
    void lluvia(Recurso &recurso);
    //----------------------------------------------------------------
    // PRE:
    // POS:
    void construir(int x, int y, const string &edificio, Constructor &bob);

    // PRE:
    // POS:
    void agregar_ubicacion_edificio(Ubicacion ubicacion);

    bool chequear_permisos_edificio(const string &eledificio, Constructor &bob);

    int cant_construidos(const string &edificio);

    void agregar_ubicacion(int x, int y, string edificio);

    void demoler_edificio(int x, int y);

    void quitar_ubicacion(int x, int y);

    void llenarcoordenadatransitable();

    void cargar_ubicaciones();

    void listar_edificios();
};
#endif //JUEGO_HPP
