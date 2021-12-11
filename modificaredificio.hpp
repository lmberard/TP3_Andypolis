#ifndef MODIFICAREDIFICIO_HPP
#define MODIFICAREDIFICIO_HPP

#include "jugada.hpp"

class ModificarEdificio : public Jugada{
    public: 
        void jugar(Constructor & bob, Mapa & mapa, int & turno, Jugador * jugador, int & id_jugador_actual){
            string nombre_edificio;
            string cantidad_madera, cantidad_piedra, cantidad_metal;
            //bool entrada;

            //TODO: FALTA PREGUNTAR SI ALGUN PARAMETRO DESEA NO MODIFICARLO Y TAMBIÉN QUE SEA ENTRE 0 Y 50000

            msjeInstruccion("Ingrese el edificio que desea modificar: ");
            getline(cin, nombre_edificio);

            if(bob.existe(nombre_edificio) == true && nombre_edificio != "obelisco"){
                
                Edificio *edificio = bob.mostrar_edificio(nombre_edificio);

                msjeInstruccion("Ingrese la cantidad de madera que desea: ");
                getline(cin, cantidad_madera);

                if(es_numero_y_positivo(cantidad_madera) == true && stoi(cantidad_madera) < 50000){                  

                    msjeInstruccion("Ingrese la cantidad de piedra que desea: ");
                    getline(cin, cantidad_piedra);
                    if(es_numero_y_positivo(cantidad_piedra) == true && stoi(cantidad_piedra) < 50000){
                        
                        msjeInstruccion("Ingrese la cantidad de metal que desea: ");
                        getline(cin, cantidad_metal);

                        if(es_numero_y_positivo(cantidad_metal) == true && stoi(cantidad_metal) < 50000){
                            edificio->setear_madera(stoi(cantidad_madera));
                            edificio->setear_piedra(stoi(cantidad_piedra));
                            edificio->setear_metal(stoi(cantidad_metal));
                        } else {msjeError("Usted a ingresado una cantidad de metal incorrecta.");}

                    } else {msjeError("Usted a ingresado una cantidad de piedra incorrecta.");}

                } else {msjeError("Usted a ingresado una cantidad de madera incorrecta.");}

            } else {msjeError("El nombre del edificio que usted ingreso no es modificable");}
        }
};


#endif //MODIFICAREDIFICIO_HPP