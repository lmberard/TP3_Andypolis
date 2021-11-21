#ifndef _MENU_H_INCLUDED_
#define _MENU_H_INCLUDED_


#ifdef __linux__
#define CLR_SCREEN "clear"
#endif // __linux__

#ifdef __MINGW32__
#define CLR_SCREEN "CLS"
#endif // __MINGW32__


#include "list.h"
#include "colors.h"
#include "constants.h"
#include "materials.h"
#include "building.h"
#include "buildingInfo.h"
#include "map.h"
#include "utilities.h"
#include "arrayOfCoordinates.h"
#include "cell.h"
#include "cellBuildable.h"
#include "cellPassable.h"

using namespace std;

typedef enum {

	UNDEFINE = 0,
	BUILD_BUILDING_BY_NAME = 1,
	LIST_CONSTRUCTUCTED_BUILDINGS = 2,
	LIST_ALL_BUILDINGS = 3,
	DEMOLISH_BUILDING_BY_COORDINATES = 4,
	SHOW_MAP = 5,
	ASK_COORDINATES = 6,
	SHOW_INVENTARY = 7,
	COLLECT_RESOURCES = 8,
	RESOURCES_STORM = 9,
	SAVE_AND_LEAVE = 10,
	LEAVE = 11

} optionMenu;


void menu(optionMenu & option, List<Materials> & materialsChain, List<BuildingInfo> & buildingsInfoChain, Map & andyMap, List<CoordinatesOfBuilding> & roadsCoordinates);

// PRE: Las listas recibidas deben estar creadas, aunque estén vacías.
// POST: Se llaman a las funciones contempladas en las opciones del 1 al 6 si el usuario ingresa esas opciones.
// Caso contrario, se indica que la opción ingresada es incorrecta y se finaliza la función.

// PRE: -
// POST: Esta funcion devuelve por referencia la opcion elegida.
void handleMenu(optionMenu& option);

// PRE: -
// POST: Se imprime el menú del programa.
void displayMenu();

// PRE: -
// POST: Esta funcion procesa la opcion ingresada y dependiendo de cual sea, llama a la funcion pertinente.
void processOption(optionMenu& selectedOption, List<Materials> & materialsChain, List<BuildingInfo> & buildingsInfoChain, Map & andyMap, List<CoordinatesOfBuilding> & roadsCoordinates);

// PRE: -
// POST: Imprime por consola UNICAMENTE los materiales de construccion con sus respectivas cantidades.
void listConstructionMaterials(List <Materials> * materialsChain);


// PRE: -
// POST: Se imprime el título "Listado de materiales de construcción".
void printTitleListOfMaterials();


// PRE: -
// POST: Se imprimen los encabezados "Material" y "Cantidad".
void printHeaderListOfMaterials();


// PRE: El nodo recibido debe estar creado, aunque esté vacío.
// POST: Se imprime el material de construcción con su respectiva cantidad.
void printListOfMaterials(Node<Materials> * aux);

//PRE: -
//POST: Esta funcion muestra que hay en las coordenadas que ingresa el usuario.
void showCellByCoordinates(Map & andyMap);

//PRE: -
//POST: Esta funcion construye un edificio en las coordenadas del mapa que le ingresa el usuario a partir del nombre del edificio que también ingresa el usuario. 
void buildBuildingByName(List<Materials> &materialsChain, List<BuildingInfo> &buildingsInfoChain, Map &andyMap);

//PRE: -
//POST: Esta funcion destruye un edificio del mapa a partir de las coordenadas que le ingresa el usuario.
void demolishBuildingByCoordinates(List<Materials> &materialsChain, List<BuildingInfo> &buildingsInfoChain, Map &andyMap); ////

//PRE: - 
//POST: Esta funcion lista todos los edificios indicando para cada uno de ellos: cuantas unidades de cada material se requieren para construir uno, 
// cuantos fueron construidos hasta el momento, cuantos más puedo construir sin superar el máximo permitido y si me brinda algún tipo de material.
void listAllBuildings(List <BuildingInfo> & buildingsInfoChain);

//PRE:
//POST: Esta funcion lista todos los edificios construidos, indicando cuantos hay construidos de cada tipo y las coordenadas donde se encuentran.
void listBuildingsMade(List <BuildingInfo> & buildingsInfoChain);

//PRE: -
// POST: Esta funcion imprime los todos los edificios, cuanta madera, piedra y metal se necesita para construirlos,
// cuantos hay construidos, cuanta es la cantidad disponible para construir y el material que entrega.
void printAllBuildings(Node<BuildingInfo> * aux);

// PRE: El nodo recibido debe estar creado, aunque esté vacío.
// POST: Se imprime el nombre del edificio, la cantidad construida y las coordenadas.
void printListOfBuildingsMade(Node<BuildingInfo> * aux);

//PRE: - 
//POST: Esta funcion recolecta los materiales que brindan todos los edificios construidos.
void collectResources(List<Materials> & materialsChain, List<BuildingInfo> & buildingsInfoChain, Map &andyMap);

//PRE: -
//POST: Para cada uno de los edificios del mapa, esta funcion se fija que material brinda y cuanto e invoca a addMaterial para agregarlos a la lista de materiales.
void addResourcesToMaterialsChain(List<Materials> & materialsChain, Node<BuildingInfo> * ptrBuildInfoNode, Map & andyMap);

//PRE: -
//POST: Esta funcion agrega los materiales que generan los edificios que estan construidos en el mapa a la lista de materiales.
void addMaterial(List<Materials> & materialsChain, string material, int materialAmount);

//PRE: - 
//POST: Esta funcíon genera una lluvia de materiales en el mapa.
void resourcesStorm(Map & andyMap, List<CoordinatesOfBuilding> & roadsCoordinates);

//PRE: - 
//POST: Esta funcion sobreescribe los archivos txt con la informacion contenida en ambas listas.
void saveAndQuit(List<Materials> & materialsChain, List<BuildingInfo> & buildingsInfoChain);

//PRE: - 
//POST: Esta funcion sobreescribe materiales.txt con la informacion contenida en la lista de materiales.
void saveMaterials(List<Materials> & materialsChain);

//PRE: - 
//POST: Esta funcion sobreescribe ubicaciones.txt con la informacion contenida en la lista de edificios.
void saveBuildingsLocation(List<BuildingInfo> & buildingsInfoChain);

// PRE: -
// POST: Se imprime el título de si se desea contruir si o no.
void printConfirmationToBuild();

// PRE: -
// POST: Se imprime el título "Listado de edificios construidos".
void printTitleAllBuildings();

// PRE: -
// POST: Se imprimen los encabezados "Edificio", "Piedra", "Madera", "Metal".
// "Cantidad construida", "Cantidad disponible para construir" y "Material que entrega".
void printHeaderAllBuildings();

// PRE: -
// POST: Se imprime el título "Listado de todos los edificios".
void printTitleBuildingsMade();

// PRE: -
// POST: Se imprimen los encabezados "Edificio", "Cantidad construida" y "Coordenadas".
void printHeaderBuildingsMade();


#endif