#ifndef CONSTRUIR_HPP
#define CONSTRUIR_HPP

#include "jugada.hpp"

class Construir : public Jugada{
    public: 
        void jugar(Constructor & bob, Mapa & mapa, int & turno, Jugador * jugador, int & id_jugador_actual){
            cout << "tengo que constuir un edificio!! " << endl;
        }
};

#endif //CONSTRUIR_HPP