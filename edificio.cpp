#include "edificio.hpp"

Edificio::Edificio(int s, int w, int m, int p)
{
    piedra = s;
    madera = w;
    metal = m;

    cantidad_permitida = p;
}

Edificio::Edificio(Edificio *edificio)
{
    nombre = edificio->obtener_nombre();
    codigo = edificio->obtener_codigo();
    
    madera = edificio->obtener_madera();
    piedra = edificio->obtener_piedra();
    metal = edificio->obtener_metal();
    
    cantidad_permitida = edificio->obtener_cant_max();
    
    produccion = edificio->obtener_tipo_produccion();
    cant_produccion = edificio->obtener_cant_produccion();

    vida = edificio->obtener_vida();
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
    return cantidad_permitida;
}

string Edificio::obtener_codigo()
{
    return codigo;
}

int Edificio::obtener_cant_produccion()
{
    return cant_produccion;
}

string Edificio::obtener_tipo_produccion()
{
    return produccion;
}

int Edificio::obtener_vida()
{
    return vida;
}

void Edificio::bajar_vida()
{
    vida--;
}

void Edificio::subir_vida()
{
    vida++;
}

void Edificio::setear_madera(int madera){
    this->madera = madera;
}

void Edificio::setear_piedra(int piedra){
    this->piedra = piedra;
}

void Edificio::setear_metal(int metal){
    this->metal = metal;
}