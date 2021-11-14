#include "materialMetal.hpp"
#include <string>

using namespace std;

Metal::Metal() : Material()
{
    nombre = "metal";
    codigo = "M";
}

Metal::Metal(int cantidad) : Material(cantidad){
    nombre = "metal";
    codigo = "M";
}

Metal::~Metal()
{
}
