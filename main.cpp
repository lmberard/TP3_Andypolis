#include <iostream>
#include <string>
#include <fstream>

#include "menu.hpp"
#include "juego.hpp"
//#include "parser.hpp"

using namespace std;
int main()
{
    Menu menu;
    Juego andypolis;

    int opcion = 0;
    //si el archivo ubicaciones.txt no existe o esta vacio entonces es una partida nueva
    
    if (andypolis.es_partida_nueva())
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