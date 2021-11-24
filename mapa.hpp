#ifndef MAPA_HPP
#define MAPA_HPP
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
#include "terreno.hpp"
#include "edificio.hpp"
#include "material.hpp"

class Mapa
{
private:
    int filas;
    int columnas;
    Casillero ***mapa;

public:
    //----------------------------------------------------------------
    Mapa();

    ~Mapa();

    void crear_memoria_mapa(int _filas, int _columnas);

    void actualizar_tam_mapa(int _filas, int _columnas);

    void crear_memoria_filas_mapa(int _filas);

    void crear_memoria_columna_mapa(int posicion_fila, int _columnas);

    //----------------------------------------------------------------
    int obtener_filas();

    int obtener_columnas();

    Edificio *obtener_edificio(Coordenada coord);

    //----------------------------------------------------------------
    void agregar_casillero(Coordenada coord, string casillero, Terreno &terreno);

    bool agregar_contenido(Coordenada coord, Edificio *edificio);

    bool agregar_contenido(Coordenada coord, Material *material);

    //----------------------------------------------------------------
    void mostrar();

    void consultar_coordenada(Coordenada coord);

    bool coordenada_es_transitable(Coordenada coord);

    void demoler_contenido(Coordenada coord);

    bool coordenadas_validas(Coordenada coord);
};

#endif // MAPA_HPP
