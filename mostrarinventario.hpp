#ifndef MOSTRARINVENTARIO_HPP
#define MOSTRARINVENTARIO_HPP

#include "jugada.hpp"

class MostrarInventario : public Jugada{
    public: 
        void jugar(Constructor & bob, Mapa & mapa, int & turno, Jugador * jugador, int & id_jugador_actual);
};

#endif //MOSTRARINVENTARIO_HPP