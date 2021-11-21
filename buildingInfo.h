#ifndef _BUILDING_INFO_H_INCLUDED_
#define _BUILDING_INFO_H_INCLUDED_

using namespace std;
#include "constants.h"
#include "arrayOfCoordinates.h"


class BuildingInfo{
private:
    string buildingName;
    int stoneRequired;
    int woodRequired;
    int metalRequired;
    int buildingsAllowed;
    int buildingsMade; 
    ArrayOfCoordinates arrayOfCoordinates; 

public:
    //PRE:
    //POST: Constructor de la clase. Se inicializan los atributos.
    BuildingInfo();

    //PRE:
    //POST: Constructor de la clase. Se copian los parametros recibidos en los atributos de la clase
    BuildingInfo(string, int, int, int, int);
    
    //PRE:
    //POST: Constructor de la clase. Se copian los atributos de la instancia de Building recibida en los atributos
    BuildingInfo(const BuildingInfo &);
    
    //PRE:
    //POST: Destructor de la clase
    ~BuildingInfo();

    //PRE:
    //POST: Sobrecarga de operador "<<". Se establecen las instrucciones para la impresion de la clase
    friend ostream & operator<< (ostream &outputStream, const BuildingInfo & building);
    
    //PRE:
    //POST: Sobrecarga de operador "==". Se establecen las instrucciones para comparar dos instancias de la clase
    bool operator==(const BuildingInfo &);

    //PRE: -
    //POST: Este metodo devuelve el nombre del edificio.
    string getBuildingName()const;
    
    //PRE: -
    //POST: Este metodo devuelve el valor del atributo woodRequired (cantidad de madera requerida para construir un edificio, que es distinto dependiendo que tipo de edificio es).
    int getStoneRequired()const;
    
    //PRE: -
    //POST: Este metodo devuelve el valor del atributo woodRequired (cantidad de madera requerida para construir un edificio, que es distinto dependiendo que tipo de edificio es).
    int getWoodRequired()const;
    
    //PRE: -
    //POST: Este metodo devuelve el valor del atributo metalRequired (cantidad de metal requerida para construir un edificio, que es distinto dependiendo que tipo de edificio es).
    int getMetalRequired()const;
    
    //PRE: -
    //POST: Este metodo devuelve el valor del atributo buildingsAllowed (cantidad maxima permitida de edificios a contruir).
    int getBuildingsAllowed()const;
    
    //PRE: -
    //POST: Este metodo devuelve el valor del atributo buildingsName (el nombre del edificio).
    int getBuildingsMade()const;
    
    //PRE: -
    //POST: Este metodo devuelve por referencia el arreglo de coordenadas.
    ArrayOfCoordinates & getArrayOfCoordinates();

    //PRE: -
    //POST: Este metodo agrega coordenadas al arreglo de coordenadas.
    void addCoordinates(int, int);

    //PRE: -
    //POST: Este metodo llama al metodo deletee() de la clase ArrayOfCoordinates.
    void deleteCoordinates(int row, int column);

    //PRE: -
    //POST: Este metodo llama al metodo print() de la clase ArrayOfCoordinates.
    void printCoordinates();

    //PRE: - 
    //POST: Este metodo setea en el atributo buildingsName el nombre del edificio recibido.
    void setBuildingName(string);
    
    //PRE: -
    //POST: Este metodo setea el valor del atributo stoneRequired (cantidad de piedra requerida para construir un edificio, que es distinto dependiendo que tipo de edificio es).
    void setStoneRequired(int);
    
    //PRE: -
    //POST: Este metodo setea el valor del atributo woodRequired (cantidad de madera requerida para construir un edificio, que es distinto dependiendo que tipo de edificio es).
    void setWoodRequired(int);
    
    //PRE: -
    //POST: Este metodo setea el valor del atributo metalRequired (cantidad de metal requerida para construir un edificio, que es distinto dependiendo que tipo de edificio es).
    void setMetalRequired(int);
    
    //PRE: -
    //POST: Este metodo setea el valor del atributo buildingsAllowed (cantidad maxima permitida de edificios a contruir).
    void setBuildingsAllowed(int); 
    
    //PRE: - 
    //POST: Este metodo setea el valor del atributo buildingsMade (cuantos edificios hay construidos).
    void setBuildingsMade(int);

};



#endif
