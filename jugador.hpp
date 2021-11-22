#ifndef JUGADOR_HPP
#define JUGADOR_HPP
#include <iostream>
#include <string>
#include <algorithm>
#include <fstream>
#include <cstdlib>
#include <iomanip>
#include <cctype>
#include "colors.hpp"
#include "lista.hpp"
#include "ciudad.hpp"
#include "ubicaciones.hpp"
#include "constructor.hpp"
#include "inventario.hpp"
#include "recurso.hpp"
#include "superficie.hpp"
#include "objetivo.hpp"

class Jugador
{
private:
    int id;

    Lista<Ubicacion> edificios;
    Inventario inventario;
    Ubicacion ubicacion;

    int puntos_energia;
    //Objetivo objetivo_principal;
    Lista<Objetivo> objetivos;
    int cantidad_objetivos;

public:
    Jugador(int _id, Ubicacion _ubicacion, int puntos_iniciales);
    ~Jugador();
    void setear_objetivos_secundarios();
    void setear_objetivo_principal();

    int obtener_id();
    int obtener_puntos_energia();
    void modificar_puntos_energia(int cantidad);
    bool se_quedo_sin_energia();

    void moverse_a_coordenada(int x, int y);

    bool cantidad_suficiente_material(Edificio *edificio, bool construir);
    void modificar_inventario(string nombre_material, int cantidad);
    void modificar_lista_edificios(string edificio, Ubicacion ubicacion);

    bool es_su_edificio(string nombre_edificio, Ubicacion ubicacion);

    void modificar_andypoints(int cantidad);
    int obtener_cant_andycoins();
    int obtener_cant_bombas();

    void mostrar_objetivos_y_progreso();
    void mostrar_inventario();
};
#endif //JUGADOR_HPP
