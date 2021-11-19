#include <iostream>
#include <string>
#include <fstream>

#include "menu.hpp"
#include "ciudad.hpp"
#include "parser.hpp"

using namespace std;

int main()
{
    Menu menu;
    Parser lector_archivos;
    Terreno terreno;
    Constructor bob;
    lector_archivos.cargar_edificios(bob);
    Recurso recurso;
    Ciudad andypolis("mapa.txt", "materiales.txt", "ubicaciones.txt", terreno, bob, recurso);
    int opcion = 0;
    //si el archivo ubicaciones.txt no existe o esta vacio entonces es una partida nueva
    if (lector_archivos.existe_archivo_ubicaciones())
    {
        do
        {
            menu.menu_partida_nueva(andypolis, bob, recurso, opcion);
        } while (menu.cerro_menu_inicial(opcion));
    }
    else
    {
        menu.menu_juego(andypolis, bob, recurso, opcion);
    }
    return 0;
}
