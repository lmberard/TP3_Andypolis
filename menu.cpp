#include <fstream>
#include <iostream>
#include <iomanip>
#include <string>

#include "menu.h"


using namespace std;

void menu(optionMenu & option, List<Materials> & materialsChain, List<BuildingInfo> & buildingsInfoChain, Map &andyMap, List<CoordinatesOfBuilding> & roadsCoordinates){
    while (option != LEAVE) {
        option = UNDEFINE;
        handleMenu(option);
        processOption(option, materialsChain, buildingsInfoChain, andyMap, roadsCoordinates);
    }
}


void handleMenu(optionMenu& option) {
    int selectedOption = 0;
    string aux;

    displayMenu();
    getline(cin, aux);

    
    if (isANumber(aux) == true){
        selectedOption = stoi(aux);
        if (selectedOption >= 1 && selectedOption <= 10)
            option = (optionMenu)selectedOption;
    } else
        option = UNDEFINE;
  
}

void processOption(optionMenu& selectedOption, List<Materials> & materialsChain, List<BuildingInfo> & buildingsInfoChain, Map & andyMap, List<CoordinatesOfBuilding> & roadsCoordinates){

    switch(selectedOption){
        case BUILD_BUILDING_BY_NAME:
            buildBuildingByName(materialsChain, buildingsInfoChain, andyMap);
            break;

        case LIST_CONSTRUCTUCTED_BUILDINGS:
            listBuildingsMade(buildingsInfoChain);
            break;

        case LIST_ALL_BUILDINGS:
            listAllBuildings(buildingsInfoChain);
            break;

        case DEMOLISH_BUILDING_BY_COORDINATES:
            demolishBuildingByCoordinates(materialsChain, buildingsInfoChain, andyMap);
            break;

        case SHOW_MAP:
            andyMap.printMap();
            cout << endl;
            break;

        case ASK_COORDINATES:
            showCellByCoordinates(andyMap);
            break;

        case SHOW_INVENTARY:
            listConstructionMaterials(&materialsChain);
            break;
            
        case COLLECT_RESOURCES:
            collectResources(materialsChain, buildingsInfoChain, andyMap);
            break;
        
        case RESOURCES_STORM:
            resourcesStorm(andyMap, roadsCoordinates);
            andyMap.printMap();
            break;

        case SAVE_AND_LEAVE:
            saveAndQuit(materialsChain, buildingsInfoChain);
            selectedOption = LEAVE;
            break;

        default:
            cerr << TXT_DARK_RED_1 << ERR_WRONG_INPUT << END_COLOR << endl << endl;
            break;
    }
}

void buildBuildingByName(List<Materials> &materialsChain, List<BuildingInfo> &buildingsInfoChain, Map &andyMap){
    int row, column;
    string building;
    Node<BuildingInfo> * ptrBuildInfoNode = nullptr;

    cout << TXT_ORANGE_166 << ENTER_BUILDING_TO_BUILD << endl << END_COLOR;
    getline(cin, building);
    
    if(searchBuildingByName(buildingsInfoChain, &ptrBuildInfoNode, building) == true){
        if(checkBuildingRequirements(ptrBuildInfoNode, materialsChain) == true){
            askCoordinates(row,column);
            if(andyMap.validateCoordinates(row, column) == true){
                if((ptrBuildInfoNode->getData()).getBuildingsAllowed() - (ptrBuildInfoNode->getData()).getBuildingsMade() > 0){
                    if( ((CellBuildable*)(andyMap.getElement(row, column)))->getIsBuilt() != true ){
                        if(ConfirmationToBuild() == CONFIRMATION_BUILD_YES){
                            if(andyMap.buildBuilding(row, column, building) == true){
                                ptrBuildInfoNode->getData().addCoordinates(row, column);
                                ptrBuildInfoNode->getData().setBuildingsMade(ptrBuildInfoNode->getData().getBuildingsMade() + 1);
                                updateMaterialsAmount(ptrBuildInfoNode, materialsChain);
                                cout << TXT_ORANGE_166 << BUILD_BUILDING_SUCCESS << building << END_COLOR << endl;
                            }
                        }
                    }
                    else
                        cerr << TXT_DARK_RED_1 << ERR_CELL_WITH_BUILDING << END_COLOR << endl << endl;
                }
                else
                    cerr << TXT_DARK_RED_1 << ERR_NO_REMAINING_BUILDINGS_TO_BUILD << END_COLOR << endl << endl;
            } else
                cerr << TXT_DARK_RED_1 <<  ERR_INVALID_COORDINATES << END_COLOR << endl << endl;
        }
    } else
        cerr << TXT_DARK_RED_1 << ERR_BUILDING_NOT_FOUND << END_COLOR<< endl << endl;
}


