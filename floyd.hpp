#ifndef GRAFOS_FLOYD_H
#define GRAFOS FLOYD_H

#include "caminoMinimo.hpp"

using namespace std;

class Floyd : public CaminoMinimo
{
private:
    int **matrizCostos;
    int **matrizCaminos;

    // pre: requiere una matriz de adyacencia bien cargada
    // post: crea la matriz costo inicializandola con los valores de la matriz de adyacencia
    int **crearMatrizCostos(int **matrizAdyacencia);

    // post: crea una matriz de caminos
    int **crearMatrizCaminos();

    // post: libera la memoria de las matrices de costos y caminos
    void liberarMatrices();

    // post: muestra la matriz de cossto y de caminos.
    void mostrarMatrices();

    // post : calcula las matrices de costos y caminos.
    void calcularMatrices();

public:
    Floyd(Lista<Vertice> *vertices, int **matrizAdyacencia);

    // post: muestra por pantalla el camino minimo entre el origen y el destino, detallando su recorrido y peso
    void caminoMinimo(int origen, int destino) override;

    ~Floyd() override;
};

#endif
