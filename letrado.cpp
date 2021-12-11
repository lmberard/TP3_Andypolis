#include <string>
#include <iostream>

#include "letrado.hpp"

using namespace std;

Letrado::Letrado() : Objetivo()
{
}

Letrado::~Letrado()
{
}

bool Letrado::chequear_estado(Inventario & inventario, int puntos_energia, Lista<Ubicaciones> & edificios, Constructor & bob, bool fin_turno)
{   

    int cantidad;
    string escuela = "escuela";

    for (int i = 1; i < edificios.mostrar_cantidad() + 1; i++)
        if (edificios[i].nombre == "escuela")
            cantidad = obtener_cantidad(edificios[i]);

    if(cantidad == bob.mostrar_edificio(escuela)->obtener_cant_max())
        objetivo_cumplido = true;

    return false;
}

void Letrado::obtener_objetivo(){
    cout << "Letrado: haber construido el máximo posible de escuelas." << endl;
    //cout << "Por ahora construistes " << cantidad << "escuelas" << endl;
    if(objetivo_cumplido)
        cout << "el objetivo está cumplido" << endl;
    else
        cout << "el objetivo no está cumplido" << endl;
}

bool Letrado::es_principal(){
    return false;
}
