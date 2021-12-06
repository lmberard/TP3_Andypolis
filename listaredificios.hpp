#ifndef LISTAREDIFICIOS_HPP
#define LISTAREDIFICIOS_HPP

#include "jugada.hpp"

class ListarEdificios : public Jugada{
    public: 
        void jugar(Constructor & bob, Mapa & mapa, int & turno, Jugador * jugador, int & id_jugador_actual);
};

#endif //LISTAREDIFICIOS.HPP