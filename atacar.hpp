#ifndef ATACAR_HPP
#define ATACAR_HPP

#include "jugada.hpp"

class Atacar : public Jugada{
    public: 
        void jugar(Constructor & bob, Mapa & mapa, int & turno, Jugador * jugador, int & id_jugador_actual){
            cout << "tengo que atacar a un edificio" << endl;
        }
};

#endif //ATACAR_HPP