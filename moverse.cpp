#include "moverse.hpp"

Moverse::Moverse()
{
    matriz_cargada = false;
}

void Moverse::jugar(Constructor &bob, Mapa &mapa, int &turno, Jugador *jugador, int &id_jugador_actual)
{
    Coordenada coordenadas;
    Lista<Coordenada> camino_recorrido;
    int costo;
    Grafo grafo;

    if (!matriz_cargada)
    {
        agregar_vertices(grafo, mapa);
        matriz_cargada = true;
    }
    agregar_caminos(grafo, mapa, id_jugador_actual);

    coordenadas = pedir_coordenadas_destino(id_jugador_actual, mapa);
    if (mapa.coordenadas_validas(coordenadas) == true)
    {
        grafo.caminoMinimo(mapa.obtener_posicion_jugador(id_jugador_actual), coordenadas, costo, camino_recorrido);
        if (costo < jugador[id_jugador_actual - 1].obtener_energia())
        {
            jugador[id_jugador_actual - 1].decrementar_puntos_energia(costo);
            moverse_en_vivo(mapa, camino_recorrido, jugador[id_jugador_actual - 1], id_jugador_actual);
            // recolectar_materiales_del_camino(mapa, camino_recorrido, jugador[id_jugador_actual - 1], id_jugador_actual);
            msjeOK("Se descontaron " + to_string(costo) + " puntos de energia.");
            msjeInfo("Actualmente tiene " + to_string(jugador[id_jugador_actual - 1].obtener_energia()) + " puntos de energia disponibles.");
        }
        else
        {
            msjeError("No cuenta con energia suficiente para trasladarse a esa coordenada.");
            msjeInfo("Actualmente tiene " + to_string(jugador[id_jugador_actual - 1].obtener_energia()) + " puntos de energia disponibles.");
        }
    }

    bool fin_turno = false;
    jugador[id_jugador_actual - 1].chequear_objetivos(fin_turno, bob);
}

void Moverse::agregar_vertices(Grafo &grafo, Mapa &mapa)
{
    Coordenada coordenadas;

    for (int i = mapa.obtener_filas() - 1; i >= 0; i--)
    {
        for (int j = mapa.obtener_columnas() - 1; j >= 0; j--)
        {
            coordenadas = crear_coordenada(i, j);
            grafo.agregarVertice(coordenadas);
        }
    }
}

void Moverse::agregar_caminos(Grafo &grafo, Mapa &mapa, int id_jugador_actual)
{
    Coordenada coordenadas, coord_aux;
    int aux = 0;

    for (int i = 0; i < mapa.obtener_filas(); i++)
    {
        for (int j = 0; j < mapa.obtener_columnas(); j++)
        {
            coordenadas = crear_coordenada(i, j);

            if (j + 1 < mapa.obtener_columnas())
            {
                coord_aux.coord_x = i;
                coord_aux.coord_y = j + 1;
                aux = mapa.obtener_peso_del_mapa(id_jugador_actual, coord_aux);
                grafo.agregarCamino(coordenadas, coord_aux, aux);
            }
            if (j - 1 >= 0)
            {
                coord_aux.coord_x = i;
                coord_aux.coord_y = j - 1;
                aux = mapa.obtener_peso_del_mapa(id_jugador_actual, coord_aux);
                grafo.agregarCamino(coordenadas, coord_aux, aux);
            }
            if (i + 1 < mapa.obtener_filas())
            {
                coord_aux.coord_x = i + 1;
                coord_aux.coord_y = j;
                aux = mapa.obtener_peso_del_mapa(id_jugador_actual, coord_aux);
                grafo.agregarCamino(coordenadas, coord_aux, aux);
            }
            if (i - 1 >= 0)
            {
                coord_aux.coord_x = i - 1;
                coord_aux.coord_y = j;
                aux = mapa.obtener_peso_del_mapa(id_jugador_actual, coord_aux);
                grafo.agregarCamino(coordenadas, coord_aux, aux);
            }
        }
    }
}

Coordenada Moverse::pedir_coordenadas_destino(int id_jugador_actual, Mapa &mapa)
{
    Coordenada actual = mapa.obtener_posicion_jugador(id_jugador_actual);
    msjeInfo("\nActualmente esta en la posicion: (" + to_string(actual.coord_x) + ", " + to_string(actual.coord_y) + ")");
    msjeInfo("A donde se quiere mover?\n");
    return pedir_coordenadas();
}

void Moverse::recolectar_materiales_del_camino(Mapa &mapa, Lista<Coordenada> &camino_recorrido, Jugador &jugador, int id_jugador_actual)
{
    mapa.borrar_jugador_de_coordenada(camino_recorrido[1]);
    mapa.recorrer(camino_recorrido[1]);
    for (int i = 2; i < camino_recorrido.mostrar_cantidad() + 1; i++)
    {
        if (mapa.agregar_jugador(camino_recorrido[i], &jugador, id_jugador_actual))
            mapa.borrar_jugador_de_coordenada(camino_recorrido[i]);
        mapa.recorrer(camino_recorrido[i]);
        if (i == camino_recorrido.mostrar_cantidad())
        {
            if (mapa.agregar_jugador(camino_recorrido[i], &jugador, id_jugador_actual))
                mapa.recorrer(camino_recorrido[i]);
        }
    }
    msjeInstruccion("\nCamino recorrido:");
    mapa.mostrar();

    for (int i = 1; i < camino_recorrido.mostrar_cantidad() + 1; i++)
    {
        mapa.desrecorrer(camino_recorrido[i]);
    }
}

void Moverse::moverse_en_vivo(Mapa &mapa, Lista<Coordenada> &camino_recorrido, Jugador &jugador, int id_jugador_actual)
{
    mapa.borrar_jugador_de_coordenada(camino_recorrido[1]);
    mapa.recorrer(camino_recorrido[1]);
    system("clear");
    mapa.mostrar();
    for (int i = 2; i < camino_recorrido.mostrar_cantidad() + 1; i++)
    {
        if (mapa.agregar_jugador(camino_recorrido[i], &jugador, id_jugador_actual))
        {
            mapa.recorrer(camino_recorrido[i]);
            system("clear");
            mapa.mostrar();
            usleep(500000);
            mapa.borrar_jugador_de_coordenada(camino_recorrido[i]);
        }
        else
        {
            mapa.recorrer(camino_recorrido[i]);
            system("clear");
            mapa.mostrar();
            usleep(500000);
        }
        if (i == camino_recorrido.mostrar_cantidad())
        {
            if (mapa.agregar_jugador(camino_recorrido[i], &jugador, id_jugador_actual))
                mapa.recorrer(camino_recorrido[i]);
        }
    }
    system("clear");
    mapa.mostrar();
    usleep(500000);

    for (int i = 1; i < camino_recorrido.mostrar_cantidad() + 1; i++)
    {
        mapa.desrecorrer(camino_recorrido[i]);
    }
}
