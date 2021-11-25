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
    Recurso recurso;
    //Inventario inventario;
    Jugador jugador1;
    Jugador jugador2;
    lector_archivos.cargar_inventario(recurso, jugador1, jugador2);
    lector_archivos.cargar_ubicaciones(andypolis);
    //lector_archivos.cargar_edificios(bob);

    int opcion = 0;
    //si el archivo ubicaciones.txt no existe o esta vacio entonces es una partida nueva
    if (lector_archivos.existe_archivo_ubicaciones())
    {
        do
        {
            menu.menu_partida_nueva(andypolis, opcion);
            // jugador1.mostrar_inventario();
            // jugador2.mostrar_inventario();
            // cout << "ID Jugador 1: " << andypolis.obtener_jugador_1().obtener_id() << endl;
            // cout << "Coordenada X Jugador 1: " << andypolis.obtener_jugador_1().obtener_posicion_jugador().coord_x << endl;
            // cout << "Coordenada Y Jugador 1: " << andypolis.obtener_jugador_1().obtener_posicion_jugador().coord_y << endl;
            // cout << "ID Jugador 2: " << andypolis.obtener_jugador_2().obtener_id() << endl;
            // cout << "Coordenada X Jugador 2: " << andypolis.obtener_jugador_2().obtener_posicion_jugador().coord_x << endl;
            // cout << "Coordenada X Jugador 2: " << andypolis.obtener_jugador_2().obtener_posicion_jugador().coord_y << endl;

        } while (menu.cerro_menu_inicial(opcion));
    }
    else
    {
        menu.menu_juego(andypolis, opcion);
    }



    return 0;
}
