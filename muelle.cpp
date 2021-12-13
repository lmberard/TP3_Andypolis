#include "muelle.hpp"

Muelle::Muelle(){
    caracteristicas();
}

void Muelle::caracteristicas(){
    casillero_nombre = "muelle";
    color = BGND_BROWN_94;  
}

void Muelle::desrecorrer(){
    color = BGND_BROWN_94; 
}