void demolishBuildingByCoordinates(List<Materials> &materialsChain, List<BuildingInfo> &buildingsInfoChain, Map &andyMap){
    int row,column;
    string buildingDemolished;
    Node<BuildingInfo> * ptrBuildInfoNode = buildingsInfoChain.getFirst();
    bool buildingFoundFlag = false;

    askCoordinates(row, column);

    if(andyMap.demolishBuilding(row, column, buildingDemolished) == true){
        while(ptrBuildInfoNode != nullptr && buildingFoundFlag == false){
            if(buildingDemolished == (ptrBuildInfoNode->getData()).getBuildingName()){
                ptrBuildInfoNode->getData().setBuildingsMade(ptrBuildInfoNode->getData().getBuildingsMade() - 1); 
                updateMaterialsAmountDemolish(ptrBuildInfoNode, materialsChain);
                ptrBuildInfoNode->getData().deleteCoordinates(row, column);
                buildingFoundFlag = true;
            } 
            else   
                ptrBuildInfoNode = ptrBuildInfoNode->getNext();
        }
        cout << TXT_ORANGE_166 << DEMOLISH_BUILDING_SUCCESS << buildingDemolished << END_COLOR << endl << endl;
    }

}


void showCellByCoordinates(Map & andyMap){
    int row, column;

    askCoordinates(row, column);

    if(andyMap.validateCoordinates(row,column) == false){
        cerr << TXT_DARK_RED_1 <<  ERR_INVALID_COORDINATES << END_COLOR << endl << endl;
        return;
    }

    andyMap.printCellInfo(row, column);
}


void listConstructionMaterials(List <Materials> * materialsChain){
    Node<Materials> * aux = (*materialsChain).getFirst();
    string material;

    printTitleListOfMaterials();
    printHeaderListOfMaterials();

	if(!(*materialsChain).isEmpty()){
		while(aux != 0){
            material = (aux->getData()).getMaterial();
            printListOfMaterials(aux);
			aux = aux->getNext();
		}
		cout << endl << endl;
	}
}


void listAllBuildings(List <BuildingInfo> & buildingsInfoChain){
    Node<BuildingInfo> * aux = buildingsInfoChain.getFirst();

    printTitleAllBuildings();
    printHeaderAllBuildings();

    while(aux != 0){
        printAllBuildings(aux);
        aux = aux->getNext();     
    }	
	
    cout << endl << endl;
}

void collectResources(List<Materials> & materialsChain, List<BuildingInfo> & buildingsInfoChain, Map &andyMap){
    string buildingDemolished;
    Node<BuildingInfo> * ptrBuildInfoNode = buildingsInfoChain.getFirst();
    
    while(ptrBuildInfoNode != nullptr){
        if(ptrBuildInfoNode->getData().getBuildingsMade() > 0){
            addResourcesToMaterialsChain(materialsChain, ptrBuildInfoNode, andyMap);
        }
        ptrBuildInfoNode = ptrBuildInfoNode->getNext();
    }
}


void addResourcesToMaterialsChain(List<Materials> & materialsChain, Node<BuildingInfo> * ptrBuildInfoNode, Map & andyMap){
    int row, column;
    string material;
    int materialAmount;

    for(int i = 0; i < ptrBuildInfoNode->getData().getArrayOfCoordinates().getSize(); i++){

            row = ptrBuildInfoNode->getData().getArrayOfCoordinates()[i].row;
            column = ptrBuildInfoNode->getData().getArrayOfCoordinates()[i].column;
            material = ((CellBuildable*)(andyMap.getElement(row, column)))->getBuilding().getGeneratedMaterial();
            materialAmount = ((CellBuildable*)(andyMap.getElement(row, column)))->getBuilding().getGeneratedMaterialAmount();

            addMaterial(materialsChain, material, materialAmount);
    }
}

