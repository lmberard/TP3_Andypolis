#include <string>
#include <iostream>

#include "cellIntransitable.h"
#include "constants.h"
#include "colors.h"

using namespace std;


CellIntransitable::CellIntransitable() : Cell(){
}

CellIntransitable::~CellIntransitable(){
}

void CellIntransitable::showCell(){
    cout << BGND_BLUE_19 << '|' << ' ' << '|' << END_COLOR;
}

void CellIntransitable::showCellInfo(){
    cout << TXT_ORANGE_166 << "Este casillero es un lago" << END_COLOR << endl << endl;
}

CellIntransitable::CellIntransitable(int x, int y, string identif) : Cell(x, y, identif){
}
