#include <iostream>

#include "menu.h"
#include "list.h"
#include "node.h"
#include "materials.h" 
#include "utilities.h"
#include "constants.h"
#include "colors.h"
#include "map.h"
#include "cell.h"
#include "buildingInfo.h"
#include "building.h"

using namespace std;

int main(){
    optionMenu option = UNDEFINE;
    List<BuildingInfo> buildingsInfoChain;
    List<Materials> materialsChain;
    Map andyMap;
    List<CoordinatesOfBuilding> roadsCoordinates;

    system (CLR_SCREEN);

    loadBuildingsData(buildingsInfoChain);
    loadMaterials(materialsChain);
    loadMap(andyMap, buildingsInfoChain, roadsCoordinates);
    
    menu(option, materialsChain, buildingsInfoChain, andyMap, roadsCoordinates);

    return 0;
}