void addMaterial(List<Materials> & materialsChain, string material, int materialAmount){
    Node<Materials> * ptrMaterialsNode = materialsChain.getFirst();
    bool flag = false;

    while(ptrMaterialsNode != nullptr && flag == false){
        if(ptrMaterialsNode->getData().getMaterial() == material){
            ptrMaterialsNode->getData().setAmount(ptrMaterialsNode->getData().getAmount() + materialAmount);
            flag = true;
        }
        else
            ptrMaterialsNode = ptrMaterialsNode->getNext();
    }
}

void resourcesStorm(Map & andyMap, List<CoordinatesOfBuilding> & roadsCoordinates){
    int row, column, aux;
    int generatedStone, generatedMetal, generatedWood;
    Node<CoordinatesOfBuilding> * ptrRoadsCoordinate = roadsCoordinates.getFirst();

    generatedStone = rand()%(RANDOM_MAX_STONE_AMOUNT - RANDOM_MIN_STONE_AMOUNT + 1) + RANDOM_MIN_STONE_AMOUNT; 
    generatedWood = rand()%(RANDOM_MAX_WOOD_AMOUNT - RANDOM_MIN_WOOD_AMOUNT + 1) + RANDOM_MIN_WOOD_AMOUNT;
    generatedMetal = rand()%(RANDOM_MAX_METAL_AMOUNT - RANDOM_MIN_METAL_AMOUNT + 1) + RANDOM_MIN_METAL_AMOUNT;

    for (int i = 0; i < generatedStone; i++){
        if(roadsCoordinates.getSize() > 0){                              //si es mayor a 0 es que todavia tengo caminos libres para asignar materiales
            aux = rand() % (roadsCoordinates.getSize() - 1 + 1) + 1;    //esto me da un numero entre 1 y el tamaño de la lista.
            for(int j = 1; j < aux; j++)                                // busco el nodo que está en la posicion aux de la lista
                ptrRoadsCoordinate = ptrRoadsCoordinate->getNext();
            row = ptrRoadsCoordinate->getData().row;
            column = ptrRoadsCoordinate->getData().column;
            ((CellPassable*)(andyMap.getElement(row, column)))->addMaterial(WORD_STONE);
            roadsCoordinates.removeElement(*ptrRoadsCoordinate);
        }
        ptrRoadsCoordinate = roadsCoordinates.getFirst();
    }

    for (int i = 0; i < generatedMetal; i++){
        if(roadsCoordinates.getSize() > 0){                              //si es mayor a 0 es que todavia tengo caminos libres para asignar materiales
            aux = rand() % (roadsCoordinates.getSize() - 1 + 1) + 1;    //esto me da un numero entre 1 y el tamaño de la lista.
            for(int j = 1; j < aux; j++)                                // busco el nodo que está en la posicion aux de la lista
                ptrRoadsCoordinate = ptrRoadsCoordinate->getNext();
            row = ptrRoadsCoordinate->getData().row;
            column = ptrRoadsCoordinate->getData().column;
            ((CellPassable*)(andyMap.getElement(row, column)))->addMaterial(WORD_METAL);
            roadsCoordinates.removeElement(*ptrRoadsCoordinate);
        }
        ptrRoadsCoordinate = roadsCoordinates.getFirst();
    }

    for (int i = 0; i < generatedWood; i++){
        if(roadsCoordinates.getSize() > 0){                              //si es mayor a 0 es que todavia tengo caminos libres para asignar materiales
            aux = rand() % (roadsCoordinates.getSize() - 1 + 1) + 1;    //esto me da un numero entre 1 y el tamaño de la lista.
            for(int j = 1; j < aux; j++)                                // busco el nodo que está en la posicion aux de la lista
                ptrRoadsCoordinate = ptrRoadsCoordinate->getNext();
            row = ptrRoadsCoordinate->getData().row;
            column = ptrRoadsCoordinate->getData().column;
            ((CellPassable*)(andyMap.getElement(row, column)))->addMaterial(WORD_WOOD);
            roadsCoordinates.removeElement(*ptrRoadsCoordinate);
        }
        ptrRoadsCoordinate = roadsCoordinates.getFirst();
    }
}




void saveAndQuit(List<Materials> & materialsChain, List<BuildingInfo> & buildingsInfoChain){
    saveMaterials(materialsChain);
    saveBuildingsLocation(buildingsInfoChain);
}

