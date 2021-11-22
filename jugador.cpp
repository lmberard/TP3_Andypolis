#include "jugador.hpp"

Jugador::Jugador(int _id, Ubicacion _ubicacion, int puntos_iniciales)
{
    id = _id;
    ubicacion = _ubicacion;
    puntos_energia = puntos_iniciales;
}

Jugador::~Jugador()
{
}

void Jugador::setear_objetivos_secundarios()
{
    cout << "FALTA ARMAR BIEN CLASE OBJETIVOS" << endl;
}

void Jugador::setear_objetivo_principal()
{
    cout << "FALTA ARMAR BIEN CLASE OBJETIVOS" << endl;
}

int Jugador::obtener_id()
{
    return id;
}

int Jugador::obtener_puntos_energia()
{
    return puntos_energia;
}

void Jugador::modificar_puntos_energia(int cantidad)
{
    puntos_energia += cantidad;
}

bool Jugador::se_quedo_sin_energia()
{
    return puntos_energia <= 0;
}

//GRAFO
void Jugador::moverse_a_coordenada(int x, int y)
{
    cout << "algoritmo camino minimo" << endl;
}

bool Jugador::cantidad_suficiente_material(Edificio *edificio, bool construir)
{
    return inventario.chequear_stock(edificio, construir);
}

void Jugador::modificar_inventario(string nombre_material, int cantidad)
{
    cout << "no estoy segura de esto" << endl;
}

void Jugador::modificar_lista_edificios(string edificio, Ubicacion ubicacion)
{
    cout << "no estoy segura de esto" << endl;
}

bool Jugador::es_su_edificio(string nombre_edificio, Ubicacion ubicacion)
{
    return true;
}

void Jugador::modificar_andypoints(int cantidad)
{
    cout << "ver en inventario" << endl;
}

int Jugador::obtener_cant_andycoins()
{
    return 0;
}

int Jugador::obtener_cant_bombas()
{
    return 0;
}

void Jugador::mostrar_objetivos_y_progreso()
{
    cout << "FALTA ARMAR BIEN CLASE OBJETIVOS" << endl;
}

void Jugador::mostrar_inventario()
{
    inventario.mostrar_inventario();
}
