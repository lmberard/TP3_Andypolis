#include "moverse.hpp"

void Moverse::jugar(Constructor & bob, Mapa & mapa, int & turno, Jugador * jugador, int & id_jugador_actual){
    Coordenada coordenadas;
    Lista<Coordenada> camino_recorrido;
    int costo;
    Grafo grafo;

    agregar_vertices(grafo, mapa);
    agregar_caminos(grafo, mapa, id_jugador_actual);

    coordenadas = pedir_coordenadas_destino();
    if(mapa.coordenadas_validas(coordenadas) == true){
        cout << "antes de camino minimo" << endl;
        grafo.caminoMinimo(mapa.obtener_posicion_jugador(id_jugador_actual), coordenadas, costo, camino_recorrido);
        cout << "despues de camino minimo" << endl;
        //recolectar_materiales_del_camino(mapa, camino_recorrido);
    }

    bool fin_turno = false;
    jugador[id_jugador_actual-1].chequear_objetivos(fin_turno,bob);
        
}


void Moverse::agregar_vertices(Grafo & grafo, Mapa & mapa){
    Coordenada coordenadas;

    for(int i = 0; i < mapa.obtener_filas(); i++){
        for (int j = 0; j < mapa.obtener_columnas(); j++){
            coordenadas = crear_coordenada(i, j);
            grafo.agregarVertice(coordenadas);
        }
    }
}

void Moverse::agregar_caminos(Grafo & grafo, Mapa & mapa, int id_jugador_actual){
    Coordenada coordenadas, coord_aux;

    for(int i = 0; i < mapa.obtener_filas(); i++){
        for (int j = 0; j < mapa.obtener_columnas(); j++){
            coordenadas = crear_coordenada(i, j);

            if(j + 1 < mapa.obtener_columnas()){
                coord_aux.coord_x = i;
                coord_aux.coord_y = j + 1;
                grafo.agregarCamino(coordenadas, coord_aux, mapa.obtener_peso_del_mapa(id_jugador_actual, coord_aux));
            }
            if(j - 1 > 0){
                coord_aux.coord_x = i;
                coord_aux.coord_y = j - 1;
                grafo.agregarCamino(coordenadas, coord_aux, mapa.obtener_peso_del_mapa(id_jugador_actual, coord_aux));
            }
            if(i + 1 < mapa.obtener_filas()){
                coord_aux.coord_x = i + 1;
                coord_aux.coord_y = j;
                grafo.agregarCamino(coordenadas, coord_aux, mapa.obtener_peso_del_mapa(id_jugador_actual, coord_aux));
            }
            if(i - 1 > 0){
                coord_aux.coord_x = i - 1;
                coord_aux.coord_y = j;
                grafo.agregarCamino(coordenadas, coord_aux, mapa.obtener_peso_del_mapa(id_jugador_actual, coord_aux));
            }                    
        }        
    }
}


Coordenada Moverse::pedir_coordenadas_destino(){
    msjeInstruccion("Ingrese las coordenadas a las que desea moverse.");
    return pedir_coordenadas();
}

void Moverse::recolectar_materiales_del_camino(Mapa & mapa, Lista<Coordenada> & camino_recorrido){

    for(int i = 1; i < camino_recorrido.mostrar_cantidad() - 1; i++){
        mapa.recolectar_materiales_del_mapa(camino_recorrido[i]);
    }

}