void saveMaterials(List<Materials> & materialsChain){
    fstream file;
    Node<Materials> * ptrMaterialsNode = materialsChain.getFirst();

    file.open("materiales.txt", ios::out);

    if(file.is_open()){
        while(ptrMaterialsNode != 0){

            file << (ptrMaterialsNode->getData()).getMaterial() << " ";
            file << (ptrMaterialsNode->getData()).getAmount() << endl;

            ptrMaterialsNode = ptrMaterialsNode->getNext();
        }
 		file.close();
    }
	else
		cerr << TXT_DARK_RED_1 << ERR_CANT_OPEN_FILE << END_COLOR << endl << endl;
}

void saveBuildingsLocation(List<BuildingInfo> & buildingsInfoChain){
    fstream file;
    Node<BuildingInfo> * ptrBuildInfoNode = buildingsInfoChain.getFirst();

    file.open("ubicaciones.txt", ios::out);

    if(file.is_open()){

        while(ptrBuildInfoNode != 0){

            for(int i = 0; i < ptrBuildInfoNode->getData().getArrayOfCoordinates().getSize(); i++){
                file << (ptrBuildInfoNode->getData()).getBuildingName();
                file << " " << "(";
                file << ptrBuildInfoNode->getData().getArrayOfCoordinates()[i].row;
                file << ",";
                file << ptrBuildInfoNode->getData().getArrayOfCoordinates()[i].column;
                file << ")" << endl;
            }
            ptrBuildInfoNode = ptrBuildInfoNode->getNext();
        }
 		file.close();
    }
	else
		cerr << TXT_DARK_RED_1 << ERR_CANT_OPEN_FILE << END_COLOR << endl << endl;
}



void printAllBuildings(Node<BuildingInfo> * aux){
    int width = 11;

    cout << left << TAB
    << setw(2*width) << (aux->getData()).getBuildingName()  << setw(1) << "|" 
    << setw(width) << (aux->getData()).getStoneRequired() << setw(1) << "|" 
    << setw(width) << (aux->getData()).getWoodRequired()  << setw(1) << "|" 
    << setw(width) << (aux->getData()).getMetalRequired() << setw(1) << "|" 
    << setw(2*width) << (aux->getData()).getBuildingsMade() << setw(1) << "|" 
    << setw(3*width + 1) <<(aux->getData()).getBuildingsAllowed() - (aux->getData()).getBuildingsMade() << "|" << setw(10*width);

    if((aux->getData()).getBuildingName() == WORD_MINE)
        cout << WORD_STONE << setw(1) << endl ;
    else if ((aux->getData()).getBuildingName() == WORD_SAWMILL)
        cout << WORD_WOOD << setw(1) << endl ;
    else if ((aux->getData()).getBuildingName() == WORD_FACTORY)
        cout << WORD_METAL << setw(1) << endl ;
    else
        cout << "No entrega" << setw(1) << endl;

}


void listBuildingsMade(List <BuildingInfo> & buildingsInfoChain){
    Node<BuildingInfo> * aux = buildingsInfoChain.getFirst();

    printTitleBuildingsMade();
    printHeaderBuildingsMade();

    while(aux != 0){
        if((aux->getData()).getBuildingsMade() > 0)
            printListOfBuildingsMade(aux);

        aux = aux->getNext();
    }
	
    cout << endl;
}


void displayMenu(){

    cout << TAB << BGND_DARK_AQUA_24 << TAB << TAB << TAB << TAB << TAB << " MENU" << TAB << TAB << TAB << TAB << TAB << END_COLOR << endl;
    cout << TAB << BGND_DARK_AQUA_24 << "_____________________________________________" << END_COLOR << endl;
    cout << TAB << BGND_DARK_AQUA_24 << "|  1. Construir edificio por nombre.        |" << END_COLOR << endl;
    cout << TAB << BGND_DARK_AQUA_24 << "|  2. Listar los edificios construidos      |" << END_COLOR << endl;
    cout << TAB << BGND_DARK_AQUA_24 << "|  3. Listar todos los edificios            |" << END_COLOR << endl;
    cout << TAB << BGND_DARK_AQUA_24 << "|  4. Demoler un edificio por coordenada.   |" << END_COLOR << endl;
    cout << TAB << BGND_DARK_AQUA_24 << "|  5. Mostrar mapa.                         |" << END_COLOR << endl;
    cout << TAB << BGND_DARK_AQUA_24 << "|  6. Consultar coordenada.                 |" << END_COLOR << endl;
    cout << TAB << BGND_DARK_AQUA_24 << "|  7. Mostrar inventario.                   |" << END_COLOR << endl;
    cout << TAB << BGND_DARK_AQUA_24 << "|  8. Recolectar recursos producidos.       |" << END_COLOR << endl;
    cout << TAB << BGND_DARK_AQUA_24 << "|  9. Lluvia de recursos.                   |" << END_COLOR << endl;
    cout << TAB << BGND_DARK_AQUA_24 << "| 10. Guardar y salir.                      |" << END_COLOR << endl;
    cout << TAB << BGND_DARK_AQUA_24 << "|___________________________________________|" << END_COLOR << endl;

    cout << TXT_ORANGE_166 << ENTER_OPTION << END_COLOR << endl;

}

