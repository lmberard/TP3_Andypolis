#include "vertice.hpp"


Vertice::Vertice(coordenada nombre)
{
    this->nombre = nombre;
}

void Vertice::obtenerNombre()
{
    cout << "(" << nombre.coord_x << "," << nombre.coord_y << ")";
}

coordenada Vertice::obtenerCoordenada()
{
    return nombre;
}

Vertice::~Vertice()
{
}
