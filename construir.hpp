#ifndef CONSTRUIR_HPP
#define CONSTRUIR_HPP

#include "jugada.hpp"

class Construir : public Jugada{
    public: 
        void jugar(Constructor & bob, Mapa & mapa, int & turno, Jugador * jugadores, int & id_jugador_actual);
        bool chequear_requerimientos_edificio(Edificio * edif_ptr, Jugador jugador);

};

#endif //CONSTRUIR_HPP



