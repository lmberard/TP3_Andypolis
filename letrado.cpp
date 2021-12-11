#include <string>
#include <iostream>

#include "letrado.hpp"

using namespace std;

Letrado::Letrado() : Objetivo()
{
    progreso = 0;
}

Letrado::~Letrado()
{
}

void Letrado::chequear_estado(Inventario & inventario, int puntos_energia, Lista<Ubicaciones> & edificios, Constructor & bob, bool fin_turno)
{   
    string escuela = "escuela";

    for (int i = 1; i < edificios.mostrar_cantidad() + 1; i++)
        if (edificios[i].nombre == "escuela")
            progreso = obtener_cantidad(edificios[i]);

    if(progreso == bob.mostrar_edificio(escuela)->obtener_cant_max())
        objetivo_cumplido = true;

}

void Letrado::mostrar_objetivo(){
    cout << "Letrado: haber construido el máximo posible de escuelas." << endl;
    cout << "Por ahora construistes " << progreso << " escuelas" << endl;
    if(objetivo_cumplido)
        cout << "el objetivo está cumplido" << endl;
    else
        cout << "el objetivo no está cumplido" << endl;
}

bool Letrado::es_principal(){
    return false;
}
