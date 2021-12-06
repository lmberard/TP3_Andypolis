#ifndef MOSTRAROBJETIVOS_HPP
#define MOSTRAROBJETIVOS_HPP

#include "jugada.hpp"

class MostrarObjetivos : public Jugada{
    public: 
        void jugar(Constructor & bob, Mapa & mapa, int & turno, Jugador * jugador, int & id_jugador_actual){
            cout << "muestra los objetivos del jugador" << endl;
        }
};

#endif //MOSTRAROBJETIVOS_HPP