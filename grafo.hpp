#ifndef GRAFOS GRAFO_H
#define GRAFOS GRAFO_H
#include <string>
#include "lista.hpp"
#include "vertice.hpp"
const int INFINITO = 99999999;
using namespace std;

class Grafo
{
    /*ATRIBUTOS*/
private:
    int **matrizDeAdyacencia;
    Lista<Vertice> *vertices;
    /*MÉTODO */
    // pre: tienen que existir tanto el origen como el destino.
    // post: muestra el camino minimo entre el origeny el destino
    void caminoMinimo(int origen, int destino);
};

#endif
