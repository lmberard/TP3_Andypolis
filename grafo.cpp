#include "grafo.hpp"
#include <iostream>

Grafo::Grafo()
{
    matrizDeAdyacencia = nullptr;
}

void Grafo::agregarVertice(Coordenada nuevoVertice)
{
    agrandarMatrizDeAdyacencia();
    vertices.alta(nuevoVertice);
}

void Grafo::agregarCamino(Coordenada origen, Coordenada destino, int & peso)
{
    int posicionOrigen = vertices.obtenerPosicion(origen);
    int posicionDestino = vertices.obtenerPosicion(destino);

    if (posicionOrigen == POSICION_NO_ENCONTRADA)
    {
        cout << "El vertice (" << origen.coord_x << "," << origen.coord_y  << ") no existe en el grafo" << endl;
    }
    if (posicionDestino == POSICION_NO_ENCONTRADA)
    {
        cout << "El vertice (" << destino.coord_x << "," << destino.coord_y << ") no existe en el grafo" << endl;
    }

    if (!(posicionDestino == POSICION_NO_ENCONTRADA || posicionOrigen == POSICION_NO_ENCONTRADA))
    {
        matrizDeAdyacencia[posicionOrigen][posicionDestino] = peso;
    }
}

void Grafo::caminoMinimo(Coordenada origen, Coordenada destino, int & energia, Lista<Coordenada> & lista )
{
    int posicionOrigen = vertices.obtenerPosicion(origen);
    int posicionDestino = vertices.obtenerPosicion(destino);

    if (posicionOrigen == POSICION_NO_ENCONTRADA)
    {
        cout << "El vertice (" << origen.coord_x << "," << origen.coord_y << ") no existe en el grafo" << endl;
    }
    if (posicionDestino == POSICION_NO_ENCONTRADA)
    {
        cout << "El vertice (" << destino.coord_x << "," << destino.coord_y << ") no existe en el grafo" << endl;
    }

    caminoMinimo(posicionOrigen, posicionDestino, energia, lista);
}

void Grafo::agrandarMatrizDeAdyacencia()
{
    int **matrizAuxiliar;
    int nuevaCantidadDeVertices = vertices.mostrar_cantidad() + 1;
   

    matrizAuxiliar = new int *[nuevaCantidadDeVertices];
    for (int i = 0; i < nuevaCantidadDeVertices; i++)
    {
        matrizAuxiliar[i] = new int[nuevaCantidadDeVertices];
    }

    copiarMatrizAdyacente(matrizAuxiliar);
    inicializarNuevoVertice(matrizAuxiliar);
    liberarMatrizAdyacencia();
    matrizDeAdyacencia = matrizAuxiliar;
}

void Grafo::copiarMatrizAdyacente(int **nuevaAdyacente)
{
    for (int i = 0; i < vertices.mostrar_cantidad(); i++)
    {
        for (int j = 0; j <  vertices.mostrar_cantidad(); j++)
        {
            nuevaAdyacente[i][j] = matrizDeAdyacencia[i][j];
        }
    }
}

void Grafo::inicializarNuevoVertice(int **nuevaAdyacente)
{
    for (int i = 0; i <  vertices.mostrar_cantidad(); i++)
    {
        nuevaAdyacente[ vertices.mostrar_cantidad()][i] = INFINITO;
        nuevaAdyacente[i][ vertices.mostrar_cantidad()] = INFINITO;
    }
    nuevaAdyacente[ vertices.mostrar_cantidad()][ vertices.mostrar_cantidad()] = 0;
}

void Grafo::liberarMatrizAdyacencia()
{
    for (int i = 0; i <  vertices.mostrar_cantidad(); i++)
    {
        delete[] matrizDeAdyacencia[i];
    }
    delete[] matrizDeAdyacencia;
}

Grafo::~Grafo()
{
    liberarMatrizAdyacencia();
    matrizDeAdyacencia = nullptr;
}

void Grafo::caminoMinimo(int origen, int destino, int &energia, Lista<Coordenada> & lista)
{
    dijkstra.construir(vertices, matrizDeAdyacencia);
    dijkstra.caminoMinimo(origen, destino, energia, lista);
}


