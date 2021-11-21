#include <string>
#include <iostream>

#include "map.h"
#include "cellBuildable.h"
#include "cellPassable.h"
#include "cellIntransitable.h"
#include "constants.h"
#include "school.h"
#include "colors.h"

using namespace std;

Map::Map(){
    rows = 0;
    columns = 0;
    cellPtrMatrix = nullptr;
}

Map::~Map(){
    if(cellPtrMatrix == nullptr)
        return;

    for(int i = 0; i < rows; i++){
        for(int j = 0; j < columns; j++){
            delete cellPtrMatrix[i][j];
        }
        delete [] cellPtrMatrix[i];
    }    
    delete [] cellPtrMatrix;
}

void Map::askCellMatrixMemory(int rows, int columns){
    cellPtrMatrix = new CellPtr*[rows]; 

    for(int i = 0; i < rows; i++)
        (cellPtrMatrix)[i] = new CellPtr[columns];

    this->rows = rows;
    this->columns = columns;

}

Map::CellPtr Map::getElement(int x, int y){

    if(x >= rows || y >= columns || x < 0 || y < 0)
        return nullptr;

    return cellPtrMatrix[x][y];

}

void Map::addElement(int x, int y, string data){

    if(x >= rows || y >= columns || x < 0 || y < 0)
        return;

    if(data == FIELD_IDENTIFIER){
        cellPtrMatrix[x][y] = new CellBuildable(x, y, data);
    }
    else if(data == LAKE_IDENTIFIER){
        cellPtrMatrix[x][y] = new CellIntransitable(x, y, data);
    }
    else if(data == ROAD_IDENTIFIER){
        cellPtrMatrix[x][y] = new CellPassable(x, y, data);
    }
}

bool Map::buildBuilding(int x, int y, string data){
    bool status;
    if(x >= rows || y >= columns || x < 0 || y < 0){
        cerr << TXT_DARK_RED_1 << ERR_INVALID_COORDINATES << END_COLOR << endl << endl;
        status = false;
    }
    else{
        if(cellPtrMatrix[x][y]->getCellIdentifier() == FIELD_IDENTIFIER){
            ((CellBuildable*)cellPtrMatrix[x][y])->build(data);
            status = true;
        }
        else{
            cerr << TXT_DARK_RED_1 << ERR_INVALID_CELL << END_COLOR << endl << endl;
            status = false;
        }
    }
    return status;
}

bool Map::demolishBuilding(int x, int y, string & demolishedBuilding){
    bool status;

    if(x >= rows || y >= columns || x < 0 || y < 0){
        cerr << TXT_DARK_RED_1 << ERR_INVALID_COORDINATES << END_COLOR << endl << endl;
        status = false;
    }
    else{
        if(cellPtrMatrix[x][y]->getCellIdentifier() == FIELD_IDENTIFIER){
            if(((CellBuildable*)cellPtrMatrix[x][y])->demolish(demolishedBuilding) == true){
                status = true;
            } 
            else{
                status = false;
                cerr << TXT_DARK_RED_1 << ERR_NO_BUILDING_TO_DEMOLISH << END_COLOR << endl << endl;
            } 
        }
        else{
            cerr << TXT_DARK_RED_1 << ERR_NOT_BUILDABLE_CELL << END_COLOR << endl << endl;
            status = false;
        }
    }
    return status;
}

void Map::printMap(){
    for(int i = 0; i < rows; i++){
        for(int j = 0; j < columns; j++){
            cellPtrMatrix[i][j]->showCell();
        }
        cout << endl;
    }
}

void Map::printCellInfo(int row, int column){
    cellPtrMatrix[row][column]->showCellInfo();
}

bool Map::validateCoordinates(int row, int column){
    if (this->rows > row && this->columns > column)
        return true;
    else    
        return false;
}