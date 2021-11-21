#ifndef _CELL_H_INCLUDED_
#define _CELL_H_INCLUDED_

using namespace std;
#include "building.h"

class Cell{
protected:
    int coordinateX; 
    int coordinateY; 
    string cellIdentifier;
    
public:
    //PRE:
    //POST: Este metodo inicializa las coordenadas x,y y el cellIdentifier.
    Cell();

    //PRE:
    //POST: Constructor de la clase. Se copian los parametros recibidos en los atributos de la clase 
    Cell(int x, int y, string identif);

    //PRE:
    //POST: Destructor virtual de la clase Cell.
    virtual ~Cell() = 0;
    
    //PRE: -
    //POST: Este metodo setea el atributo cellIdentifier (identificador de la celda).
    void setCellIdentifier(string);

    //PRE: -
    //POST: Este metodo setea las coordenadas de la celda.
    void setCoordinates(int x, int y);

    //PRE: -
    //POST: Este metodo devuelve el identificador de la celda (L, F, R).
    string getCellIdentifier()const;

    //PRE: -
    //POST: Esta funcion devuelve la coordenada X de la celda.
    int getCoordinateX()const;

    //PRE:
    //POST: Esta funcion devuelve la coordenada Y de la celda.
    int getCoordinateY()const;

    //PRE: -
    //POST: Este metodo se ejecuta si o si en las clases hijas (metodo virtual)
    virtual void showCell() = 0;

    //PRE: -
    //POST: Este metodo se ejecuta si o si en las clases hijas (metodo virtual)
    virtual void showCellInfo() = 0;
};



#endif