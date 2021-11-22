#include <string>
#include <iostream>

#include "energetico.hpp"

using namespace std;

Energetico::Energetico(string objetivo, string tipo) : Objetivo(objetivo, tipo)
{
}

Energetico::~Energetico()
{
}
