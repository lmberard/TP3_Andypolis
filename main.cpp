#include <iostream>
#include <string>
#include <fstream>

#include "menu.hpp"
#include "ciudad.hpp"

using namespace std;

int main()
{

    string rta = " ";
    string si = "si";
    string no = "no";
    do
    {
        mostrar_InstruccionInicial();
        rta = devolver_rta_usuario();
        if (strings_son_iguales(rta, si))
        {
            Terreno terreno;
            Constructor bob("edificios.txt");
            Recurso recurso;

            Ciudad andypolis("mapa.txt", "materiales.txt", "ubicaciones.txt", terreno, bob, recurso);

            mostrar_menuInicial(andypolis, bob, recurso);
            return 0;
        }
        else if (!strings_son_iguales(rta, no))
            msjeError("Error. Opciones validas: 'si' o 'no'");
    } while (!strings_son_iguales(rta, no));

    msjeInstruccion("Hasta luego!! :)");

    return 0;
}