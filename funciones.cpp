#include "funciones.hpp"

bool char_son_iguales(char &c1, char &c2)
{
    if (c1 == c2)
        return true;
    else if (toupper(c1 == toupper(c2)))
        return true;
    return false;
}

int generar_valor_random(int desde, int hasta)
{
    return (rand() % (desde + hasta - desde) + desde);
}