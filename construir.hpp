#ifndef CONSTRUIR_HPP
#define CONSTRUIR_HPP

#include "jugada.hpp"

class Construir : public Jugada{
    public: 
        void jugar(Constructor & bob, Mapa & mapa, int & turno, Jugador * jugadores, int & id_jugador_actual);
        bool chequear_existencia_de_edificio(Constructor & bob, string edificio);
        bool chequear_requerimientos_edificio(Edificio * edif_ptr, Jugador & jugador);
        bool chequear_edificios_disponibles(Edificio * edif_ptr, Jugador & jugador);
        bool descontar_materiales(Edificio * edif_ptr, Jugador & jugador);

};

#endif //CONSTRUIR_HPP



