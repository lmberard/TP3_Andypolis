#include <string>
#include <iostream>

#include "sawmill.h"
#include "constants.h"

using namespace std;


Sawmill::Sawmill(){
    identifier = SAWMILL_IDENTIFIER;
    generatedMaterial = WORD_WOOD;
    generatedMaterialAmount = MATERIAL_PRODUCED_SAWMILL;
}


Sawmill::~Sawmill(){
}
