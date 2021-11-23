#include "jugador.hpp"
//-----------------CONSTRUCTORES DESTRUCTORES----------------------------
Jugador::Jugador(int _id, int puntos_iniciales)
{
    id = _id;
    puntos_energia = puntos_iniciales;
    x = 0;
    y = 0;
}

Jugador::Jugador()
{
    id = 0;
    puntos_energia = 0;
    x = 0;
    y = 0;
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
void Jugador::agregar_ubicacion_lista_edificios(Ubicacion ubicacion)
{
    edificios.alta(ubicacion);
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

//CAMBIAR A LO DE BUILDING INFO DE PIPO Y GUILLE!
void Jugador::eliminar_ubicacion_edificio(Ubicacion ubicacion)
{
    //este for empieza en 1 asi por como esta implementada la lista, hay que recorrerlo asi
    for (int i = 1; i < edificios.mostrar_cantidad() + 1; i++)
    {
        if (edificios[i].nombre == ubicacion.nombre && edificios[i].coord_x == ubicacion.coord_x && edificios[i].coord_y == ubicacion.coord_y)
            edificios.baja(i);
    }
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

//CAMBIAR A LO DE BUILDING INFO DE PIPO Y GUILLE!
bool Jugador::es_su_edificio(Ubicacion ubicacion)
{
    for (int i = 1; i < edificios.mostrar_cantidad() + 1; i++)
    {
        if (edificios[i].nombre == ubicacion.nombre && edificios[i].coord_x == ubicacion.coord_x && edificios[i].coord_y == ubicacion.coord_y)
            return true;
    }
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

void Jugador::mostrar_inventario()
{
    inventario.mostrar_inventario();
}
