#include "atacar.hpp"

void Atacar::jugar(Constructor & bob, Mapa & mapa, int & turno, Jugador * jugador, int & id_jugador_actual)
{
            
    Coordenada coordenadas;
    Edificio* ptredificio;
    string edificio_a_atacar, aux;

    coordenadas = pedir_coordenadas();

    if(mapa.obtener_edificio(coordenadas) != NULL){
        if(jugador[id_jugador_actual - 1].obtener_energia() >= ENERGIA_NECESARIA_PARA_ATACAR){
            if(jugador[id_jugador_actual - 1].tiene_edificio_por_coordenada(coordenadas, aux) == false){
                edificio_a_atacar = mapa.obtener_edificio(coordenadas)->obtener_nombre();
                ptredificio = mapa.obtener_edificio(coordenadas);
                if(jugador->inv().obtener_bombas_contador() > 1){
                    if(ptredificio->obtener_vida() == 1){
                        //TODO:cambiar logica if
                        for (int i = 0; i < 2; i++){
                            if ((id_jugador_actual - 1) != i){
                                if(jugador[i].eliminar_ubicacion_lista_edificios(edificio_a_atacar, coordenadas) == false){
                                    cout << ERR_AL_DESTRUIR_EDIFICIO << endl;
                                }
                            }
                        }
                        mapa.demoler_contenido(coordenadas);
                        jugador[id_jugador_actual - 1].inv().decrementar_bombas_contador();
                        jugador[id_jugador_actual - 1].inv().aumentar_bombas_usadas();
                    }else {
                        ptredificio->bajar_vida();
                        jugador[id_jugador_actual - 1].inv().decrementar_bombas_contador();
                        jugador[id_jugador_actual - 1].inv().aumentar_bombas_usadas();
                    }

                } else {cout << "No tiene suficientes bombas para atacar al oponente" << endl;}

            } else {cerr << ERR_ATACAR_EDIFICIO_PROPIO << endl;}
                        
        } else {cerr << ERR_ENERGIA_INSUFICIENTE_ATACAR << endl;}
                    
    } else {cerr << ERR_NO_SE_PUEDE_ATACAR << endl;}

    bool fin_turno = false;
    jugador[id_jugador_actual-1].chequear_objetivos(fin_turno,bob);

}