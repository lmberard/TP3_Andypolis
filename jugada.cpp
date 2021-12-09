#include "jugada.hpp"

Jugada::Jugada(){}
Jugada::~Jugada(){}
        
Coordenada Jugada::pedir_coordenadas()
{
    int x, y;
    string aux;
    msjeInstruccion("Ingrese las coordenadas:");

    msjeInstruccion("Coordenada X:");
    getline(cin, aux);
    if (es_coordenada(aux) == true)
        x = stoi(aux);

    msjeInstruccion("Coordenada Y:");
    getline(cin, aux);
    if (es_coordenada(aux) == true)
        y = stoi(aux);
    
    return crear_coordenada(x, y);
}

int Jugada::pedir_id_jugador()
{
    msjeInstruccion("Seleccione un jugador (ingrese el numero):");
    for (int i = 0; i < 2; i++)
        msjeInstruccion(to_string(i + 1) + ": Jugador nro " + to_string(i + 1));
        //verificar si es valido (esto no porque se hace en otro lado)
        //verificar que se ingrese un numero entero
    int id;
    cin >> id;
    
    return id;
}

bool Jugada::id_jugador_es_valido(int id_jugador)
{
    if (id_jugador < 1 || id_jugador > 2){
        msjeError("No existe ese numero de jugador");
        return false;
    }
    else
        return true;
}

void Jugada::setear_coordenada_jugador(int id_jugador, Jugador * jugadores, Mapa & mapa)
{
    msjeInstruccion("Jugador " + to_string(id_jugador) + ", donde quiere empezar el juego?");
    Coordenada coord_jugador = pedir_coordenadas();
    //esto deberia ser un loop para que te siga pidiendo
    if(mapa.coordenadas_validas(coord_jugador))
        jugadores[id_jugador - 1].setear_posicion(coord_jugador);
}

        