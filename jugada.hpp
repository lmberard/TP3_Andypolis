#ifndef JUGADA_HPP
#define JUGADA_HPP

#include "colors.hpp"
#include "constructor.hpp"
#include "mapa.hpp"
#include "jugador.hpp"
#include "ubicaciones.hpp"

static const int OPCION_DE_CONFIRMACION = 1;

class Jugada
{
public:
    Jugada();

    virtual void jugar(Constructor &, Mapa &, int &, Jugador *, int &) = 0;

    Coordenada pedir_coordenadas();
    string pedir_edificio();
    int pedir_confirmacion();

    int pedir_id_jugador();

    bool id_jugador_es_valido(int id_jugador);

    void setear_coordenada_jugador(int id_jugador, Jugador *jugadores, Mapa &mapa);

    virtual ~Jugada();
};

#endif // JUGADA_HPP
