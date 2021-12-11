#include "construir.hpp"

void Construir::jugar(Constructor & bob, Mapa & mapa, int & turno, Jugador * jugadores, int & id_jugador_actual){
    Coordenada coordenadas;
    Edificio * edif_ptr;
    string edificio;

    if(jugadores[id_jugador_actual - 1].obtener_energia() >= 15){
        edificio = pedir_edificio();
        if(chequear_existencia_de_edificio(bob, edificio)){
            edif_ptr = bob.mostrar_edificio(edificio);
            if(chequear_edificios_disponibles(edif_ptr, jugadores[id_jugador_actual - 1])){
                if(chequear_requerimientos_edificio(edif_ptr, jugadores[id_jugador_actual - 1])){
                    coordenadas = pedir_coordenadas();
                    if(mapa.coordenadas_validas(coordenadas)){
                        mapa.agregar_contenido(coordenadas, bob.construye(edif_ptr->obtener_nombre()));
                        descontar_materiales(edif_ptr,jugadores[id_jugador_actual - 1]);
                        jugadores[id_jugador_actual - 1].agregar_ubicacion_lista_edificios(edif_ptr->obtener_nombre(), coordenadas);
                    }
                }
            }   
        }
    }
    
    bool fin_turno = false;
    jugadores[id_jugador_actual-1].chequear_objetivos(fin_turno,bob);     
}

bool Construir::chequear_existencia_de_edificio(Constructor & bob, string edificio){
    bool estado = true;

    if(!bob.existe(edificio)){
        msjeError("No se puede construir el edificio. El edificio que desea construir no existe en Andypolis.");
        estado = false;
    }
    return estado;
}


bool Construir::chequear_edificios_disponibles(Edificio * edif_ptr, Jugador & jugador){
    bool estado = true;
    int cantidad_construidos;

    cantidad_construidos = jugador.obtener_cant_edificios_construidos(edif_ptr->obtener_nombre());
    if(cantidad_construidos >= edif_ptr->obtener_cant_max()){
        msjeError("No se puede construir el edificio. No quedan edificios disponibles por construir.");
        estado = false;
    }

    return estado;
}




bool Construir::chequear_requerimientos_edificio(Edificio * edif_ptr, Jugador & jugador){
    return jugador.inv().chequear_stock(edif_ptr, false);
}

bool Construir::descontar_materiales(Edificio * edif_ptr, Jugador & jugador){
    return jugador.inv().chequear_stock(edif_ptr, true);
}


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
