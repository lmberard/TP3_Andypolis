#ifndef CONSULTARCOORDENADA_HPP
#define CONSULTARCOORDENADA_HPP

#include "jugada.hpp"

class ConsultarCoordenada : public Jugada{
    public: 
        void jugar(Constructor & bob, Mapa & mapa, int & turno, Jugador * jugador, int & id_jugador_actual){
            cout << "te tengo que decir las coordenadas en las que estas creo, no se" << endl;
        }
};

#endif //CONSULTARCOORDENADA_HPP