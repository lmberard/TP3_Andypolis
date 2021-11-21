#include <string>
#include <iostream>

#include "mine.h"
#include "constants.h"

using namespace std;


Mine::Mine(){
    identifier = MINE_IDENTIFIER;
    generatedMaterial = WORD_STONE;
    generatedMaterialAmount = MATERIAL_PRODUCED_MINE;
}


Mine::~Mine(){
}
