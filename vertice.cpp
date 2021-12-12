#include "vertice.hpp"


Vertice::Vertice(Coordenada nombre)
{
    this->nombre = nombre;
}

void Vertice::obtenerNombre()
{
    cout << "(" << nombre.coord_x << "," << nombre.coord_y << ")";
}

Coordenada Vertice::obtenerCoordenada()
{
    return nombre;
}

Vertice::~Vertice()
{
}
