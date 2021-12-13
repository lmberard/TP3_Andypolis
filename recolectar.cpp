#include "recolectar.hpp"

void Recolectar::jugar(Constructor &bob, Mapa &mapa, int &turno, Jugador *jugador, int &id_jugador_actual)
{
    if (jugador[id_jugador_actual - 1].obtener_energia() >= 20)
    {

        Lista<Ubicaciones> lista = jugador[id_jugador_actual - 1].lista_edificios();
        Coordenada coordenada;
        Edificio *edificio;

        for (int i = 1; i < lista.mostrar_cantidad() + 1; i++)
        {
            for (int j = 1; j < obtener_cantidad(lista[i]) + 1; j++)
            {
                coordenada = lista[i].coordenadas[j];
                edificio = mapa.obtener_edificio(coordenada);
                if (edificio->obtener_tipo_produccion() == "energia" && jugador[id_jugador_actual - 1].obtener_energia() < 100)
                {
                    jugador[id_jugador_actual - 1].modificar_puntos_energia(edificio->recolectar());
                    msjeOK("Se recolectaron " + to_string(edificio->recolectar()) + "unidades de energia.\n");
                }
                else
                {
                    jugador[id_jugador_actual - 1].inv().aniadir_cant_material(edificio->obtener_tipo_produccion(), edificio->recolectar());
                    msjeOK("Se recolectaron " + to_string(edificio->obtener_cant_produccion()) + " de unidades de " + edificio->obtener_tipo_produccion() + " del edificio '" + edificio->obtener_nombre() + "'");
                }
            }
        }
        jugador[id_jugador_actual - 1].decrementar_puntos_energia(20);

        bool fin_turno = false;
        jugador[id_jugador_actual - 1].chequear_objetivos(fin_turno, bob);
    }
    else
        msjeError("No posee energia suficiente.");
}
