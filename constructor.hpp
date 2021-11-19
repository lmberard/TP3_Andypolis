#ifndef CONSTRUCTOR_H
#define CONSTRUCTOR_H
#include <fstream>
#include "lista.hpp"

#include "edificio.hpp"

#include "edificioAserradero.hpp"
#include "edificioEscuela.hpp"
#include "edificioYacimiento.hpp"
#include "edificioObelisco.hpp"
#include "edificioMina.hpp"
#include "edificioFabrica.hpp"
#include "edificioPlantaElectrica.hpp"

class Constructor
{
    Lista<Edificio *> edificios;

public:
    // PRE: -
    // POS:
    int buscar_edificio(string edificio);
    Constructor();
    // PRE: -
    // POS: Se construye el constructor con la informacion de los edificios en el archivo txt del path.
    Constructor(const string &PATH);

    void agregar_edificio(string nombre, int piedra, int madera, int metal, int permitidos);
    // PRE: -
    // POS: Elimina los edificios construidos en la lista de edificios
    ~Constructor();

    // PRE: -
    // POS: Construye segun el nombre del edificio y devuelve el edificio construido
    Edificio *construye(const string &edificio);

    // PRE: -
    // POS: Devuelve la cantidad de edificios en la lista de edificios
    int cant_edificios();

    // PRE:
    // POS: Muestra el edificio en la posicion i de la lista
    Edificio *mostrar_edificio(int i);
};

#endif // CONSTRUCTOR_H