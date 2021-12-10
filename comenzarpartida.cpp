#include "comenzarpartida.hpp"

void ComenzarPartida::jugar(Constructor & bob, Mapa & mapa, int & turno, Jugador * jugador, int & id_jugador_actual)
{

    id_jugador_actual = pedir_id_jugador();
    
    if (id_jugador_es_valido(id_jugador_actual))
    {
        jugador[id_jugador_actual-1].setear_jugador(id_jugador_actual);
        setear_coordenada_jugador(id_jugador_actual, jugador, mapa);

        for (int i = 0; i < 2; i++){
            if ((id_jugador_actual - 1) != i){
                jugador[i].setear_jugador(i+1);
                setear_coordenada_jugador(i + 1, jugador, mapa);
            }
        }
        turno = 1;
    }
    else
    {
        msjeInstruccion("Intente de nuevo!");
        turno = 0;
    }
}