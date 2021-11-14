#include "material.hpp"
#include <string>

using namespace std;

Material::Material()
{
    cantidad = 1;
}

Material::Material(int cantidad)
{
    this->cantidad = cantidad;
}

Material::~Material() {}

string Material::obtener_nombre()
{
    return nombre;
}

string Material::obtener_codigo()
{
    return codigo;
}

int Material::obtener_cantidad()
{
    return cantidad;
}

void Material::modificar_cantidad(int cantidad)
{
    this->cantidad = cantidad;
}