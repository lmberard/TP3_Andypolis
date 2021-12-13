#ifndef MOVERSE_HPP
#define MOVERSE_HPP
#include <unistd.h>
#include "jugada.hpp"
#include "grafo.hpp"

class Moverse : public Jugada
{
private:
    bool matriz_cargada;

public:
    Moverse();
    void jugar(Constructor &bob, Mapa &mapa, int &turno, Jugador *jugador, int &id_jugador_actual);
    Coordenada pedir_coordenadas_destino(int id_jugador_actual, Mapa &mapa);
    void agregar_vertices(Grafo &grafo, Mapa &mapa);
    void agregar_caminos(Grafo &grafo, Mapa &mapa, int id_jugador_actual);
    void recolectar_materiales_del_camino(Mapa &mapa, Lista<Coordenada> &camino_recorrido, Jugador &jugador, int id);
    void moverse_en_vivo(Mapa &mapa, Lista<Coordenada> &camino_recorrido, Jugador &jugador, int id);
};

#endif // MOVERSE_HPP
