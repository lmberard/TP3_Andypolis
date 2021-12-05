#ifndef COMENZARPARTIDA_HPP
#define COMENZARPARTIDA_HPP

#include "jugada.hpp"

class ComenzarPartida : public Jugada{
    public: 
        void jugar(Constructor & bob, Mapa & mapa, int & turno, Jugador * jugador, int & id_jugador_actual); 
};

#endif //COMENZARPARTIDA_HPP