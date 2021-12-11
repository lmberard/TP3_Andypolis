#ifndef MODIFICAREDIFICIO_HPP
#define MODIFICAREDIFICIO_HPP

#include "jugada.hpp"

class ModificarEdificio : public Jugada{
    public: 
        void jugar(Constructor & bob, Mapa & mapa, int & turno, Jugador * jugador, int & id_jugador_actual){
            string nombre_edificio;
            int numero_madera, numero_piedra, numero_metal;
            bool madera_ok, metal_ok, piedra_ok;
            //bool entrada;

            //TODO: FALTA PREGUNTAR SI ALGUN PARAMETRO DESEA NO MODIFICARLO Y TAMBIÉN QUE SEA ENTRE 0 Y 50000

            msjeInstruccion("Ingrese el edificio que desea modificar: ");
            getline(cin, nombre_edificio);

            if(bob.existe(nombre_edificio) == true && nombre_edificio != "obelisco"){
                
                Edificio *edificio = bob.mostrar_edificio(nombre_edificio);

                if(modificar_madera(numero_madera, madera_ok) == true){
                    if (modificar_piedra(numero_piedra, piedra_ok) == true){
                        if (modificar_metal(numero_metal, metal_ok) == true){
                            if(madera_ok)
                                edificio->setear_madera(numero_madera);
                            if(piedra_ok)
                                edificio->setear_piedra(numero_piedra);
                            if(metal_ok)
                                edificio->setear_metal(numero_metal);
                        }
                    }
                }

            } else {msjeError("El nombre del edificio que usted ingreso no es modificable");}
        }

        bool modificar_madera(int& numero_madera, bool& confirmacion){
            string cantidad_madera;
            bool entrada_correcta = true;

            msjeInstruccion("Desea cambiar la cantidad de madera que requiere el edificio?");
            if(pedir_confirmacion() == OPCION_DE_CONFIRMACION){
                confirmacion = true;
                msjeInstruccion("Ingrese la cantidad de madera que desea modificar: ");
                getline(cin, cantidad_madera);
                if(es_numero_y_positivo(cantidad_madera) == true && stoi(cantidad_madera) < 50000){
                    numero_madera = stoi(cantidad_madera); 
                } else{entrada_correcta = false;}
            } else{confirmacion = false;}

            return entrada_correcta;
        }

        bool modificar_piedra(int& numero_piedra, bool& confirmacion){
            string cantidad_piedra;
            bool entrada_correcta = true;

            msjeInstruccion("Desea cambiar la cantidad de piedra que requiere el edificio?");
            if(pedir_confirmacion() == OPCION_DE_CONFIRMACION){
                confirmacion = true;
                msjeInstruccion("Ingrese la cantidad de piedra que desea modificar: ");
                getline(cin, cantidad_piedra);
                if(es_numero_y_positivo(cantidad_piedra) == true && stoi(cantidad_piedra) < 50000){
                    numero_piedra = stoi(cantidad_piedra);
                } else{entrada_correcta = false;}            
            } else{confirmacion = false;}

            return entrada_correcta;
        }

        bool modificar_metal(int& numero_metal, bool& confirmacion){
            string cantidad_metal;
            bool entrada_correcta = true;

            msjeInstruccion("Desea cambiar la cantidad de metal que requiere el edificio?");
            if(pedir_confirmacion() == OPCION_DE_CONFIRMACION){
                confirmacion = true;
                msjeInstruccion("Ingrese la cantidad de metal que desea modificar: ");
                getline(cin, cantidad_metal);
                if(es_numero_y_positivo(cantidad_metal) == true && stoi(cantidad_metal) < 50000){
                    numero_metal = stoi(cantidad_metal); 
                } else{entrada_correcta = false;}           
            } else{confirmacion = false;}

            return entrada_correcta;
        }

};


#endif //MODIFICAREDIFICIO_HPP