void printTitleListOfMaterials(){
    cout << TAB << BGND_DARK_AQUA_24 << "_________________________________________" << END_COLOR << endl;
    cout << TAB << BGND_DARK_AQUA_24 << "| Listado de materiales de construccion |" << END_COLOR << endl;
    cout << TAB << BGND_DARK_AQUA_24 << "|_______________________________________|" << END_COLOR << endl;
}

void printHeaderListOfMaterials(){
    int width = 15;
    cout << left << TAB << setw(width)  << "Material" << setw(1) << "|" << setw(width) << "Cantidad" << endl;
}


void printListOfMaterials(Node<Materials> * aux){
    int width = 15;
    cout << left << TAB << setw(width) << (aux->getData()).getMaterial() << setw(1) << "|" 
    << setw(width) << (aux->getData()).getAmount() << endl;
}

void printConfirmationToBuild(){
    cout << TXT_ORANGE_166 << CONFIRMATION_TO_BUILD << END_COLOR << endl;
    cout << TXT_ORANGE_166 << ENTER_OPTION << END_COLOR << endl;
    cout << TXT_ORANGE_166 << "1. Si" << END_COLOR << endl;
    cout << TXT_ORANGE_166 << "2. No" << END_COLOR << endl;
}

void printTitleAllBuildings(){
    cout << TAB << BGND_DARK_AQUA_24 << "_________________________________________" << END_COLOR << endl;
    cout << TAB << BGND_DARK_AQUA_24 << "|    Listado de todos los edificios     |" << END_COLOR << endl;
    cout << TAB << BGND_DARK_AQUA_24 << "|_______________________________________|" << END_COLOR << endl;
}

void printHeaderAllBuildings(){
    int width = 11;
    cout << left << TAB
    << setw(2*width) << "Edificio"                          << setw(1) << "|" 
    << setw(width) << "Piedra"                              << setw(1) << "|"
    << setw(width) << "Madera"                              << setw(1) << "|"
    << setw(width) << "Metal"                               << setw(1) << "|"
    << setw(2*width) << "Cantidad construida"               << setw(1) << "|"
    << setw(3*width + 1) << "Cantidad disponible para construir"  << setw(1) << "|"
    << setw(width) << "Material que entrega"                << setw(1) 
    << endl;
}

void printTitleBuildingsMade(){
    cout << TAB << BGND_DARK_AQUA_24 << "_________________________________________" << END_COLOR << endl;
    cout << TAB << BGND_DARK_AQUA_24 << "|   Listado de edificios construidos    |" << END_COLOR << endl;
    cout << TAB << BGND_DARK_AQUA_24 << "|_______________________________________|" << END_COLOR << endl;
}

void printHeaderBuildingsMade(){
    int width = 15;
    cout << left << TAB << setw(2*width)  << "Edificio" << setw(1) << "|" 
    << setw(2*width) << "Cantidad construida" << setw(1) << "|"
    << setw(2*width) << "Coordenadas" << endl;
}

void printListOfBuildingsMade(Node<BuildingInfo> * aux){
    int width = 15;
    cout << left << TAB 
    << setw(2*width) << (aux->getData()).getBuildingName() << setw(1) << "|"
    << setw(2*width) << (aux->getData()).getBuildingsMade() << setw(1) << "|";
    
    (aux->getData()).printCoordinates();

    cout << endl;  
}