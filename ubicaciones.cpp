#include "ubicaciones.hpp"
//---------------------STRUCT UBICACIONES--------------------------------
int obtener_cantidad(Ubicaciones info)
{
    return info.coordenadas.mostrar_cantidad();
}

string obtener_nombre(Ubicaciones info)
{
    return info.nombre;
}

void mostrar_coordenadas(Ubicaciones info)
{
    int cant_coordenadas = obtener_cantidad(info);
    for (int i = 1; i < cant_coordenadas + 1; i++)
    {
        cout << "\t->(" << info.coordenadas[i].coord_x << ", "
             << info.coordenadas[i].coord_y << ") " << endl;
    }
}

bool eliminar_coordenada(Ubicaciones info, Coordenada coordenada)
{
    int cant_coordenadas = obtener_cantidad(info);
    for (int i = 1; i < cant_coordenadas + 1; i++)
    {
        if (coordenadas_son_iguales(info.coordenadas[i], coordenada))
        {
            info.coordenadas.baja(i);
            return true;
        }
    }
    msjeError("No existe eso construido en esa coordenada.");
    return false;
}

void agregar_coordenada(Ubicaciones info, Coordenada coordenada)
{
    info.coordenadas.alta(coordenada);
}

void setear_nombre(Ubicaciones& info, string nombre)
{
    info.nombre = nombre;
}

bool tiene_esa_coordenada(Ubicaciones info, Coordenada coordenada)
{
    int cant_coordenadas = obtener_cantidad(info);
    for (int i = 1; i < cant_coordenadas + 1; i++)
    {
        if (coordenadas_son_iguales(info.coordenadas[i], coordenada))
            return true;
    }
    return false;
}

//---------------------STRUCT COORDENADAS--------------------------------
void modificar_coordenada(Coordenada& coordenada, int x, int y)
{
    coordenada.coord_x = x;
    coordenada.coord_y = y;
}

bool coordenadas_son_iguales(Coordenada coord1, Coordenada coord2)
{
    return (coord1.coord_y == coord2.coord_y && coord1.coord_x == coord2.coord_x);
}

Coordenada crear_coordenada(int x, int y)
{
    Coordenada coord;
    coord.coord_x = x;
    coord.coord_y = y;
    return coord;
}
