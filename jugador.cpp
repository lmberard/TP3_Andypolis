#include "jugador.hpp"
//-----------------CONSTRUCTORES DESTRUCTORES----------------------------
Jugador::Jugador(int _id, int puntos_iniciales)
{
    id = _id;
    puntos_energia = puntos_iniciales;
    modificar_coordenada(posicion_jugador, 0, 0);
}

Jugador::Jugador()
{
    id = 0;
    puntos_energia = 0;
    modificar_coordenada(posicion_jugador, 0, 0);
}

Jugador::~Jugador()
{
}

//-------------------------GETTERS---------------------------------------
int Jugador::obtener_id()
{
    return id;
}

int Jugador::obtener_puntos_energia()
{
    return puntos_energia;
}

int Jugador::obtener_cant_andycoins()
{
    return 0;
}

int Jugador::obtener_cant_bombas()
{
    return 0;
}

int Jugador::obtener_cant_edificios_construidos(string nombre)
{
    for (int i = 1; i < edificios.mostrar_cantidad() + 1; i++)
    {
        if (edificios[i].nombre == nombre)
            return obtener_cantidad(edificios[i]);
    }
    return 0;
}
int Jugador::obtener_tam_lista_ubicaciones()
{
    return edificios.mostrar_cantidad();
}
//-------------------------SETTERS---------------------------------------
void Jugador::setear_objetivos_secundarios()
{
    cout << "FALTA ARMAR BIEN CLASE OBJETIVOS" << endl;
}

void Jugador::setear_objetivo_principal()
{
    cout << "FALTA ARMAR BIEN CLASE OBJETIVOS" << endl;
}

void Jugador::setear_id(int _id)
{
    id = _id;
}

//--------------------------PARA PARSER----------------------------------
//materiales.txt
void Jugador::agregar_material_al_inventario(string nombre, int cantidad, Recurso &recurso)
{
    inventario.agregar_material(nombre, cantidad, recurso);
}

//ubicaciones.txt
void Jugador::agregar_ubicacion_lista_edificios(string nombre, Coordenada coordenada_edificio)
{
    Ubicaciones nuevo_edificio_construido;
    setear_nombre(nuevo_edificio_construido, nombre);
    agregar_coordenada(nuevo_edificio_construido, coordenada_edificio);
    edificios.alta(nuevo_edificio_construido);
}

//------------------------MODIFICADORES----------------------------------
void Jugador::modificar_puntos_energia(int cantidad)
{
    puntos_energia += cantidad;
}

void Jugador::modificar_cant_material(string nombre_material, int cantidad)
{
    inventario.modificar_cant_material(nombre_material, cantidad);
}

/*esta funcion es lit lo mismo que la anterior pero para que sea mas legible quizas :) 
se podria hacer una tb para las bombas pero creo que es al pedo jeje 
la pueden borrar si no les cabe*/
void Jugador::modificar_andypoints(int cantidad)
{
    inventario.modificar_cant_material("andypoints", cantidad);
}

bool Jugador::eliminar_ubicacion_edificio(string nombre, Coordenada coordenada)
{
    //este for empieza en 1 asi por como esta implementada la lista, hay que recorrerlo asi
    for (int i = 1; i < edificios.mostrar_cantidad() + 1; i++)
    {
        if (edificios[i].nombre == nombre)
            return eliminar_coordenada(edificios[i], coordenada);
    }
    msjeError("Error: El jugador no tiene edificios construidos de ese estilo");
    return false;
}

void Jugador::agregar_materiales_reciclados(Edificio *edificio)
{
    inventario.llenar_stock(edificio);
}
//------------------------FUNCIONES UTILES-------------------------------
bool Jugador::se_quedo_sin_energia()
{
    return puntos_energia <= 0;
}

bool Jugador::cantidad_suficiente_material(Edificio *edificio, bool construir)
{
    //REVISAR ESTA FUNCION
    return inventario.chequear_stock(edificio, construir);
}

bool Jugador::es_su_edificio(string nombre, Coordenada coordenada)
{
    for (int i = 1; i < edificios.mostrar_cantidad() + 1; i++)
    {
        if (edificios[i].nombre == nombre)
            return tiene_esa_coordenada(edificios[i], coordenada);
    }
    msjeError("El jugador no tiene un edificio construido con ese nombre en esa coordenada");
    return false;
}

//------------------------OPCIONES JUGADOR-------------------------------
//GRAFO
void Jugador::moverse_a_coordenada(int x, int y)
{
    cout << "algoritmo camino minimo" << endl;
}

void Jugador::mostrar_objetivos_y_progreso()
{
    cout << "FALTA ARMAR BIEN CLASE OBJETIVOS" << endl;
}

void Jugador::mostrar_edificios_construidos()
{
    for (int i = 1; i < edificios.mostrar_cantidad() + 1; i++)
    {
        cout << "Tipo de edificio: " << edificios[i].nombre << endl;
        cout << "\tCantidad construida: " << to_string(obtener_cantidad(edificios[i])) << endl;
        mostrar_coordenadas(edificios[i]);
    }
}

void Jugador::mostrar_inventario()
{
    inventario.mostrar_inventario();
}
