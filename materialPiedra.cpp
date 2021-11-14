#include "materialPiedra.hpp"
#include <string>

using namespace std;

Piedra::Piedra() : Material()
{
    nombre = "piedra";
    codigo = "S";
}

Piedra::Piedra(int cantidad) : Material(cantidad)
{
    nombre = "piedra";
    codigo = "S";
}

Piedra::~Piedra(){}
