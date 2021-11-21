#include <string>
#include <iostream>

#include "arrayOfCoordinates.h"

using namespace std;

ArrayOfCoordinates::ArrayOfCoordinates(){
    arrayOfCoordinates = nullptr;
    size = 0;
    allocSize = 0;
}

ArrayOfCoordinates::~ArrayOfCoordinates(){
  if(arrayOfCoordinates != nullptr) {
    delete[] arrayOfCoordinates;
    arrayOfCoordinates = nullptr;
  }
}

int ArrayOfCoordinates::getSize()const{
    return size;
}

void ArrayOfCoordinates::pushBack(int row, int column){

    if(size >= allocSize){
        CoordinatesOfBuilding * aux;
        aux = new CoordinatesOfBuilding[allocSize + 4];
        if(arrayOfCoordinates != nullptr){
          for (int i = 0; i < size; i++){
              aux[i] = arrayOfCoordinates[i];
              aux[i].row = arrayOfCoordinates[i].row;
              aux[i].column = arrayOfCoordinates[i].column;
          }
          delete[] arrayOfCoordinates;
        }
        arrayOfCoordinates = aux;
        allocSize += 4; 
    }

    arrayOfCoordinates[size].row = row;
    arrayOfCoordinates[size].column = column;
    size++;
}

void ArrayOfCoordinates::deletee(int row, int column){
    
    for (int i = 0; i < size; i++){
            if(arrayOfCoordinates[i].row == row && arrayOfCoordinates[i].column == column){
                for(;i < size-1; i++){
                    arrayOfCoordinates[i].row = arrayOfCoordinates[i+1].row;
                    arrayOfCoordinates[i].column = arrayOfCoordinates[i+1].column;
                }
            size--;
            }
    }

}

void ArrayOfCoordinates::print(){

    for(int i = 0; i < size; i++){
        cout << "(" << arrayOfCoordinates[i].row << ","
        << " " << arrayOfCoordinates[i].column << ")" << " ";
    }
}

CoordinatesOfBuilding ArrayOfCoordinates::operator[](size_t index){
    return arrayOfCoordinates[index];
}
