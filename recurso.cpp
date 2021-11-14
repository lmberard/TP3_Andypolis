#include "recurso.hpp"


Material * Recurso::dar_material(const string & material, int cantidad){
    Material* elemento;

    if(material == "piedra")
        elemento = new Piedra(cantidad);
    if(material == "madera")
        elemento = new Madera(cantidad);
    if(material == "metal")
        elemento = new  Metal(cantidad);
    return elemento;
}

Material * Recurso::dar_material(const string & material){
    Material* elemento;

    if(material == "piedra")
        elemento = new Piedra;
    if(material == "madera")
        elemento = new Madera;
    if(material == "metal")
        elemento = new  Metal;

    return elemento;
}

