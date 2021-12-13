#include "mostrarobjetivos.hpp"

void MostrarObjetivos::jugar(Constructor &bob, Mapa &mapa, int &turno, Jugador *jugador, int &id_jugador_actual)
{
    bool fin_turno = false;
    jugador[id_jugador_actual - 1].chequear_objetivos(fin_turno, bob);
    jugador[id_jugador_actual - 1].mostrar_objetivos_y_progreso();
}
