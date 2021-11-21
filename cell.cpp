#include <string>
#include <iostream>

#include "cell.h"

using namespace std;

Cell::Cell(){
    coordinateX = 0; 
    coordinateY = 0; 
    cellIdentifier.clear();
}

Cell::~Cell(){
}

void Cell::setCellIdentifier(string cellIdentif){
    cellIdentifier = cellIdentif;
}

void Cell::setCoordinates(int x, int y){
    coordinateX = x;
    coordinateY = y;
}

string Cell::getCellIdentifier()const{
    return cellIdentifier;
}

int Cell::getCoordinateX()const{
    return coordinateX;
}

int Cell::getCoordinateY()const{
    return coordinateY;
}

Cell::Cell(int x, int y, string identif){
    coordinateX = x;
    coordinateY = y;
    cellIdentifier = identif;
}

