#include "materialBomba.hpp"
#include <string>

using namespace std;

Bomba::Bomba() : Material()
{
    nombre = "bomba";
    codigo = "-";
}

Bomba::Bomba(int cantidad) : Material(cantidad){
    nombre = "bomba";
    codigo = "-";
}

Bomba::~Bomba()
{
}
