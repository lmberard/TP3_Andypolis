#include "ubicaciones.hpp"
//---------------------STRUCT UBICACIONES--------------------------------
int obtener_cantidad(Ubicaciones info_edificio)
{
    return info_edificio.coordenadas.mostrar_cantidad();
}

void mostrar_coordenadas(Ubicaciones info_edificio)
{
    int cant_coordenadas = obtener_cantidad(info_edificio);
    for (int i = 1; i < cant_coordenadas + 1; i++)
    {
        cout << "\t->(" << info_edificio.coordenadas[i].coord_x << ", "
             << info_edificio.coordenadas[i].coord_y << ") " << endl;
    }
}

bool eliminar_coordenada(Ubicaciones info_edificio, Coordenada coordenada)
{
    int cant_coordenadas = obtener_cantidad(info_edificio);
    for (int i = 1; i < cant_coordenadas + 1; i++)
    {
        if (coordenadas_son_iguales(info_edificio.coordenadas[i], coordenada))
        {
            info_edificio.coordenadas.baja(i);
            return true;
        }
    }
    msjeError("No existe eso construido en esa coordenada.");
    return false;
}

void agregar_coordenada(Ubicaciones info_edificio, Coordenada coordenada)
{
    info_edificio.coordenadas.alta(coordenada);
}

void setear_nombre(Ubicaciones info_edificio, string nombre)
{
    info_edificio.nombre = nombre;
}

bool tiene_esa_coordenada(Ubicaciones info_edificio, Coordenada coordenada)
{
    int cant_coordenadas = obtener_cantidad(info_edificio);
    for (int i = 1; i < cant_coordenadas + 1; i++)
    {
        if (coordenadas_son_iguales(info_edificio.coordenadas[i], coordenada))
            return true;
    }
    return false;
}

//---------------------STRUCT COORDENADAS--------------------------------
void modificar_coordenada(Coordenada coordenada, int x, int y)
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
