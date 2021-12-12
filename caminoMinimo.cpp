#include "caminoMinimo.hpp"

CaminoMinimo::CaminoMinimo(ListaG<Vertice> *vertices, int **matrizAdyacencia)
{
    this->vertices = vertices;
    this->matrizAdyacencia = matrizAdyacencia;
    cantidadVertices = vertices->obtenerCantidadDeElementos();
}
