#ifndef CIUDAD_HPP
#define CIUDAD_HPP
#include <string>
#include "colors.hpp"
#include "ubicaciones.hpp"
#include "lista.hpp"

#include "terreno.hpp"
#include "constructor.hpp"
#include "recurso.hpp"
#include "material.hpp"
#include "inventario.hpp"

class Ciudad
{

    Inventario inventario;

    Lista<Ubicacion> edificios;
    Lista<Ubicacion> materiales;

    Lista<Ubicacion> coordenadasTransitables;
    
    int filas;
    int columnas;
    Casillero ***mapa;

public:
    // PRE:
    // POS:
    Ciudad();

    // PRE:
    // POS:
    Ciudad(const string &, const string &, const string &, Terreno &terreno, Constructor &bob, Recurso &recurso);

    // PRE:
    // POS: Se elimina la Ciudad (se eliminan los casilleros del mapa, el mapa y lo construido (ubicaciones y materiales))
    ~Ciudad();

    // PRE:
    // POS: se guardan los cambios en los archivos txt de ubicaciones y de materiales
    void guardar_archivos();

    // PRE:
    // POS: Muestra el mapa por la terminal con sus respectivos colores para cada tipo de casillero y con la inicial de lo que haya en el mismo (material o edificio)
    void mostrar_mapa();

    // PRE:
    // POS:
    void consultar_coordenada_cin();

    // PRE:
    // POS:
    void consultar_coordenada(int, int);

    // PRE:
    // POS:
    void construir_por_nombre_coordenada(Constructor &bob);

    // PRE:
    // POS:
    void construir(int, int, const string &, Constructor &bob);

    // PRE:
    // POS:
    void cargar_ubicaciones(Constructor &bob);

    // PRE:
    // POS:
    bool chequear_permisos_edificio(const string &edificio, Constructor &bob);

    // PRE:
    // POS:
    void cargar_ubicaciones(const string &PATH);

    // PRE:
    // POS:

    // PRE:
    // POS:
    void mostrar_inventario();

    // PRE:
    // POS:
    void agregar_ubicacion(int x, int y, string edificio);

    // PRE:
    // POS:
    void demoler_por_coordenada();
    // PRE:
    // POS:
    void demoler_edificio(int x, int y);

    // PRE:
    // POS:
    bool guardar_ubicaciones();

    // PRE:
    // POS: Elimina los edificios y materiales construidos
    void demoler_todo();

    // PRE:
    // POS:
    void mostrar_ubicaciones();

    // PRE:
    // POS:
    int construidos(const string &edificio);

    // PRE:
    // POS:
    void recolectar();

    // PRE:
    // POS:

    // PRE:
    // POS:
    void quitar_ubicacion(int x, int y);

    // PRE:
    // POS:
    void llenarcoordenadatransitable();

    // PRE:
    // POS:
    void lluvia(Recurso &recurso);
};

void listar_edificios(Ciudad &andypolis, Constructor &bob);

#endif // CIUDAD_HPP