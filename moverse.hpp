#ifndef MOVERSE_HPP
#define MOVERSE_HPP

#include "jugada.hpp"

class Moverse : public Jugada{
    public: 
        void jugar(Constructor & bob, Mapa & mapa, int & turno, Jugador * jugador, int & id_jugador_actual){
            
            Coordenada coordenadas;
            //Grafo grafo;

            for(int i = 0; i < mapa.obtener_filas(); i++){
                for (int j = 0; j < mapa.obtener_columnas(); j++)
                {
                    coordenadas = crear_coordenada(i, j);
                    cout << "(" << coordenadas.coord_x << "," << coordenadas.coord_y << ")" << endl;
                    //grafo.agregarVertice(coordenadas);
                }        
            }

            bool fin_turno = false;
            jugador[id_jugador_actual-1].chequear_objetivos(fin_turno,bob);
        }
};

#endif //MOVERSE_HPP