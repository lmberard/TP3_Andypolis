#ifndef GRAFOS_DIJKSTRA_H
#define GRAFOS_DIJKSTRA_H

#include "caminoMinimo.hpp"
#include "listaNG.hpp"
#include "coordenada.hpp"

class Dijkstra : public CaminoMinimo
{
    // Atributos
private:
    bool *verticesVisitados;
    int *distancia;
    int *recorrido;

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
    void mostrarRecorrido(int origen, int destino, int & energia, ListaNG<coordenada> & lista);

    // post: muestra el estado instantaneo del vector de recorrido, distancia y visitados.
    void mostrarIteracion(int iteracion);

public:
    Dijkstra(ListaG<Vertice> *vertices, int **matrizAdyacencia);

    // post: muestra por pantalla el camino mínimo entre el origen y el destino, detallando su recorrido y peso
    void caminoMinimo(int origen, int destino, int & energia, ListaNG<coordenada> & lista) override;

    ~Dijkstra() override;
};

#endif // GRAFOS_DIJKSTRA_H
