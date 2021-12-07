#ifndef MODIFICAREDIFICIO_HPP
#define MODIFICAREDIFICIO_HPP

#include "jugada.hpp"

class ModificarEdificio : public Jugada{
    public: 
        void jugar(Constructor & bob, Mapa & mapa, int & turno, Jugador * jugador, int & id_jugador_actual){
            cout << "MODIFICAR EDIFICIO POR NOMBRE NO HECHO" << endl; 
        }
};


#endif //MODIFICAREDIFICIO_HPP