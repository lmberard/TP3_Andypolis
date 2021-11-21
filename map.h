#ifndef _MAP_H_INCLUDED_
#define _MAP_H_INCLUDED_

#include "cell.h"

using namespace std;


class Map{

typedef Cell* CellPtr;

private:
    int rows;
    int columns;
    CellPtr ** cellPtrMatrix;

public:
    //PRE:
    //POST: Constructor de la clase. Se inicializan los atributos.
    Map();
    
    //PRE:
    //POST: Destructor de la clase
    ~Map();

    // PRE: El archivo debe venir bien formado.
    // POST: Este metodo pide memoria para la cantidad de elementos de la clase cellPtr obtenido del archivo "mapa.txt." que dice las rows y columns que tiene la matriz.  
    void askCellMatrixMemory(int rows, int columns);

    // PRE: -
    // POST: Este metodo devuelve el casillero, es decir un elemento de la clase CellPtr.
    CellPtr getElement(int x, int y);
    
    // PRE: - 
    // POST: Este metodo pide memoria para la contrucci�n de un edificio, un camino o un lago dentro de una celda dependiendo del identificador que esa celda conten�a en el mapa.   
    void addElement(int x, int y, string);
    
    // PRE: -
    // POST: Este metodo valida a partir de la row y column que le pasan si esa celda, es una celda construible. Si lo es, construye el edificio a partir del metodo "build()". 
    //       Si se pudo construir, devuelve true. En caso contrario, devuelve false. 
    bool buildBuilding(int x, int y, string data);
    
    // PRE: -
    // POST: Este metodo devuelve true si se demolio un edificio satisfactoriamente.
    bool demolishBuilding(int x, int y, string & demolishedBuilding);///
    
    // PRE:
    // POST: Imprime el mapa. Se llama al metodo showCell que cada hija ejecutara de acuerdo a la clase que sea.
    void printMap();
    
    // PRE:
    // POST: Imprime la informacion de la celda. Se llama al metodo showCellInfo que cada hija ejecutara de acuerdo a la clase que sea.
    void printCellInfo(int row, int column);
    
    // PRE: -
    // POST: Este metodo valida que las coordenadas ingresadas sean correctas, es decir, que esten dentro del mapa.
    bool validateCoordinates(int row, int column);
};




#endif
