#include <string>
#include <iostream>

#include "buildingInfo.h"

using namespace std;

// Constructores

BuildingInfo::BuildingInfo(){
    buildingName.clear();
    stoneRequired = 0;
    woodRequired = 0;
    metalRequired = 0;
    buildingsAllowed = 0;
    buildingsMade = 0;
}

BuildingInfo::BuildingInfo(string buildName, int stoneReq, int woodReq, int metalReq, int buildAllowed){
    buildingName = buildName;
    stoneRequired = stoneReq;
    woodRequired = woodReq;
    metalRequired = metalReq;
    buildingsAllowed = buildAllowed;
    buildingsMade = 0;
}

//este borrar 
BuildingInfo::BuildingInfo(const BuildingInfo & building){
    buildingName = building.buildingName;
    stoneRequired = building.stoneRequired;
    woodRequired = building.woodRequired;
    metalRequired = building.metalRequired;
    buildingsAllowed = building.buildingsAllowed;
    buildingsMade = building.buildingsMade;
}

// Destructor

BuildingInfo::~BuildingInfo(){
}


// Sobrecarga de operadores

ostream & operator<< (ostream &outputStream, const BuildingInfo & building){
 	outputStream << building.buildingName << endl;
    outputStream << building.stoneRequired << endl;
    outputStream << building.woodRequired << endl;
    outputStream << building.metalRequired << endl;
    outputStream << building.buildingsAllowed << endl;
    outputStream << building.buildingsMade << endl;

	return outputStream;
}

bool BuildingInfo::operator==(const BuildingInfo & building){
    return  ( buildingName == building.buildingName
            && stoneRequired == building.stoneRequired
            && woodRequired == building.woodRequired 
            && metalRequired == building.metalRequired
            && buildingsAllowed == building.buildingsAllowed 
            && buildingsMade == building.buildingsMade);
}

// Getters

string BuildingInfo::getBuildingName()const{
    return buildingName;
}

int BuildingInfo::getStoneRequired()const{
    return stoneRequired;
}

int BuildingInfo::getWoodRequired()const{
    return woodRequired;
}

int BuildingInfo::getMetalRequired()const{
    return metalRequired;
}

int BuildingInfo::getBuildingsAllowed()const{
    return buildingsAllowed;
}

int BuildingInfo::getBuildingsMade()const{
    return buildingsMade;
}

ArrayOfCoordinates& BuildingInfo::getArrayOfCoordinates(){
    return arrayOfCoordinates;
}

// 
void BuildingInfo::addCoordinates(int row, int column){
    arrayOfCoordinates.pushBack(row, column);
}

void BuildingInfo::deleteCoordinates(int row, int column){

    arrayOfCoordinates.deletee(row, column);

}

void BuildingInfo::printCoordinates(){
    arrayOfCoordinates.print();
}


// Setters

void BuildingInfo::setBuildingName(string builName){
    buildingName = builName;
}

void BuildingInfo::setStoneRequired(int stoneReq){
    stoneRequired = stoneReq;
}

void BuildingInfo::setWoodRequired(int woodReq){
    woodRequired = woodReq;
}

void BuildingInfo::setMetalRequired(int metalReq){
    metalRequired = metalReq;
}

void BuildingInfo::setBuildingsAllowed(int builAllowed){
    buildingsAllowed = builAllowed;
}

void BuildingInfo::setBuildingsMade(int builMade){
    buildingsMade = builMade;
}
