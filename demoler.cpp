#include "demoler.hpp"

void Demoler::jugar(Constructor &bob, Mapa &mapa, int &turno, Jugador *jugador, int &id_jugador_actual)
{
    Coordenada coordenadas;
    Edificio *ptredificio;
    string edificio_a_demoler;

    coordenadas = pedir_coordenadas();

    if (mapa.coordenadas_validas(coordenadas) == true)
    {
        if (mapa.obtener_edificio(coordenadas) != NULL)
        {
            if (jugador[id_jugador_actual - 1].obtener_energia() >= ENERGIA_NECESARIA_PARA_DEMOLER)
            {
                if (jugador[id_jugador_actual - 1].tiene_edificio_por_coordenada(coordenadas, edificio_a_demoler) == true)
                {

                    ptredificio = mapa.obtener_edificio(coordenadas);
                    if (jugador[id_jugador_actual - 1].eliminar_ubicacion_lista_edificios(edificio_a_demoler, coordenadas) == false)
                    {
                        msjeError(ERR_AL_DEMOLER_EDIFICIO);
                    }
                    msjeOK("Se demolio el edificio del tipo '" + ptredificio->obtener_nombre() + "'");
                    jugador[id_jugador_actual - 1].inv().llenar_stock(ptredificio);
                    mapa.demoler_contenido(coordenadas);
                    jugador[id_jugador_actual - 1].decrementar_puntos_energia(ENERGIA_NECESARIA_PARA_DEMOLER);
                }
                else
                {
                    msjeError(ERR_DEMOLER_EDIFICIO_PROPIO);
                }
            }
            else
            {
                msjeError(ERR_ENERGIA_INSUFICIENTE);
            }
        }
        else
        {
            msjeError(ERR_NO_SE_PUEDE_DEMOLER);
        }
    }

    bool fin_turno = false;
    jugador[id_jugador_actual - 1].chequear_objetivos(fin_turno, bob);
}
