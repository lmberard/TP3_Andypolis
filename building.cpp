#include <string>
#include <iostream>

#include "building.h"

using namespace std;

// Constructores

Building::Building(){
    identifier.clear();
    generatedMaterial.clear();
    generatedMaterialAmount = 0;
}

Building::Building(const Building & Building){
    identifier = Building.identifier;
    generatedMaterial = Building.generatedMaterial;
    generatedMaterialAmount = Building.generatedMaterialAmount;
}

// Destructor

Building::~Building(){
}


// Sobrecarga de operadores

ostream & operator<< (ostream &outputStream, const Building & Building){
    outputStream << Building.identifier << endl;
    outputStream << Building.generatedMaterial << endl;
    outputStream << Building.generatedMaterialAmount << endl;

	return outputStream;
}


bool Building::operator==(const Building & Building){
    return  (identifier == Building.identifier
            && generatedMaterial == Building.generatedMaterial
            && generatedMaterialAmount == Building.generatedMaterialAmount);
}

// Getters

string Building::getIdentifier()const{
    return identifier;
}

string Building::getGeneratedMaterial()const{
    return generatedMaterial;
}

int Building::getGeneratedMaterialAmount()const{
    return generatedMaterialAmount;
}

// Setters


void Building::setIdentifier(string identif){
    identifier = identif;
}

void Building::setGeneratedMaterial(string generatedMat){
    generatedMaterial = generatedMat;
}

void Building::setGeneratedMaterialAmount(int generatedMatAmount){
    generatedMaterialAmount = generatedMatAmount;
}