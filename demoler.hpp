#ifndef DEMOLER_HPP
#define DEMOLER_HPP

#include "jugada.hpp"

static const string ERR_DEMOLER_EDIFICIO_PROPIO = "El edificio que intenta demoler no está dentro de sus edificios construidos";
static const string ERR_ENERGIA_INSUFICIENTE = "No tiene la energía suficiente para demoler";
static const string ERR_NO_SE_PUEDE_DEMOLER = "No hay ningun edificio para demoler en esta coordenada";
static const string ERR_AL_DEMOLER_EDIFICIO = "Error al demoler el edificio";
static const int ENERGIA_NECESARIA_PARA_DEMOLER = 15;

class Demoler : public Jugada
{
public:
    void jugar(Constructor &bob, Mapa &mapa, int &turno, Jugador *jugador, int &id_jugador_actual);
};

#endif // DEMOLER_HPP
