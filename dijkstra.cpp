#include "dijkstra.hpp"

Dijkstra::Dijkstra(ListaG<Vertice> *vertices, int **matrizAdyacencia) : CaminoMinimo(vertices, matrizAdyacencia)
{
    verticesVisitados = new bool[cantidadVertices];
    distancia = new int[cantidadVertices];
    recorrido = new int[cantidadVertices];
}

void Dijkstra::caminoMinimo(int origen, int destino, int & energia, Lista<Coordenada> & lista)
{
    inicializarVisitados(origen);
    inicializarDistancia(matrizAdyacencia[origen]);
    inicializarRecorrido(origen);

    int minimoVertice;

    bool destinoArribado = origen == destino;
    int verticesRecorridos = 1;
    while (!destinoArribado)
    {
        //mostrarIteracion(verticesRecorridos - 1);
        minimoVertice = verticeMinimaDistancia();
        destinoArribado = minimoVertice == destino;

        if (!destinoArribado)
        {
            verticesVisitados[minimoVertice] = true;
            actualizarDistancia(minimoVertice);
        }
        verticesRecorridos++;
    }

    mostrarRecorrido(origen, destino, energia, lista);
}

int Dijkstra::verticeMinimaDistancia()
{
    int minimaDistancia = INFINITO;
    int minimoVertice;

    for (int i = 0; i < cantidadVertices; i++)
    {
        if (!verticesVisitados[i] && distancia[i] <= minimaDistancia)
        {
            minimaDistancia = distancia[i];
            minimoVertice = i;
        }
    }

    return minimoVertice;
}

void Dijkstra::inicializarVisitados(int origen)
{
    for (int i = 0; i < cantidadVertices; i++)
        verticesVisitados[i] = false;
    verticesVisitados[origen] = true;
}

void Dijkstra::inicializarRecorrido(int origen)
{
    for (int i = 0; i < cantidadVertices; i++)
        recorrido[i] = origen;
}

Dijkstra::~Dijkstra()
{
    delete[] verticesVisitados;
    delete[] distancia;
    delete[] recorrido;
}

void Dijkstra::inicializarDistancia(const int *distanciaOrigen)
{
    for (int i = 0; i < cantidadVertices; i++)
        distancia[i] = distanciaOrigen[i];
}

void Dijkstra::actualizarDistancia(int vertice)
{
    for (int i = 0; i < cantidadVertices; i++)
    {
        if (!verticesVisitados[i] && distancia[vertice] != INFINITO && distancia[i] > matrizAdyacencia[vertice][i] + distancia[vertice])
        {
            distancia[i] = matrizAdyacencia[vertice][i] + distancia[vertice];
            recorrido[i] = vertice;
        }
    }
}

void Dijkstra::mostrarRecorrido(int origen, int destino, int & energia, Lista<Coordenada> & lista)
{
    if (distancia[destino] == INFINITO)
    {
        cout << "No hay un camino que conecte (" << vertices->obtenerNombre(origen + 1).coord_x << "," << vertices->obtenerNombre(origen + 1).coord_y << ") con (" << vertices->obtenerNombre(destino + 1).coord_x << "," <<  vertices->obtenerNombre(destino + 1).coord_y << ")";
    }
    else
    {
        cout << "El camino minimo que une (" << vertices->obtenerNombre(origen + 1).coord_x << "," << vertices->obtenerNombre(origen + 1).coord_y << ") con (" << vertices->obtenerNombre(destino + 1).coord_x << "," <<  vertices->obtenerNombre(destino + 1).coord_y << ")";
        cout << " tiene un costo de: " << distancia[destino] << " y es el siguiente: ";
        energia = distancia[destino];
        cout << "(" << vertices->obtenerNombre(destino + 1).coord_x << "," << vertices->obtenerNombre(destino + 1).coord_y << ")" ;
        lista.alta(vertices->obtenerNombre(destino + 1));
        do
        {
            destino = recorrido[destino];
            cout << " <- (" << vertices->obtenerNombre(destino + 1).coord_x << "," << vertices->obtenerNombre(destino + 1).coord_y << ")" ;
            lista.alta(vertices->obtenerNombre(destino + 1));
        } while (origen != destino);
    }
    cout << endl;
}

void Dijkstra::mostrarIteracion(int iteracion)
{
    cout << endl
         << "Iteración " << iteracion << endl;

    cout << "Visitados: [";
    for (int i = 0; i < cantidadVertices; i++)
    {
        cout << verticesVisitados[i];
        if (i + 1 != cantidadVertices)
        {
            cout << ", ";
        }
    }
    cout << "]" << endl;

    cout << "Distancia: [";
    for (int i = 0; i < cantidadVertices; i++)
    {
        if (distancia[i] != INFINITO)
        {
            cout << distancia[i];
        }
        else
        {
            cout << "∞";
        }
        if (i + 1 != cantidadVertices)
        {
            cout << ", ";
        }
    }
    cout << "]" << endl;

    cout << "Recorrido: [";
    for (int i = 0; i < cantidadVertices; i++)
    {
        cout << "(" << vertices->obtenerNombre(recorrido[i] + 1).coord_x << "," << vertices->obtenerNombre(recorrido[i] + 1).coord_y << ")";
        if (i + 1 != cantidadVertices)
        {
            cout << ", ";
        }
    }
    cout << "]" << endl
         << endl;
}