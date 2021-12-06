#ifndef DEMOLER_HPP
#define DEMOLER_HPP

#include "jugada.hpp"

class Demoler : public Jugada{
    public: 
        void jugar(Constructor & bob, Mapa & mapa, int & turno, Jugador * jugador, int & id_jugador_actual){
            cout << "tengo que demoler un edificio por coordenada" << endl;
        }
};

#endif //DEMOLER_HPP