#include <string>
#include <iostream>

#include "cellBuildable.h"
#include "school.h"
#include "mine.h"
#include "sawmill.h"
#include "factory.h"
#include "power_plant.h"
#include "obelisk.h"
#include "constants.h"
#include "colors.h"

using namespace std;

CellBuildable::CellBuildable() : Cell(){
    ptrBuilding = nullptr;
    isBuilt = false;
}


void CellBuildable::build(string building){
    
    if(building == WORD_SCHOOL)
        ptrBuilding = new School();
    else if (building == WORD_OBELISK)    
        ptrBuilding = new Obelisk();
    else if (building == WORD_FACTORY)
        ptrBuilding = new Factory();    
    else if (building == WORD_SAWMILL)
        ptrBuilding = new Sawmill();
    else if (building == WORD_MINE)
        ptrBuilding = new Mine();
    else if (building == WORD_POWER_PLANT)
        ptrBuilding = new PowerPlant();
    
    isBuilt = true;
}


bool CellBuildable::demolish(string & demolishedBuilding){
    bool demolishStatus = false;

    if(isBuilt == true){

        if(ptrBuilding->getIdentifier() == SCHOOL_IDENTIFIER)
            demolishedBuilding = WORD_SCHOOL;
        else if(ptrBuilding->getIdentifier() == MINE_IDENTIFIER)
            demolishedBuilding = WORD_MINE;
        else if(ptrBuilding->getIdentifier() == SAWMILL_IDENTIFIER)
            demolishedBuilding = WORD_SAWMILL;
        else if(ptrBuilding->getIdentifier() == FACTORY_IDENTIFIER)
            demolishedBuilding = WORD_FACTORY;
        else if(ptrBuilding->getIdentifier() == OBELISK_IDENTIFIER)
            demolishedBuilding = WORD_OBELISK;
        else if(ptrBuilding->getIdentifier() == POWER_PLANT_IDENTIFIER)
            demolishedBuilding = WORD_POWER_PLANT;

        delete ptrBuilding;
        ptrBuilding = nullptr;
        isBuilt = false;
        demolishStatus = true;
    }   
    
    return demolishStatus;
}

CellBuildable::~CellBuildable(){
    if(ptrBuilding)
        delete ptrBuilding;
}


void CellBuildable::showCell(){

    if(ptrBuilding){
        cout << BGND_GREEN_34 << '|' << (*ptrBuilding).getIdentifier() << '|' << END_COLOR;
    } else{
        cout << BGND_GREEN_34 << '|' << ' ' << '|' << END_COLOR;
    }
}

void CellBuildable::showCellInfo(){

    if(ptrBuilding){
        cout << TXT_ORANGE_166 << "Este es un casillero construible y hay construido/a un/a: " << END_COLOR;
        if(ptrBuilding->getIdentifier() == SCHOOL_IDENTIFIER)
            cout << WORD_SCHOOL << endl;
        else if(ptrBuilding->getIdentifier() == MINE_IDENTIFIER)
            cout << WORD_MINE << endl;
        else if(ptrBuilding->getIdentifier() == SAWMILL_IDENTIFIER)
            cout << WORD_SAWMILL << endl;
        else if(ptrBuilding->getIdentifier() == FACTORY_IDENTIFIER)
            cout << WORD_FACTORY << endl;
        else if(ptrBuilding->getIdentifier() == OBELISK_IDENTIFIER)
            cout << WORD_OBELISK << endl;
        else if(ptrBuilding->getIdentifier() == POWER_PLANT_IDENTIFIER)
            cout << WORD_POWER_PLANT << endl;
    } else{
        cout << TXT_ORANGE_166 << "Este es un casillero construible y no hay nada construido" << END_COLOR << endl << endl;
    }
}

CellBuildable::CellBuildable(int x, int y, string identif) : Cell(x, y, identif){
    ptrBuilding = nullptr;
    isBuilt = false;
}

Building CellBuildable::getBuilding(){
    return *ptrBuilding;
}

bool CellBuildable::getIsBuilt(){
    return isBuilt;
}