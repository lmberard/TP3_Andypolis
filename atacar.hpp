#ifndef ATACAR_HPP
#define ATACAR_HPP

#include "jugada.hpp"

static const string ERR_ATACAR_EDIFICIO_PROPIO = "El edificio que intenta atacar está dentro de sus edificios";
static const string ERR_ENERGIA_INSUFICIENTE_ATACAR = "No tiene la energía suficiente para atacar";
static const string ERR_BOMBAS_INSUFICIENTE_ATACAR = "No tiene suficientes bombas para atacar al oponente";
static const string ERR_NO_SE_PUEDE_ATACAR = "No hay ningun edificio para atacar en esta coordenada";
static const string ERR_AL_DESTRUIR_EDIFICIO = "Error al destruir el edificio";
static const int ENERGIA_NECESARIA_PARA_ATACAR = 30;

class Atacar : public Jugada{
    public: 
        void jugar(Constructor & bob, Mapa & mapa, int & turno, Jugador * jugador, int & id_jugador_actual);
};

#endif //ATACAR_HPP