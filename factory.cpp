#include <string>
#include <iostream>

#include "factory.h"
#include "constants.h"

using namespace std;


Factory::Factory(){
    identifier = FACTORY_IDENTIFIER;
    generatedMaterial = WORD_METAL;
    generatedMaterialAmount = MATERIAL_PRODUCED_FACTORY;
}

Factory::~Factory(){
}
