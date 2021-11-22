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
#include "ciudad.hpp"
#include "ubicaciones.hpp"
#include "constructor.hpp"
#include "inventario.hpp"
#include "recurso.hpp"
#include "superficie.hpp"
#include "jugador.hpp"
#include "menu.hpp"

class Juego
{
private:
    /*Menu menu;
    Parser lector_archivos;

    Terreno terreno;
    Constructor bob;
    Recurso recurso;
    Ciudad ciudad;*/

    Lista<Jugador> jugadores;
    int cant_jugadores;

public:
    Juego(int _cant_jugadores);
    ~Juego();
};
#endif //JUEGO_HPP
