#include <iostream>
#include <string>
#include <fstream>

#include "menu.hpp"
#include "juego.hpp"
#include "parser.hpp"

using namespace std;
int main()
{
    Menu menu;
    Parser lector_archivos;
    Juego andypolis;
    //lector_archivos.cargar_edificios(bob);
    int opcion = 0;
    //si el archivo ubicaciones.txt no existe o esta vacio entonces es una partida nueva
    if (lector_archivos.existe_archivo_ubicaciones())
    {
        do
        {
            menu.menu_partida_nueva(andypolis, opcion);
        } while (menu.cerro_menu_inicial(opcion));
    }
    else
    {
        menu.menu_juego(andypolis, opcion);
    }
    return 0;
}
