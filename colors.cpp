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

void msjeTitulo(string msje)
{
    cout << TXT_BOLD << TXT_UNDERLINE << BGND_DARK_BLUE_17 << msje << END_COLOR << endl;
}

void msjeInfo(string msje)
{
    cout << msje << endl;
}
