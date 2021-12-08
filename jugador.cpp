#include "jugador.hpp"
//-----------------CONSTRUCTORES DESTRUCTORES----------------------------

Jugador::Jugador()
{
    id = 0;
    puntos_energia = 0;
    modificar_coordenada(posicion_jugador, 0, 0);
}

Jugador::~Jugador()
{
    for(int i = 1; i < objetivos.mostrar_cantidad()+1;i++)
        delete objetivos[i];
}

//-------------------------GETTERS---------------------------------------

Coordenada Jugador::obtener_posicion_jugador()
{
    return posicion_jugador;
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

Lista<Ubicaciones> & Jugador::lista_edificios()
{
    return edificios;
}

int Jugador::obtener_energia()
{
    return puntos_energia;
}
//-------------------------SETTERS---------------------------------------

void Jugador::setear_posicion(Coordenada coord)
{
    modificar_coordenada(posicion_jugador, coord.coord_x, coord.coord_y);
}
//--------------------------PARA PARSER----------------------------------
//materiales.txt
void Jugador::agregar_material_al_inventario(Material* material)
{
    inventario.agregar_material(material);
}

//ubicaciones.txt
void Jugador::agregar_ubicacion_lista_edificios(string nombre, Coordenada coordenada_edificio)
{
    //TODO: MODIFIQUE ESTO
    for (int i = 1; i < edificios.mostrar_cantidad() + 1; i++)
    {
        if (edificios[i].nombre == nombre){
            agregar_coordenada(edificios[i], coordenada_edificio);
            return;
        }
    }   

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

bool Jugador::eliminar_ubicacion_edificio(string nombre, Coordenada coordenada)
{
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

//MARIANO: DUDA
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

bool Jugador::tiene_energia(int cantidad_necesaria)
{
    return puntos_energia >= cantidad_necesaria;
}

void Jugador::asignar_objetivos_jugador(Objetivo * objetivo){
    objetivos.alta(objetivo);
}

//------------------------OPCIONES JUGADOR-------------------------------
//GRAFO
/*-----------------------------VER-----------------------------------------*/
void Jugador::moverse_a_coordenada(int x, int y)
{
    cout << "algoritmo camino minimo" << endl;
}
/*-------------------------------------------------------------------------*/
void Jugador::mostrar_objetivos_y_progreso()
{
    for(int i = 1; i < objetivos.mostrar_cantidad()+1;i++){
        cout << objetivos[i]->obtener_objetivo() << endl;
    }
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

bool Jugador::gano()
{
    int objetivos_cumplidos = 0;
    bool gano = false;

    for(int i = 1; i < objetivos.mostrar_cantidad()+1;i++){
        if(objetivos[i]->es_principal() && objetivos[i]->cumplido())
            gano = true;
        if(objetivos[i]->cumplido())
            objetivos_cumplidos++;
    }
    if(objetivos_cumplidos == 2)
        gano = true;

    return gano;
}

void Jugador::chequear_objetivos(bool fin_turno, Constructor & bob)
{
    for(int i = 1; i < objetivos.mostrar_cantidad()+1; i++)
        objetivos[i]->chequear_estado(inventario, puntos_energia, edificios, bob, fin_turno);
}
