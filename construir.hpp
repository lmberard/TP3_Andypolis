#ifndef CONSTRUIR_HPP
#define CONSTRUIR_HPP

#include "jugada.hpp"

class Construir : public Jugada{
    public: 
        void jugar(Constructor & bob, Mapa & mapa, int & turno, Jugador * jugador, int & id_jugador_actual){
            Coordenada coordenadas;
            

            if(jugador->obtener_energia() >= 15){

                /*if(pedir_nombre_edificio() == true) */ //to do
                /*diccionario.buscar(nombre_edificio)*/ //to do

                coordenadas = pedir_coordenadas();
                if(mapa.coordenadas_validas(coordenadas) == true){
                    
                }
           }
           
           
           
            







            //ESTA FUNCION PUEDE PERDER MEMORIA!!!
            
            //esto chequea los objetivos luego de ejecutar la accion. fin de turno = false hace que los 
            //objetivos que se tengan que chequear al final del turno se chequeen solo cuando cambia el turno
            bool fin_turno = false;
            jugador[id_jugador_actual-1].chequear_objetivos(fin_turno,bob);
        }
};

#endif //CONSTRUIR_HPP


/*
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
*/

