#ifndef CONSULTARCOORDENADA_HPP
#define CONSULTARCOORDENADA_HPP

#include "jugada.hpp"

class ConsultarCoordenada : public Jugada
{
public:
    void jugar(Constructor &bob, Mapa &mapa, int &turno, Jugador *jugador, int &id_jugador_actual);
};

#endif // CONSULTARCOORDENADA_HPP
