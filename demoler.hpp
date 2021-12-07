#ifndef DEMOLER_HPP
#define DEMOLER_HPP

#include "jugada.hpp"

class Demoler : public Jugada{
    public: 
        void jugar(Constructor & bob, Mapa & mapa, int & turno, Jugador * jugador, int & id_jugador_actual){
            cout << "tengo que demoler un edificio por coordenada" << endl;

            //esto chequea los objetivos luego de ejecutar la accion. fin de turno = false hace que los 
            //objetivos que se tengan que chequear al final del turno se chequeen solo cuando cambia el turno
            bool fin_turno = false;
            jugador[id_jugador_actual-1].chequear_objetivos(fin_turno,bob);
        }
};

#endif //DEMOLER_HPP