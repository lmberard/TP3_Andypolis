#ifndef MOSTRARMAPA_HPP
#define MOSTRARMAPA_HPP

#include "jugada.hpp"

class MostrarMapa : public Jugada
{
public:
    void jugar(Constructor &bob, Mapa &mapa, int &turno, Jugador *jugador, int &id_jugador_actual);
};

#endif // MOSTRARAPA_HPP
