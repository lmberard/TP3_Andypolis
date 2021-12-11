#include "comprar.hpp"

void Comprar::jugar(Constructor & bob, Mapa & mapa, int & turno, Jugador * jugador, int & id_jugador_actual)
{
    string aux;
    int cant;
    
    if(jugador[id_jugador_actual -1].obtener_energia() >= 5){

        msjeInstruccion("Ingrese la cantidad de bombas que desea comprar: ");
        getline(cin,aux);
        if(es_numero_y_positivo(aux)){
            cant = stoi(aux);
        
            if(cant*100 <= jugador[id_jugador_actual -1].inv().obtener_andycoins()){
            
                jugador[id_jugador_actual -1].inv().modificar_cant_material("bombas",cant);
                jugador[id_jugador_actual -1].inv().agregar_bombas_compradas(cant);
                jugador[id_jugador_actual -1].inv().aniadir_cant_material("andycoins", -cant*100);
                jugador[id_jugador_actual -1].inv().aniadir_andycoins_gastadas(cant*100);
                cout << TXT_LIGHT_BLUE_6 << "Ahora posee " << jugador[id_jugador_actual -1].inv().obtener_andycoins() << "andycoins." << END_COLOR << endl;
            
                jugador[id_jugador_actual-1].decrementar_puntos_energia(5);

                bool fin_turno = false;
                jugador[id_jugador_actual-1].chequear_objetivos(fin_turno,bob);
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