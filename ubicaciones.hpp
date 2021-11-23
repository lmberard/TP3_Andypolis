#ifndef UBICACIONES_HPP
#define UBICACIONES_HPP

#include <iostream>
#include <string>
#include <fstream>
#include "lista.hpp"
#include "colors.hpp"

using namespace std;

struct Ubicaciones
{
    string nombre;
    Lista<Coordenada> coordenadas;
};
struct Coordenada
{
    int coord_x;
    int coord_y;
};

//---------------------STRUCT UBICACIONES--------------------------------
int obtener_cantidad(Ubicaciones info_edificio);

void mostrar_coordenadas(Ubicaciones info_edificio);

bool eliminar_coordenada(Ubicaciones info_edificio, Coordenada coordenada);

void agregar_coordenada(Ubicaciones info_edificio, Coordenada coordenada);

void setear_nombre(Ubicaciones info_edificio, string nombre);

bool tiene_esa_coordenada(Ubicaciones info_edificio, Coordenada coordenada);

//---------------------STRUCT COORDENADAS--------------------------------
void modificar_coordenada(Coordenada coordenada, int x, int y);

bool coordenadas_son_iguales(Coordenada coord1, Coordenada coord2);

#endif // UBICACIONES_HPP
