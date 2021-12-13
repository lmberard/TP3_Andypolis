#ifndef GRAFOS_DIJKSTRA_H
#define GRAFOS_DIJKSTRA_H

#include "lista.hpp"
#include "ubicaciones.hpp"

const int INFINITO = 99999999;

class Dijkstra
{
    // Atributos
private:
    bool *verticesVisitados;
    int *distancia;
    int *recorrido;

    int **matrizAdyacencia;
    Lista<Coordenada> vertices;
    int cantidadVertices;

    // Métodos
    // post: pone todos los valores del vector de verticesVisitados en "false" menos el origen
    void inicializarVisitados(int origen);

    // post: pone las distancias exactamente igual que la distanciaOrigen
    void inicializarDistancia(const int *distanciaOrigen);

    // post: llena el vector de recorrido con el origen
    void inicializarRecorrido(int origen);

    // post: devuelve el número de vértice con menor distancia al origen
    int verticeMinimaDistancia();

    // post: actualiza el vector de distancias y el de recorrido con los valores que impone vertice.
    void actualizarDistancia(int vertice);

    // pre: para que tenga sentido, debe ejecutarse un recorrido previamente
    // post: muestra por pantalla el resultado del recorrido.
    void mostrarRecorrido(int origen, int destino, int & energia, Lista<Coordenada> & lista);


public: //no iria con punteros

    Dijkstra(){};

    void construir(Lista<Coordenada> & vertices, int **matrizAdyacencia);

    // post: muestra por pantalla el camino mínimo entre el origen y el destino, detallando su recorrido y peso
    void caminoMinimo(int origen, int destino, int & energia, Lista<Coordenada> & lista);

    ~Dijkstra();
};

#endif // GRAFOS_DIJKSTRA_H
