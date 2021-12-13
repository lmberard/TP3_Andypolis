#include "andycoins.hpp"
#include <string>

using namespace std;

Andycoins::Andycoins() : Material()
{
    nombre = "andycoins";
    codigo = "C";
}

Andycoins::Andycoins(int cantidad) : Material(cantidad){
    nombre = "andycoins";
    codigo = "C";
}

Andycoins::~Andycoins()
{
}
