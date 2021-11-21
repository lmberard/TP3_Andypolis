#include <string>
#include <iostream>

#include "power_plant.h"
#include "constants.h"

using namespace std;


PowerPlant::PowerPlant() : Building(){
    identifier = POWER_PLANT_IDENTIFIER;
}


PowerPlant::~PowerPlant(){
}
