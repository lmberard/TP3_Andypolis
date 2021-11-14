#include "edificio.hpp"

Edificio::Edificio(int s, int w, int m, int p)
{
    piedra = s;
    madera = w;
    metal = m;
    cant_max_construccion = p;
    mat_que_produce = "";
    cant_mat_que_produce = 0;
}

Edificio::Edificio(Edificio * edificio)
{
    nombre = edificio->obtener_nombre();
    codigo = edificio->obtener_codigo();
    madera = edificio->obtener_madera();
    piedra = edificio->obtener_piedra();
    metal  = edificio->obtener_metal();
    cant_max_construccion = edificio->obtener_cant_max();
    mat_que_produce = edificio->obtener_mat_producido();
    cant_mat_que_produce = edificio->obtener_cant_mat_producido();
    //material1 = edificio->nombre_material1();
    //material2 = edificio->nombre_material2();
    //material3 = edificio->nombre_material3();
}

string Edificio::obtener_nombre()
{
    return nombre;
}

int Edificio::obtener_madera()
{
    return madera;
}

int Edificio::obtener_metal()
{
    return metal;
}

int Edificio::obtener_piedra()
{
    return piedra;
}

int Edificio::obtener_cant_max()
{
    return cant_max_construccion;
}

string Edificio::obtener_codigo()
{
    return codigo;
}

int Edificio::obtener_cant_mat_producido()
{
    return cant_mat_que_produce;
}

string Edificio::obtener_mat_producido()
{
    return mat_que_produce;
}

void Edificio::mostrar_edificio()
{
    cout << TXT_UNDERLINE << "TIPO DE EDIFICIO:" << END_COLOR << " " + nombre << endl;
    cout << "\tCantidad de piedra: " << to_string(piedra) << endl;
    cout << "\tCantidad de madera: " << to_string(madera) << endl;
    cout << "\tCantidad de metal: " << to_string(metal) << endl;
    cout << "\tUnidad máxima de construccion: " << to_string(cant_max_construccion) << endl;
    cout << "\tMaterial que produce: " << mat_que_produce << endl;
    cout << "\tCantidad de material que produce: " << to_string(cant_mat_que_produce) << endl;
    cout << endl;
}