#include "edificioEscuela.hpp"

Escuela::Escuela(int s, int w, int m, int p) : Edificio(s, w, m, p)
{
    nombre = "escuela";
    codigo = "E";

    vida = 1;
    
    produccion = "andycoins";
    cant_produccion = 25;
}

Escuela::Escuela(Edificio *edificio): Edificio(edificio){}

