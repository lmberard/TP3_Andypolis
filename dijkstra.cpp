#include "dijkstra.hpp"

void Dijkstra::construir(Lista<Coordenada> & vertices, int **matrizAdyacencia)
{
    this->vertices = vertices;
    this->matrizAdyacencia = matrizAdyacencia;
    cantidadVertices = vertices.mostrar_cantidad();

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

//DEBERIA ESTAR ARAFUE PERO BUEN
void Dijkstra::mostrarRecorrido(int origen, int destino, int & energia, Lista<Coordenada> & lista)
{
    if (distancia[destino] == INFINITO)
    {
        cout << "No hay un camino que conecte (" << vertices[origen + 1].coord_x << "," << vertices[origen + 1].coord_y << ") con (" << vertices[destino + 1].coord_x << "," <<  vertices[destino + 1].coord_y << ")";
    }
    else
    {
        cout << "El camino minimo que une (" << vertices[origen + 1].coord_x << "," << vertices[origen + 1].coord_y << ") con (" << vertices[destino + 1].coord_x << "," <<  vertices[destino + 1].coord_y << ")";
        cout << " tiene un costo de: " << distancia[destino] << " y es el siguiente: ";
        energia = distancia[destino];
        cout << "(" << vertices[destino + 1].coord_x << "," << vertices[destino + 1].coord_y << ")" ;
        lista.alta(vertices[destino + 1]);
        do
        {
            destino = recorrido[destino];
            cout << " <- (" << vertices[destino + 1].coord_x << "," << vertices[destino + 1].coord_y << ")" ;
            lista.alta(vertices[destino + 1]);
        } while (origen != destino);
    }
    cout << endl;
}
