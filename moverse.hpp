#ifndef MOVERSE_HPP
#define MOVERSE_HPP

#include "jugada.hpp"


class Moverse : public Jugada{
    public: 
        void jugar(Constructor & bob, Mapa & mapa, int & turno, Jugador * jugador, int & id_jugador_actual);
        Coordenada pedir_coordenadas_destino();
        void agregar_vertices(Grafo & grafo, Mapa & mapa);
        void agregar_caminos(Grafo & grafo, Mapa & mapa, int id_jugador_actual);

};

#endif //MOVERSE_HPP