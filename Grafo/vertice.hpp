#ifndef GRAFOS_VERTICE_H
#define GRAFOS_VERTICE_H

#include <string>
#include <iostream>
#include "ubicaciones.hpp"

using namespace std;

class Vertice {
/*ATRIBUTOS*/
private:
    Coordenada nombre;

/*MÉTODOS*/
public:
    Vertice(Coordenada nombre);

    //post: obtiene el nombre del vertice
    void obtenerNombre();

    ~Vertice();

    Coordenada obtenerCoordenada();
};


#endif //GRAFOS_VERTICE_H
