#include "listaredificios.hpp"

void ListarEdificios::jugar(Constructor &bob, Mapa &mapa, int &turno, Jugador *jugador, int &id_jugador_actual)
{
     int cant_edificios = bob.cant_edificios();
     Edificio *edificio;

     cout << left << TXT_BOLD << TXT_UNDERLINE << BGND_BLUE_4
          << setw(23) << "Nombre" << '\t'
          << setw(23) << "Cant de madera" << '\t'
          << setw(23) << "Cant de metal" << '\t'
          << setw(23) << "Cant de piedra" << '\t'
          << setw(23) << "Cant construida" << '\t'
          << setw(30) << "Cant disponible para construir" << '\t'
          << setw(30) << "Tipo de material que produce" << '\t'
          << setw(30) << "Cant de produccion"
          << END_COLOR << endl;

     for (int i = 1; i < cant_edificios + 1; i++)
     {
          edificio = bob.mostrar_edificio(i);

          cout << left
               << setw(23) << edificio->obtener_nombre() << '\t'
               << setw(23) << edificio->obtener_madera() << '\t'
               << setw(23) << edificio->obtener_metal() << '\t'
               << setw(23) << edificio->obtener_piedra() << '\t'
               << setw(23) << 0 << '\t'
               << setw(30) << edificio->obtener_cant_max() << '\t'
               << setw(30) << edificio->obtener_tipo_produccion() << '\t'
               << setw(30) << edificio->obtener_cant_produccion()
               << endl;
     }
}
