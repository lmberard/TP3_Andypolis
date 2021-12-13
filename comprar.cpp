#include "comprar.hpp"

void Comprar::jugar(Constructor &bob, Mapa &mapa, int &turno, Jugador *jugador, int &id_jugador_actual)
{
    string aux;
    int cant;

    if (jugador[id_jugador_actual - 1].obtener_energia() >= 5)
    {
        cout << left << TXT_BOLD << TXT_AQUA_36
             << setw(40) << "Precio de cada bomba:" << '\t'
             << setw(40) << to_string(PRECIO_BOMBA) + " andycoins." << endl
             << setw(40) << "Cantidad de andycoins disponibles" << '\t'
             << setw(40) << jugador[id_jugador_actual - 1].inv().obtener_andycoins()
             << END_COLOR << endl;

        msjeInstruccion("\nIngrese la cantidad de bombas que desea comprar: ");
        getline(cin, aux);
        if (es_numero_y_positivo(aux))
        {
            cant = stoi(aux);

            if (cant * PRECIO_BOMBA <= jugador[id_jugador_actual - 1].inv().obtener_andycoins())
            {

                jugador[id_jugador_actual - 1].inv().modificar_cant_material("bombas", cant);
                jugador[id_jugador_actual - 1].inv().agregar_bombas_compradas(cant);
                jugador[id_jugador_actual - 1].inv().aniadir_cant_material("andycoins", -cant * PRECIO_BOMBA);
                jugador[id_jugador_actual - 1].inv().aniadir_andycoins_gastadas(cant * PRECIO_BOMBA);
                msjeOK("\nSe descontaron los andycoins necesarios. Ahora posee " + to_string(jugador[id_jugador_actual - 1].inv().obtener_andycoins()) + " andycoins.");

                jugador[id_jugador_actual - 1].decrementar_puntos_energia(5);

                bool fin_turno = false;
                jugador[id_jugador_actual - 1].chequear_objetivos(fin_turno, bob);
            }
            else
                msjeError("No hay suficiente dinero.");
        }
        else
            msjeError("No es valido lo que ingresaste.");
    }
    else
        msjeError("No posee energia suficiente.");
}
