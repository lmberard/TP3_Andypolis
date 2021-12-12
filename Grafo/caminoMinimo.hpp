#ifndef GRAFOS_CAMINOMINIMO_H
#define GRAFOS_CAMINOMINIMO_H
#include <string>
#include "listaG.hpp"
#include "vertice.hpp"
#include "listaNG.hpp"
#include "coordenada.hpp"
#include <iostream>

const int INFINITO = 99999999;

class CaminoMinimo
{
    // Atributos
protected:
    int **matrizAdyacencia;
    ListaG<Vertice> *vertices;
    int cantidadVertices;

    // Métodos
public:
    CaminoMinimo(ListaG<Vertice> *vertices, int **matrizAdyacencia);

    // post: muestra por pantalla el camino mínimo entre el origen y el destino, detallando su recorrido y peso
    virtual void caminoMinimo(int origen, int destino, int & energia, ListaNG<coordenada> & lista) = 0;

    virtual ~CaminoMinimo() = default;
};

#endif // GRAFOS_CAMINOMINIMO_H
