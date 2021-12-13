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

bool eliminar_coordenada(Ubicaciones& info, Coordenada coordenada)
{
    bool estado = false;
    int cant_coordenadas = obtener_cantidad(info);

    for (int i = 1; i < cant_coordenadas + 1 && (estado == false); i++)
    {
        if (coordenadas_son_iguales(info.coordenadas[i], coordenada))
        {
            info.coordenadas.baja(i);
            estado = true;
        }
    }

    if(estado == false)
        msjeError("No existe eso construido en esa coordenada.");
    
    return estado;
}

void agregar_coordenada(Ubicaciones& info, Coordenada coordenada)
{
    info.coordenadas.alta(coordenada);
}

void setear_nombre(Ubicaciones& info, string nombre)
{
    info.nombre = nombre;
}

bool tiene_esa_coordenada(Ubicaciones info, Coordenada coordenada)
{
    bool esta_la_coordenada = false;
    int cant_coordenadas = obtener_cantidad(info);

    for (int i = 1; i < cant_coordenadas + 1 && (esta_la_coordenada == false); i++)
    {
        if (coordenadas_son_iguales(info.coordenadas[i], coordenada)){
            esta_la_coordenada = true;
        }
    }
    
    return esta_la_coordenada;
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

bool es_coordenada(string cadena){
    bool estado = true;

    if (cadena.length() == 0)
        estado = false;

    for (unsigned int i = 0; i < cadena.length(); i++){
        if (!isdigit(cadena[i]))
            estado = false;
    }

    return estado;
}

bool es_numero_y_positivo(string cadena){
    bool estado = true;

    if (cadena.length() == 0)
        estado = false;

    for (unsigned int i = 0; i < cadena.length(); i++){
        if (!isdigit(cadena[i]))
            estado = false;
    }

    return estado;
}

bool esta_lista_vacia(Ubicaciones& info){
    return obtener_cantidad(info) == 0;
}

bool operator==(const Coordenada& lhs, const Coordenada& rhs)
{
    if((lhs.coord_x == rhs.coord_x) && (lhs.coord_y == rhs.coord_y))
        return true;
    
    return false;
}

