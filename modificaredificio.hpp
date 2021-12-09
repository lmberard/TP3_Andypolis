#ifndef MODIFICAREDIFICIO_HPP
#define MODIFICAREDIFICIO_HPP

#include "jugada.hpp"

class ModificarEdificio : public Jugada{
    public: 
        void jugar(Constructor & bob, Mapa & mapa, int & turno, Jugador * jugador, int & id_jugador_actual){
            cout << "MODIFICAR EDIFICIO POR NOMBRE NO HECHO" << endl; 
            cout << "MODIFICA TODO A 1000 UN ASERRADERO A VER SI FUNCA LA IDEA" << endl;
            string aserradero = "aserradero";
            Edificio *edificio = bob.mostrar_edificio(aserradero);
            edificio->setear_madera(1000);
            edificio->setear_metal(1000);
            edificio->setear_piedra(1000);
        }
};


#endif //MODIFICAREDIFICIO_HPP