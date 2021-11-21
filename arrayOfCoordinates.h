#ifndef _ARRAY_OF_COORDINATES_H_INCLUDED_
#define _ARRAY_OF_COORDINATES_H_INCLUDED_

using namespace std;
#include "constants.h"
#include "list.h"

/*cambiar nombre de estructura a algfo general como "coordinates" */
struct CoordinatesOfBuilding{
	int row;
	int column;
} ;


class ArrayOfCoordinates{
private:
    int size;
	int allocSize;
    CoordinatesOfBuilding * arrayOfCoordinates; 

public:
    //PRE:
    //POST: Constructor de la clase. Se inicializan los atributos de la clase
    ArrayOfCoordinates();

    //PRE:
    //POST: Destructor de la clase.
    ~ArrayOfCoordinates();

    //PRE: -
    //POST: Este metodo agrega un elemento al arreglo de coordenadas, y en caso de no haber lugar, pide memoria para mas elementos.
    void pushBack(int row, int column);

    //PRE: -
    //POST: Este metodo imprime las coordenadas que se encuentran en el arreglo de coordenadas.
    void print();

    //PRE: -
    //POST: Este metodo elimina las coordenadas del edificio que se demolio del arreglo de coordenadas.
    void deletee(int row, int column);

    //PRE:
    //POST: Este metodo devuelve el atributo size (tamano del arreglo de coordenadas)
    int getSize()const;

    //PRE: Se debe ingresar un index menor al tamano del arreglo
    //POST: Sobrecarga del operador []. 
    CoordinatesOfBuilding operator[](size_t index);
};

#endif
