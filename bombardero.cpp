#include <string>
#include <iostream>

#include "bombardero.hpp"

using namespace std;

Bombardero::Bombardero(string objetivo, string tipo) : Objetivo(objetivo, tipo)
{
}

Bombardero::~Bombardero()
{
}
