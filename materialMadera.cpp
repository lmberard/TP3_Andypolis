#include "materialMadera.hpp"
#include <string>

using namespace std;

Madera::Madera() : Material()
{
    nombre = "madera";
    codigo = "W";
}

Madera::Madera(int cantidad) : Material(cantidad){
    nombre = "madera";
    codigo = "W";
}

Madera::~Madera()
{
}
