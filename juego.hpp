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

class Juego
{
private:
    /*
    //NO ESTOY SEGURA DE ESTOS ACA O AFUERA
    Menu menu;
    Parser lector_archivos;
    */
    /*
    Terreno terreno;
    Constructor bob;
    Recurso recurso;
    Mapa mapa;

    Lista<Ubicacion> edificios;
    Lista<Ubicacion> materiales;
    Lista<Ubicacion> coordenadasTransitables;
    */

    Lista<Jugador> jugadores;
    int cant_jugadores;

public:
    Juego(int _cant_jugadores);
    ~Juego();
};
#endif //JUEGO_HPP
