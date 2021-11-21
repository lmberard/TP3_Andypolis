#include <string>
#include <iostream>

#include "school.h"
#include "constants.h"

using namespace std;


School::School() : Building(){
    identifier = SCHOOL_IDENTIFIER;
}


School::~School(){
}
