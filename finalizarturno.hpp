#ifndef FINALIZARTURNO_HPP
#define FINALIZARTURNO_HPP

#include "jugada.hpp"

class FinalizarTurno : public Jugada
{
public:
    void jugar(Constructor &bob, Mapa &mapa, int &turno, Jugador *jugador, int &id_jugador_actual);
};

#endif // FINALIZARTURNO_HPP
