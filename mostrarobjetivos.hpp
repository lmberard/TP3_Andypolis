#ifndef MOSTRAROBJETIVOS_HPP
#define MOSTRAROBJETIVOS_HPP

#include "jugada.hpp"

class MostrarObjetivos : public Jugada{
    public: 
        void jugar(Constructor & bob, Mapa & mapa, int & turno, Jugador * jugador, int & id_jugador_actual){

            bool fin_turno = false;
            jugador[id_jugador_actual-1].chequear_objetivos(fin_turno,bob);
            
            cout << "muestra los objetivos del jugador" << endl;
            jugador[id_jugador_actual-1].mostrar_objetivos_y_progreso();
        }
};

#endif //MOSTRAROBJETIVOS_HPP