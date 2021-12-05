#ifndef COMPRAR_HPP
#define COMPRAR_HPP

#include "jugada.hpp"

class Comprar : public Jugada{
    public: 
        void jugar(Constructor & bob, Mapa & mapa, int & turno, Jugador * jugador, int & id_jugador_actual){
            cout << "tengo que comprar bombas" << endl;
        }
};

#endif //COMPRAR_HPP