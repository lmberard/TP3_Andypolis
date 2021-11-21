#ifndef _UTILITIES_H_INCLUDED_
#define _UTILITIES_H_INCLUDED_

#include <string>
#include <fstream>
#include <iostream>

#include "materials.h"
#include "list.h"
#include "menu.h"
#include "constants.h"
#include "map.h"
#include "buildingInfo.h"

using namespace std;

// PRE: La lista recibida debe estar creada, aunque est� vac�a (de hecho lo est�)
// y el archivo "materiales.txt" debe estar bien formado.
// POST: Si se puede abrir el archivo, se leen los elementos del archivo, se los procesa y se los carga en los atributos correspondientes
// de la clase Materiales, para luego a�adir al final de la lista recibida un Nodo que contiene la instancia de esta clase.
// Caso contrario, se indica que no se pudo abrir el archivo y finaliza la funci�n.
void loadMaterials(List <Materials> & materialsChain);


// PRE: La lista recibida debe estar creada, aunque esté vacía (de hecho lo está)
// y el archivo "edificios.txt" debe estar bien formado.
// POST: Si se puede abrir el archivo, se leen los elementos del archivo, se los procesa y se los carga en los atributos correspondientes
// de la clase Building, para luego añadir al final de la lista recibida un Nodo que contiene la instancia de esta clase.
// Caso contrario, se indica que no se pudo abrir el archivo y finaliza la función.
void loadBuildingsData(List <BuildingInfo> & buildings_chain);

// PRE: -
// POST: Esta funcion agrega a la lista donde esta la información de los edificios si se contruyó uno (sumandole 1 al atributo buildingsMade) y las coordenadas donde fue construido. 
void loadBuildingsMadeFromFile(string str, List <BuildingInfo> & buildingInfoChain, int row, int column);

// PRE: -
// POST: Esta funcion crea el mapa con los edificios de ubicaciones.txt ya cargados.
void loadMap(Map &andyMap, List <BuildingInfo> & buildingInfoChain, List<CoordinatesOfBuilding> & roadsCoordinates);

// PRE: El archivo debe venir bien formado.
// POST: Esta función crea a partir de "mapa.txt" el mapa. Para ello lee el archivo, pide memoria para la cantidad de elementos de la clase cellPtr obtenido del archivo "mapa.txt." que dice las rows y columns.
void createMap(Map & andyMap, List<CoordinatesOfBuilding> & roadsCoordinates);

// PRE: - 
// POST: Esta funcion carga los edificios de ubicaciones.txt en el mapa.
void loadMapFromFile(Map & andyMap,List <BuildingInfo> & buildingInfoChain);

// PRE:
// POST: Esta funcion devuelve por referencia la fila y columna deseada.
void askCoordinates(int & row, int & column);

// PRE: - 
// POST: Esta funcion devuelve true si es un numero, y false si no lo es.
bool isANumber(string cadena);

// PRE: -
// POST: Esta funcion devuelve true si el nombre del edificio que ingreso el usuario se encuentra en la lista de edificios. Ademas, deja ptrBuildInfoNode apuntando al nodo de la lista donde se encuentra la informacion del edificio que ingreso el usuario.
bool searchBuildingByName(List<BuildingInfo> & buildingsInfoChain, Node<BuildingInfo> ** ptrBuildInfoNode, string building);

// PRE: - 
// POST: Esta funcion devuelve true si existen la cantidad de materiales necesarios para construir el edificio deseado.
bool checkBuildingRequirements(Node<BuildingInfo> * ptrBuildInfoNode,  List<Materials> & materialsChain);

// PRE: -	
// POST: Esta función actualiza los materiales de la lista de materiales si se contruyo un edificio satisfactoriamente.
void updateMaterialsAmount(Node<BuildingInfo> * ptrBuildInfoNode, List<Materials> & materialsChain);

// PRE: - 
// POST: Si se destruye satisfactoriamente un edificio, devuelve la mitad de los materiales necesarios para su construccion y actualiza la lista de los materiales.
void updateMaterialsAmountDemolish(Node<BuildingInfo> * ptrBuildInfoNode, List<Materials> & materialsChain);

// PRE: -
// POST: Esta funcion devuelve 1 si el usuario confirma que sea construir.
int ConfirmationToBuild();



#endif