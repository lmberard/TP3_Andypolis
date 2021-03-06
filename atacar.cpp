#include "atacar.hpp"

void Atacar::jugar(Constructor &bob, Mapa &mapa, int &turno, Jugador *jugador, int &id_jugador_actual)
{

    Coordenada coordenadas;
    Edificio *ptredificio;
    string edificio_a_atacar, aux;

    coordenadas = pedir_coordenadas();

    if (mapa.obtener_edificio(coordenadas) != NULL)
    {
        if (jugador[id_jugador_actual - 1].obtener_energia() >= ENERGIA_NECESARIA_PARA_ATACAR)
        {
            if (jugador[id_jugador_actual - 1].tiene_edificio_por_coordenada(coordenadas, aux) == false)
            {
                edificio_a_atacar = mapa.obtener_edificio(coordenadas)->obtener_nombre();
                ptredificio = mapa.obtener_edificio(coordenadas);
                if (jugador->inv().obtener_material("bomba")->obtener_cantidad() > 1)
                {
                    if (ptredificio->obtener_vida() == 1)
                    {

                        for (int i = 0; i < 2; i++)
                        {
                            if ((id_jugador_actual - 1) != i)
                            {
                                if (jugador[i].eliminar_ubicacion_lista_edificios(edificio_a_atacar, coordenadas) == false)
                                {
                                    msjeError(ERR_AL_DESTRUIR_EDIFICIO);
                                }
                            }
                        }

                        mapa.demoler_contenido(coordenadas);
                        jugador[id_jugador_actual - 1].inv().decrementar_bombas_contador();
                        jugador[id_jugador_actual - 1].inv().aumentar_bombas_usadas();
                        jugador[id_jugador_actual - 1].decrementar_puntos_energia(ENERGIA_NECESARIA_PARA_ATACAR);
                    }
                    else
                    {
                        ptredificio->bajar_vida();
                        jugador[id_jugador_actual - 1].inv().decrementar_bombas_contador();
                        jugador[id_jugador_actual - 1].inv().aumentar_bombas_usadas();
                        jugador[id_jugador_actual - 1].decrementar_puntos_energia(ENERGIA_NECESARIA_PARA_ATACAR);
                    }
                }
                else
                {
                    msjeError(ERR_BOMBAS_INSUFICIENTE_ATACAR);
                }
            }
            else
            {
                msjeError(ERR_ATACAR_EDIFICIO_PROPIO);
            }
        }
        else
        {
            msjeError(ERR_ENERGIA_INSUFICIENTE_ATACAR);
        }
    }
    else
    {
        msjeError(ERR_NO_SE_PUEDE_ATACAR);
    }

    bool fin_turno = false;
    jugador[id_jugador_actual - 1].chequear_objetivos(fin_turno, bob);
}
