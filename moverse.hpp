#ifndef MOVERSE_HPP
#define MOVERSE_HPP

#include "jugada.hpp"

class Moverse : public Jugada{
    public: 
        void jugar(Constructor & bob, Mapa & mapa, int & turno, Jugador * jugador, int & id_jugador_actual){
            cout << "me tengo que mover con grafos! La ultima gran cosa del tp " << endl;

            //esto chequea los objetivos luego de ejecutar la accion. fin de turno = false hace que los 
            //objetivos que se tengan que chequear al final del turno se chequeen solo cuando cambia el turno
            bool fin_turno = false;
            jugador[id_jugador_actual-1].chequear_objetivos(fin_turno,bob);
        }
};

#endif //MOVERSE_HPP