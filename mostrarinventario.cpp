#include "mostrarinventario.hpp"


void MostrarInventario::jugar(Constructor & bob, Mapa & mapa, int & turno, Jugador * jugador, int & id_jugador_actual)
{
    jugador[id_jugador_actual-1].mostrar_inventario();
}