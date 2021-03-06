#ifndef MAPA_HPP
#define MAPA_HPP

#include "lista.hpp"
#include "ubicaciones.hpp"
#include "casillero.hpp"

class Mapa
{
private:
    int filas;
    int columnas;
    Casillero ***mapa;

    Lista<Ubicaciones> materiales;
    Coordenada jugador1;
    Coordenada jugador2;
    Lista<Coordenada> coordenadas_transitables; // ver si es necesario

public:
    //---------------CONSTRUCTORES DESTRUCTORES-----------------------
    Mapa();
    ~Mapa();

    int cant_coord_transitables();

    Coordenada obtener_posicion_jugador(int i);

    Coordenada obtener_coord_transitables(int i);

    void quitar_coord_transitable(Coordenada coord);

    //------------------------GETTERS---------------------------------
    int obtener_filas();
    int obtener_columnas();
    Edificio *obtener_edificio(Coordenada coord);
    string obtener_nombre_material(Coordenada coord);
    int obtener_cant_material(Coordenada coord);
    int obtener_tam_lista_ubicaciones();
    int obtener_cant_material(int i);
    string obtener_nombre_material(int i);
    Coordenada obtener_coordenada(int i, int j);
    Lista<Ubicaciones> &lista_materiales();
    int obtener_peso_del_mapa(int jugador_id, Coordenada coordenadas);

    //------------------------SETTERS---------------------------------
    void agregar_coordenada_transitable(Coordenada coord);
    void agregar_material(Coordenada coord, Material *material);
    void agregar_edificio(Coordenada coord, Edificio *edificio);
    void agregar_casillero(Coordenada coord, Casillero *casillero);
    bool agregar_jugador(Coordenada coord, Jugador *jugador, int i);
    bool mover_jugador(Coordenada coord, Jugador *jugador, int i);
    void borrar_jugador_de_coordenada(Coordenada coord);
    // TODO: Revisar nombre y metodo
    void agregar_ubicacion_material_lista(string nombre, Coordenada coord); // YO
    bool agregar_contenido(Coordenada coord, Edificio *edificio);
    bool agregar_contenido(Coordenada coord, Material *material);
    void actualizar_tam_mapa(int _filas, int _columnas);

    //-----------------------MEMORIA----------------------------------
    void crear_memoria_mapa(int _filas, int _columnas);
    void crear_memoria_filas_mapa(int _filas);
    void crear_memoria_columna_mapa(int posicion_fila, int _columnas);

    //----------------------PARA EL JUEGO-----------------------------
    void mostrar();
    void mostrar_info();
    void consultar_coordenada(Coordenada coord);
    void demoler_contenido(Coordenada coord);
    void recolectar_materiales_del_mapa(Coordenada &coordenadas);

    //--------------------FUNCIONES UTILES-----------------------------
    bool coordenadas_validas(Coordenada coord);
    bool coordenada_es_transitable(Coordenada coord);
    bool casillero_es_transitable(string tipo_casillero);
    void liberar_materiales();
    void liberar_edificios(Lista<Ubicaciones> &lista);
    void recorrer(Coordenada coord);
    void desrecorrer(Coordenada coord);
};

#endif // MAPA_HPP
