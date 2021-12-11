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

void ConstruirObelisco::obtener_objetivo(){
    cout << "Más alto que las nubes: construir el obelisco." << endl;
    cout << '\t' << "Cumpliendo este objetivo se gana la partida" << endl;
}

bool ConstruirObelisco::chequear_estado(Inventario & inventario, int puntos_energia, Lista<Ubicaciones> & edificios, Constructor & bob, bool fin_turno)
{
    bool obelisco = false;

    for(int i = 1; i < edificios.mostrar_cantidad() + 1; i++)
        if(obtener_nombre(edificios[i]) == "obelisco")
            objetivo_cumplido = true;
            
    return obelisco;
}

bool ConstruirObelisco::es_principal(){
    return true;
}

