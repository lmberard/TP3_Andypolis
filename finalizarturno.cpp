#include "finalizarturno.hpp"

void FinalizarTurno::jugar(Constructor & bob, Mapa & mapa, int & turno, Jugador * jugador, int & id_jugador_actual)
{
    bool fin_turno = true;
    jugador[id_jugador_actual-1].chequear_objetivos(fin_turno,bob);

    if(id_jugador_actual < 2)
        id_jugador_actual++;
    else
        id_jugador_actual = 1;

    turno ++;

}
