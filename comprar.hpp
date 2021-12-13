#ifndef COMPRAR_HPP
#define COMPRAR_HPP

#include "jugada.hpp"

const int PRECIO_BOMBA = 100;

class Comprar : public Jugada
{
public:
    void jugar(Constructor &bob, Mapa &mapa, int &turno, Jugador *jugador, int &id_jugador_actual);
};

#endif // COMPRAR_HPP
