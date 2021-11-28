#include "edificioMinaOro.hpp"

MinaOro::MinaOro()
{
    caracteristicas();
}

void MinaOro::caracteristicas()
{
    nombre = "mina oro";
    codigo = "G";

    material_producido = "andycoins";
    cantidad_producida = 50;
}

int MinaOro::obtener_cantidad_producida()
{
    return  cantidad_producida;
}

string MinaOro::recurso_producido()
{
    return material_producido;
}