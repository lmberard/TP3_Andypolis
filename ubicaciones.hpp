#ifndef UBICACIONES_HPP
#define UBICACIONES_HPP

#include "lista.hpp"
#include "colors.hpp"

using namespace std;

struct Coordenada
{
    int coord_x;
    int coord_y;
};

struct Ubicaciones
{
    string nombre;
    Lista<Coordenada> coordenadas;
};


//---------------------STRUCT UBICACIONES--------------------------------
int obtener_cantidad(Ubicaciones info);

string obtener_nombre(Ubicaciones info);

void mostrar_coordenadas(Ubicaciones info);

bool eliminar_coordenada(Ubicaciones& info, Coordenada coordenada);

void agregar_coordenada(Ubicaciones& info, Coordenada coordenada);

void setear_nombre(Ubicaciones& info, string nombre);

bool tiene_esa_coordenada(Ubicaciones info, Coordenada coordenada);

//---------------------STRUCT COORDENADAS--------------------------------
void modificar_coordenada(Coordenada& coordenada, int x, int y);

bool coordenadas_son_iguales(Coordenada coord1, Coordenada coord2);

Coordenada crear_coordenada(int x, int y);

bool es_coordenada(string cadena);

bool esta_lista_vacia(Ubicaciones& info);

#endif // UBICACIONES_HPP