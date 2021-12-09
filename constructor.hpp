#ifndef CONSTRUCTOR_H
#define CONSTRUCTOR_H

#include "lista.hpp"
#include "ABB.hpp"

#include "edificio.hpp"

#include "edificioAserradero.hpp"
#include "edificioEscuela.hpp"
#include "edificioYacimiento.hpp"
#include "edificioObelisco.hpp"
#include "edificioMina.hpp"
#include "edificioMinaOro.hpp"
#include "edificioFabrica.hpp"
#include "edificioPlantaElectrica.hpp"

class Constructor
{
    Lista<string> edificios;
    ABB<Edificio,string> diccionario;

public:
    // PRE: -
    // POS:
    Constructor();
    
    // PRE: -
    // POS:
    void agregar_edificio(string nombre, int piedra, int madera, int metal, int permitidos);

    // PRE: -
    // POS: Construye segun el nombre del edificio y devuelve el edificio construido
    Edificio *construye(const string &edificio);

    // PRE:
    // POS: Muestra el edificio en la posicion i de la lista
    Edificio *mostrar_edificio(int i);

    // PRE:
    // POS: Muestra el edificio en la posicion i de la lista
    Edificio *mostrar_edificio(string & edificio);

    // PRE: -
    // POS: Devuelve la cantidad de edificios en la lista de edificios
    int cant_edificios();

};

#endif // CONSTRUCTOR_H
