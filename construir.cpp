#include "construir.hpp"

void Construir::jugar(Constructor & bob, Mapa & mapa, int & turno, Jugador * jugadores, int & id_jugador_actual){
    Coordenada coordenadas;
    Edificio * edif_ptr;
    string edificio;

    if(jugadores[id_jugador_actual].obtener_energia() >= 15){

        edificio = pedir_edificio();
        //TE PUSE ESTA COSITA PORQUE SI METES UNA CLAVE EN "MOSTRAR_EDIFICIO(string) que no existe, se caga"
        if(!bob.existe(edificio)){
            cout << "pipo, esta funcion sirve para validar si existe o no el edificio" << endl;
            return;
        }

        edif_ptr = bob.mostrar_edificio(edificio);

        if(edif_ptr){

            //chequear si tiene plata
            //chequear si tiene edificios disponibles por construir
            if(chequear_requerimientos_edificio(edif_ptr, jugadores[id_jugador_actual - 1])){

                coordenadas = pedir_coordenadas();
                if(mapa.coordenadas_validas(coordenadas));
            
            }

        }
        

            
    }

    bool fin_turno = false;
    jugadores[id_jugador_actual-1].chequear_objetivos(fin_turno,bob);
        
}


bool Construir::chequear_requerimientos_edificio(Edificio * edif_ptr, Jugador & jugador){
    Lista<Material *> lista_materiales = jugador.inv().obtener_lista_de_materiales();       
    int i = 1;
    bool piedra_chequeada = false, madera_chequeada = false, metal_chequeado, estado = false;

    while(i < lista_materiales.mostrar_cantidad() && (!piedra_chequeada || !madera_chequeada || !metal_chequeado) && estado != false){

        if(lista_materiales[i]->obtener_nombre() == "piedra"){
            if(lista_materiales[i]->obtener_cantidad() <= edif_ptr->obtener_piedra()){
                msjeError("No se puede construir el edificio. No hay piedra suficiente");
                estado = false;
            }
            piedra_chequeada = true;
        }

        if(lista_materiales[i]->obtener_nombre() == "madera"){
            if(lista_materiales[i]->obtener_cantidad() <= edif_ptr->obtener_madera()){
                msjeError("No se puede construir el edificio. No hay madera suficiente");
                estado = false;
            }
            madera_chequeada = true;
        }

        if(lista_materiales[i]->obtener_nombre() == "metal"){
            if(lista_materiales[i]->obtener_cantidad() <= edif_ptr->obtener_metal()){
                msjeError("No se puede construir el edificio. No hay metal suficiente");
                estado = false;
            }
            metal_chequeado = true;
        }

        i++;
    }
    return estado;
            
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
