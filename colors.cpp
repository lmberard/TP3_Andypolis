#include "colors.hpp"

void msjeError(string msje)
{
    cout << TXT_LIGHT_RED_9 << msje << END_COLOR << endl;
}

void msjeOK(string msje)
{
    cout << TXT_LIGHT_GREEN_46 << msje << END_COLOR << endl;
}

void msjeInstruccion(string msje)
{
    cout << TXT_LIGHT_BLUE_6 << msje << END_COLOR << endl;
}

void msjeColor(string msje, string color)
{
    cout << color << msje << END_COLOR << endl;
}
