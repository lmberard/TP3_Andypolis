#include <string>
#include <iostream>

#include "construirObelisco.hpp"

using namespace std;

ConstruirObelisco::ConstruirObelisco() : Objetivo()
{
}

ConstruirObelisco::~ConstruirObelisco()
{
}

void ConstruirObelisco::mostrar_objetivo()
{
    msjeTitulo("* Mas alto que las nubes: construir el obelisco.");
    cout << TXT_LIGHT_BLUE_6 << '\t' << "Cumpliendo este objetivo se gana la partida.\n"
         << END_COLOR << endl;
}

void ConstruirObelisco::chequear_estado(Inventario &inventario, int puntos_energia, Lista<Ubicaciones> &edificios, Constructor &bob, bool fin_turno)
{

    for (int i = 1; i < edificios.mostrar_cantidad() + 1; i++)
        if (obtener_nombre(edificios[i]) == "obelisco")
            objetivo_cumplido = true;
}

bool ConstruirObelisco::es_principal()
{
    return true;
}
