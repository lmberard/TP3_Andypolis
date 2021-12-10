#ifndef ATACAR_HPP
#define ATACAR_HPP

#include "jugada.hpp"

static const string ERR_ATACAR_EDIFICIO_PROPIO = "El edificio que intenta atacar está dentro de sus edificios";
static const string ERR_ENERGIA_INSUFICIENTE_ATACAR = "No tiene la energía suficiente para atacar";
static const string ERR_NO_SE_PUEDE_ATACAR = "No hay ningun edificio para atacar en esta coordenada";
static const string ERR_AL_DEMOLER_EDIFICIO = "Error al demoler el edificio";
static const int ENERGIA_NECESARIA_PARA_ATACAR = 30;

class Atacar : public Jugada{
    public: 
        void jugar(Constructor & bob, Mapa & mapa, int & turno, Jugador * jugador, int & id_jugador_actual){
            
            Coordenada coordenadas;
            Edificio* ptredificio;
            string edificio_a_atacar;

            coordenadas = pedir_coordenadas();

            if(mapa.obtener_edificio(coordenadas) != NULL){
                if(jugador[id_jugador_actual - 1].obtener_energia() > ENERGIA_NECESARIA_PARA_ATACAR){
                    if(jugador[id_jugador_actual - 1].tiene_edificio_por_coordenada(coordenadas, edificio_a_atacar) == false){
                        
                        ptredificio = mapa.obtener_edificio(coordenadas);
                        if(jugador->inv().obtener_bombas_contador() > 1){
                            if(ptredificio->obtener_vida() == 1){
                                if(jugador[id_jugador_actual - 1].eliminar_ubicacion_lista_edificios(edificio_a_atacar, coordenadas) == false){
                                        cout << ERR_AL_DESTRUIR_EDIFICIO << endl;
                                }
                                mapa.demoler_contenido(coordenadas);
                                jugador->inv().decrementar_bombas_contador();
                                jugador->inv().aumentar_bombas_usadas();
                            }   else {
                                    ptredificio->bajar_vida();
                                    jugador->inv().decrementar_bombas_contador();
                                    jugador->inv().aumentar_bombas_usadas();
                                }

                        } else {cout << "No tiene suficientes bombas para atacar al oponente" << endl;}

                    } else {cerr << ERR_ATACAR_EDIFICIO_PROPIO << endl;}
                        
                } else {cerr << ERR_ENERGIA_INSUFICIENTE_ATACAR << endl;}
                    
            } else {cerr << ERR_NO_SE_PUEDE_ATACAR << endl;}

            bool fin_turno = false;
            jugador[id_jugador_actual-1].chequear_objetivos(fin_turno,bob);
        }
};

#endif //ATACAR_HPP