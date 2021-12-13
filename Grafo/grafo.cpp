#include "grafo.hpp"
#include "dijkstra.hpp"
#include <iostream>

Grafo::Grafo()
{
    matrizDeAdyacencia = nullptr;
    vertices = new ListaG<Vertice>();
    algoritmoCaminoMinimo = nullptr;
}

void Grafo::agregarVertice(Coordenada nuevoVertice)
{
    agrandarMatrizDeAdyacencia();
    vertices->agregar(nuevoVertice);
}

void Grafo::mostrarGrafo()
{
    mostrarVertices();
    mostrarMatrizAdyacencia();
}

void Grafo::agregarCamino(Coordenada origen, Coordenada destino, int peso)
{
    int posicionOrigen = vertices->obtenerPosicion(origen);
    int posicionDestino = vertices->obtenerPosicion(destino);

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
        //matrizDeAdyacencia[posicionDestino][posicionOrigen] = peso;
    }
}

void Grafo::caminoMinimo(Coordenada origen, Coordenada destino, int & energia, Lista<Coordenada> & lista )
{
    int posicionOrigen = vertices->obtenerPosicion(origen);
    int posicionDestino = vertices->obtenerPosicion(destino);

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
    int nuevaCantidadDeVertices = vertices->obtenerCantidadDeElementos() + 1;

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
    for (int i = 0; i < vertices->obtenerCantidadDeElementos(); i++)
    {
        for (int j = 0; j < vertices->obtenerCantidadDeElementos(); j++)
        {
            nuevaAdyacente[i][j] = matrizDeAdyacencia[i][j];
        }
    }
}

void Grafo::inicializarNuevoVertice(int **nuevaAdyacente)
{
    for (int i = 0; i < vertices->obtenerCantidadDeElementos(); i++)
    {
        nuevaAdyacente[vertices->obtenerCantidadDeElementos()][i] = INFINITO;
        nuevaAdyacente[i][vertices->obtenerCantidadDeElementos()] = INFINITO;
    }
    nuevaAdyacente[vertices->obtenerCantidadDeElementos()][vertices->obtenerCantidadDeElementos()] = 0;
}

void Grafo::liberarMatrizAdyacencia()
{
    for (int i = 0; i < vertices->obtenerCantidadDeElementos(); i++)
    {
        delete[] matrizDeAdyacencia[i];
    }
    delete[] matrizDeAdyacencia;
}

Grafo::~Grafo()
{
    liberarMatrizAdyacencia();
    matrizDeAdyacencia = nullptr;
    delete vertices;
    delete algoritmoCaminoMinimo;
}

void Grafo::mostrarVertices()
{
    cout << "Lista de vértices: [";
    for (int i = 0; i < vertices->obtenerCantidadDeElementos(); i++)
    {
        //cout << vertices->obtenerNombre(i + 1);
        cout << vertices->obtenerNombre(i + 1).coord_x << "," << vertices->obtenerNombre(i + 1).coord_y;
        if (i + 1 != vertices->obtenerCantidadDeElementos())
        {
            cout << "; ";
        }
    }
    cout << "]" << endl;
}

void Grafo::mostrarMatrizAdyacencia()
{
    cout << "Matriz de adyacencia:" << endl;
    for (int i = 0; i < vertices->obtenerCantidadDeElementos(); i++)
    {
        for (int j = 0; j < vertices->obtenerCantidadDeElementos() * 2; j++)
        {
            if (j == vertices->obtenerCantidadDeElementos() * 2 - 1)
            {
                cout << endl;
            }
            else if (j % 2 == 0)
            {
                if (matrizDeAdyacencia[i][j / 2] == INFINITO)
                {
                    cout << "∞";
                }
                else
                {
                    cout << matrizDeAdyacencia[i][j / 2];
                }
            }
            else
            {
                cout << "|";
            }
        }
    }
    cout << endl;
}

void Grafo::caminoMinimo(int origen, int destino, int &energia, Lista<Coordenada> & lista)
{
    algoritmoCaminoMinimo->caminoMinimo(origen, destino, energia, lista);
}
/*
void Grafo::usarFloyd()
{
    delete algoritmoCaminoMinimo;
    algoritmoCaminoMinimo = new Floyd(vertices, matrizDeAdyacencia);
}*/

void Grafo::usarDijkstra()
{
    delete algoritmoCaminoMinimo;
    algoritmoCaminoMinimo = new Dijkstra(vertices, matrizDeAdyacencia);
}
