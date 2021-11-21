#ifndef _CELL_INTRANSITABLE_H_INCLUDED_
#define _CELL_INTRANSITABLE_H_INCLUDED_

#include "cell.h"

using namespace std;

class CellIntransitable: public Cell{

public:
    //PRE:
    //POST: Constructor de la clase. Se inicializan los atributos.
    CellIntransitable();

    //PRE:
    //POST: Constructor de la clase. Se inicializan los atributos.
    CellIntransitable(int, int, string);

    //PRE:
    //POST: Destructor de la clase
    ~CellIntransitable();

    //PRE:
    //POST: Este metodo imprime el casillero con el color correspondiente a un lago.
    void showCell();

    //PRE: -
    //POST: Este metodo imprime la informacion que representa lo que contiene la celda instransitable.
    void showCellInfo();
};

#endif