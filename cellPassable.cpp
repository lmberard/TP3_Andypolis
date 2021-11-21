#include <string>
#include <iostream>

#include "cellPassable.h"
#include "constants.h"
#include "colors.h"

using namespace std;


CellPassable::CellPassable() : Cell(){
}

CellPassable::~CellPassable(){
}

void CellPassable::addMaterial(string material1){
    material.setMaterial(material1);
    material.setAmount(1);
    if(material1 == WORD_STONE)
        material.setIdentifier(STONE_IDENTIFIER);
    if(material1 == WORD_METAL)
        material.setIdentifier(METAL_IDENTIFIER);
    if(material1 == WORD_WOOD)
        material.setIdentifier(WOOD_IDENTIFIER);
}

Materials& CellPassable::getMaterial(){
    return material;
}

void CellPassable::showCell(){
    if(!material.getIdentifier().empty())
        cout << BGND_LIGHT_GRAY_246 << '|' << material.getIdentifier() << '|' << END_COLOR;
    
    else 
        cout << BGND_LIGHT_GRAY_246 << '|' << " " << '|' << END_COLOR;
}

void CellPassable::showCellInfo(){
    if(material.getIdentifier() == WOOD_IDENTIFIER){
        cout << TXT_ORANGE_166 << PASSABLE_CELL_WITH_WOOD << END_COLOR << endl << endl;
    } else if(material.getIdentifier() == METAL_IDENTIFIER){
        cout << TXT_ORANGE_166 << PASSABLE_CELL_WITH_METAL << END_COLOR << endl << endl;
    } else if(material.getIdentifier() == STONE_IDENTIFIER){
        cout << TXT_ORANGE_166 << PASSABLE_CELL_WITH_STONE << END_COLOR << endl << endl;
    }
    else
        cout << TXT_ORANGE_166 << PASSABLE_CELL_EMPTY << END_COLOR << endl << endl;
}

CellPassable::CellPassable(int x, int y, string identif) : Cell(x, y, identif){
}

