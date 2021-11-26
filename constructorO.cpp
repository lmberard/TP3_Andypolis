#include <string>
#include <iostream>

#include "constructorO.hpp"

using namespace std;

ConstructorO::ConstructorO(string objetivo, string tipo) : Objetivo(objetivo, tipo)
{
}

ConstructorO::~ConstructorO()
{
}