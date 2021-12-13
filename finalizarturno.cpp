#include "finalizarturno.hpp"

void FinalizarTurno::jugar(Constructor & bob, Mapa & mapa, int & turno, Jugador * jugador, int & id_jugador_actual)
{
    bool fin_turno = true;
    jugador[id_jugador_actual-1].chequear_objetivos(fin_turno,bob);

    Lista<Ubicaciones> lista = jugador[id_jugador_actual -1].lista_edificios();
    
    for (int i = 1; i < lista.mostrar_cantidad() + 1; i++)
        for(int j = 1; j < obtener_cantidad(lista[i]) + 1; j++)
            mapa.obtener_edificio(lista[i].coordenadas[j])->producir();
    
    if(!jugador[id_jugador_actual-1].obtener_energia())
        jugador[id_jugador_actual-1].modificar_puntos_energia(50);

    if(id_jugador_actual < 2)
        id_jugador_actual++;
    else
        id_jugador_actual = 1;

    turno ++;

}
