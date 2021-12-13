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

void msjeConfirmacion(string msje)
{
    cout << TXT_PINK_197 << msje << END_COLOR << endl;
}

void msjeInfo(string msje)
{
    cout << TXT_LIGHT_PURPLE_104 << msje << END_COLOR << endl;
}

void msjeTitulo(string msje)
{
    cout << TXT_BOLD << TXT_UNDERLINE << TXT_LIGHT_BLUE_6 << msje << END_COLOR << endl;
}

void msjeH1(string msje)
{
    cout << TXT_BOLD << TXT_UNDERLINE << TXT_BLUE_12 << msje << END_COLOR << endl;
}

void msjeColor(string msje, string color)
{
    cout << color << msje << END_COLOR << endl;
}
