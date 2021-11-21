#ifndef _CELL_PASSABLE_H_INCLUDED_
#define _CELL_PASSABLE_H_INCLUDED_

#include "cell.h"
#include "materials.h"

using namespace std;

class CellPassable: public Cell{
private:
    Materials material;

public:
    //PRE:
    //POST: Constructor de la clase. Se inicializan los atributos.
    CellPassable();

    //PRE:
    //POST: Constructor de la clase. Se inicializan los atributos.
    CellPassable(int, int, string);

    //PRE:
    //POST: Destructor de la clase
    ~CellPassable();

    //PRE:
    //POST: Si hay un material en el camino, este metodo imprime el casillero con el identificador del material y color correspondiente. En caso contrario, solo imprime el casillero con su color correspondiente.
    void showCell();

    //PRE: -
    //POST: Este metodo imprime la informacion que representa lo que contiene la celda transitable.
    void showCellInfo();

    //PRE:
    //POST: Modifica los atributos del material que aparece en el camino en funcion del material recibido. 
    void addMaterial(string material1);

    //PRE:
    //POST: Retorna por referencia el atributo material (instancia de la clase Materials)
    Materials& getMaterial();
};

#endif