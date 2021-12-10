#ifndef DEMOLER_HPP
#define DEMOLER_HPP

#include "jugada.hpp"

static const string ERR_DEMOLER_EDIFICIO_PROPIO = "El edificio que intenta demoler no está dentro de sus edificios construidos";
static const string ERR_ENERGIA_INSUFICIENTE = "No tiene la energía suficiente para demoler";
static const string ERR_NO_SE_PUEDE_DEMOLER = "No hay ningun edificio para demoler en esta coordenada";
static const string ERR_AL_DESTRUIR_EDIFICIO = "Error al destruir el edificio";
static const int ENERGIA_NECESARIA_PARA_DEMOLER = 15;

class Demoler : public Jugada{
    public: 

        void jugar(Constructor & bob, Mapa & mapa, int & turno, Jugador * jugador, int & id_jugador_actual){
            
            Coordenada coordenadas;
            Edificio* ptredificio;
            string edificio_a_demoler;

            coordenadas = pedir_coordenadas();

            //TODO: PONER MENSAJES DE ERROR

            if(mapa.obtener_edificio(coordenadas) != NULL){
                if(jugador[id_jugador_actual - 1].obtener_energia() > ENERGIA_NECESARIA_PARA_DEMOLER){
                    if(jugador[id_jugador_actual - 1].tiene_edificio_por_coordenada(coordenadas, edificio_a_demoler) == true){
                        
                        ptredificio = mapa.obtener_edificio(coordenadas);
                        if(jugador[id_jugador_actual - 1].eliminar_ubicacion_lista_edificios(edificio_a_demoler, coordenadas) == false){
                            cout << ERR_AL_DESTRUIR_EDIFICIO << endl;
                        }
                        jugador[id_jugador_actual - 1].inv().llenar_stock(ptredificio);
                        mapa.demoler_contenido(coordenadas);

                    } else {cerr << ERR_DEMOLER_EDIFICIO_PROPIO << endl;}
                        
                } else {cerr << ERR_ENERGIA_INSUFICIENTE << endl;}
                    
            } else {cerr << ERR_NO_SE_PUEDE_DEMOLER << endl;}

            bool fin_turno = false;
            jugador[id_jugador_actual-1].chequear_objetivos(fin_turno,bob);
        }

};

#endif //DEMOLER_HPP