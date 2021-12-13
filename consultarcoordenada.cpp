#include "consultarcoordenada.hpp"

void ConsultarCoordenada::jugar(Constructor &bob, Mapa &mapa, int &turno, Jugador *jugador, int &id_jugador_actual)
{
    Coordenada coord = pedir_coordenadas();
    if (mapa.coordenadas_validas(coord))
    {
        msjeInstruccion("Se encuentra en la posicion (" + to_string(coord.coord_x) + ", " + to_string(coord.coord_y) + ")");
        mapa.consultar_coordenada(coord);
    }
}
