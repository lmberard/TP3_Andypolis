#ifndef _CELL_BUILDABLE_H_INCLUDED_
#define _CELL_BUILDABLE_H_INCLUDED_

#include "cell.h"
#include "building.h"

using namespace std;

class CellBuildable: public Cell{
private:
    Building * ptrBuilding;
    bool isBuilt;

public:
    //PRE:
    //POST: Constructor de la clase. Se inicializan los atributos.
    CellBuildable();

    //PRE:
    //POST: Constructor de la clase. Se inicia en el atributo ptrBuilding una nueva instancia de la clase hija correspondiente 
    //      en funcion de la cadena recibida
    CellBuildable(string building);

    //PRE:
    //POST: Constructor de la clase. Se copian los parametros recibidos en los atributos de la clase
    CellBuildable(int, int, string);

    //PRE:
    //POST: Destructor de la clase
    ~CellBuildable();

    //PRE: - 
    //POST: Si hay un edificio construido, este metodo imprime el casillero con su identificador y color correspondiente. En caso contrario, solo imprime el casillero con su color correspondiente.
    void showCell();

    //PRE: -
    //POST: Este metodo imprime la informacion que representa lo que contiene la celda construible.
    void showCellInfo();

    //PRE:
    //POST: Este metodo devuelve el atributo isBuilt (hace referencia a si hay o no un edificio construido en la celda).
    bool getIsBuilt();

    //PRE: -
    //POST: Este metodo pide memoria, dentro de una celda, para un elemento de alguna de las clases hijas de building 
    //      (ej: escuela, fabrica, etc) dependiendo del identificador que se le pase. Con esto, se estara construyendo un edificio en esa celda. 
    void build(string building);

    //PRE:
    //POST: Este metodo devuelve true si demolio un edificio, y por referencia el nombre del edificio que fue demolido.
    bool demolish(string & demolishedBuilding);

    //PRE:
    //POST: Este metodo devuelve una instancia de la clase Building.
    Building getBuilding();
};

#endif