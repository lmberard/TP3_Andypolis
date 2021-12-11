#ifndef GRAFOS_CAMINOMINIMO_H
#define GRAFOS CAMINOMINIMO H
#include <string>
#include "lista.hpp"
#include "vertice.hpp"
#include <iostream>

const int INFINITO = 99999999;
class CaminoMinimo
{
    // Atributos
protected:
    int **matrizAdyacencia;
    Lista<Vertice> *vertices;
    int cantidadVertices;

    // Métodos
public:
    CaminoMinimo(Lista<Vertice> *vertices, int **matrizAdyacencia);
    // post: muestra por pantalla el camino minimo entre el origen y el destino, detallando su recorrido y peso
    virtual void caminoMinimo(int origen, int destino) = 0;
    virtual ~CaminoMinimo() = default;
};

#endif // GRAFOS CAMINOMINIMO H
