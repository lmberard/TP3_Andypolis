#ifndef LISTARCONSTRUIDOS_HPP
#define LISTARCONSTRUIDOS_HPP

#include "jugada.hpp"

class ListarConstruidos : public Jugada{
    public: 
        void jugar(Constructor & bob, Mapa & mapa, int & turno, Jugador * jugador, int & id_jugador_actual);
};







#endif //LISTARCONSTRUIDOS_HPP