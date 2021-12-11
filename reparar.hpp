#ifndef REPARAR_HPP
#define REPARAR_HPP

#include "jugada.hpp"

static const int ENERGIA_NECESARIA_PARA_REPARAR = 25;

class Reparar : public Jugada{
    public: 
        void jugar(Constructor & bob, Mapa & mapa, int & turno, Jugador * jugadores, int & id_jugador_actual);
        bool chequear_si_requiere_reparacion(Edificio * edif_ptr);
        bool chequear_materiales_reparacion(Edificio * edif_ptr, Jugador & jugador);
        void imprimir_edificio_reparado(Edificio * edif_ptr);
        bool descontar_materiales(Edificio * edif_ptr, Jugador & jugador);
};
#endif //REPARAR_HPP