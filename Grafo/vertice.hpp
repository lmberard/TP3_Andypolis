#ifndef GRAFOS_VERTICE_H
#define GRAFOS_VERTICE_H

#include <string>
#include <iostream>
#include "coordenada.hpp"

using namespace std;

class Vertice {
/*ATRIBUTOS*/
private:
    coordenada nombre;

/*MÉTODOS*/
public:
    Vertice(coordenada nombre);

    //post: obtiene el nombre del vertice
    void obtenerNombre();

    ~Vertice();

    coordenada obtenerCoordenada();
};


#endif //GRAFOS_VERTICE_H
