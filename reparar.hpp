#ifndef REPARAR_HPP
#define REPARAR_HPP

#include "jugada.hpp"

class Reparar : public Jugada{
    public: 
        void jugar(Constructor & bob, Mapa & mapa, int & turno, Jugador * jugador, int & id_jugador_actual){
            cout << "tengo que reparar edificios" << endl;
        }
};

#endif //REPARAR_HPP