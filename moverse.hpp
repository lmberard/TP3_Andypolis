#ifndef MOVERSE_HPP
#define MOVERSE_HPP

#include "jugada.hpp"


class Moverse : public Jugada{
    public: 
        void jugar(Constructor & bob, Mapa & mapa, int & turno, Jugador * jugador, int & id_jugador_actual){
            
            Coordenada coordenadas;
            Coordenada coord_aux;
            Lista<Coordenada> camino_realizado;
            int costo;
            //Grafo grafo;

            for(int i = 0; i < mapa.obtener_filas(); i++){
                for (int j = 0; j < mapa.obtener_columnas(); j++)
                    grafo.agregarVertice(coordenadas);
            }

            for(int i = 0; i < mapa.obtener_filas(); i++){
                for (int j = 0; j < mapa.obtener_columnas(); j++)
                {
                    coordenadas = crear_coordenada(i, j);

                    if(j + 1 < mapa.obtener_columnas()){
                        coord_aux.coord_x = i;
                        coord_aux.coord_y = j + 1;
                        grafo.agregarCamino(coordenadas, coord_aux, mapa.obtener_peso_del_mapa(id_jugador_actual, coord_aux))
                    }
                    if(j - 1 > 0){
                        coord_aux.coord_x = i;
                        coord_aux.coord_y = j - 1;
                        grafo.agregarCamino(coordenadas, coord_aux, mapa.obtener_peso_del_mapa(id_jugador_actual, coord_aux))
                    }
                    if(i + 1 < mapa.obtener_filas()){
                        coord_aux.coord_x = i + 1;
                        coord_aux.coord_y = j;
                        grafo.agregarCamino(coordenadas, coord_aux, mapa.obtener_peso_del_mapa(id_jugador_actual, coord_aux))
                    }
                    if(i - 1 > 0){
                        coord_aux.coord_x = i - 1;
                        coord_aux.coord_y = j;
                        grafo.agregarCamino(coordenadas, coord_aux, mapa.obtener_peso_del_mapa(id_jugador_actual, coord_aux))
                    }                    
                }        
            }
            // pedir a usuario a donde se quiere mover (identificar donde estamos)
            // costo = grafo.obtener_camino_minimo(desde, hasta, lista<Ubicaciones>)

            bool fin_turno = false;
            jugador[id_jugador_actual-1].chequear_objetivos(fin_turno,bob);
        }
};

#endif //MOVERSE_HPP