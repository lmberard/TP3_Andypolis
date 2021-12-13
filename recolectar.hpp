#ifndef RECOLECTAR_HPP
#define RECOLECTAR_HPP

#include "jugada.hpp"

class Recolectar : public Jugada
{
public:
    void jugar(Constructor &bob, Mapa &mapa, int &turno, Jugador *jugador, int &id_jugador_actual);
};

#endif // RECOLECTAR_HPP
