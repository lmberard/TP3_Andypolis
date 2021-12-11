#include "comprar.hpp"

void Comprar::jugar(Constructor & bob, Mapa & mapa, int & turno, Jugador * jugador, int & id_jugador_actual)
{
    string aux;
    int cant;
    int aux_int;
    
    if(jugador[id_jugador_actual -1].obtener_energia() >= 5){

        cout << "ingrese la cantidad de bombas que desea comprar: " << endl;
        getline(cin,aux);
        cant = stoi(aux);
        
        if(cant*100 <= jugador[id_jugador_actual -1].inv().obtener_andycoins()){
            
            jugador[id_jugador_actual -1].inv().modificar_cant_material("bombas",cant);
            aux_int = jugador[id_jugador_actual -1].inv().obtener_andycoins();
            jugador[id_jugador_actual -1].inv().modificar_cant_material("andycoins", aux_int - cant*100);
            cout << "quedan ahora " << jugador[id_jugador_actual -1].inv().obtener_andycoins() << "andycoins" << endl;
            
            jugador[id_jugador_actual-1].modificar_puntos_energia(-5);
        }
        else
            cout << "no hay suficiente platita" << endl;
                
        bool fin_turno = false;
        jugador[id_jugador_actual-1].chequear_objetivos(fin_turno,bob);
    }
}