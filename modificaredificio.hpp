#ifndef MODIFICAREDIFICIO_HPP
#define MODIFICAREDIFICIO_HPP

#include "jugada.hpp"

static const string INGRESE_EDIFICIO_A_MODIFICAR = "Ingrese el edificio que desea modificar: ";
static const string NOMBRE_EDIFICIO_OBELISCO = "obelisco";
static const string ERROR_NOMBRE_EDIFICIO = "El nombre del edificio que usted ingreso no es modificable";
static const string DESEA_CAMBIAR_MADERA = "Desea cambiar la cantidad de madera que requiere el edificio?";
static const string DESEA_CAMBIAR_PIEDRA = "Desea cambiar la cantidad de piedra que requiere el edificio?";
static const string DESEA_CAMBIAR_METAL = "Desea cambiar la cantidad de metal que requiere el edificio?";
static const string INGRESE_VALOR_MADERA = "Ingrese la cantidad de madera que desea modificar: ";
static const string INGRESE_VALOR_PIEDRA = "Ingrese la cantidad de piedra que desea modificar: ";
static const string INGRESE_VALOR_METAL = "Ingrese la cantidad de metal que desea modificar: ";
static const string ERR_NUMERO_INVALIDO = "El numero ingresado es incorrecto";

class ModificarEdificio : public Jugada{
    public: 
        void jugar(Constructor & bob, Mapa & mapa, int & turno, Jugador * jugador, int & id_jugador_actual){
            string nombre_edificio;
            int numero_madera, numero_piedra, numero_metal;
            bool madera_ok, metal_ok, piedra_ok;
            //bool entrada;

            //TODO: FALTA PREGUNTAR SI ALGUN PARAMETRO DESEA NO MODIFICARLO Y TAMBIÉN QUE SEA ENTRE 0 Y 50000

            msjeInstruccion(INGRESE_EDIFICIO_A_MODIFICAR);
            getline(cin, nombre_edificio);

            if(bob.existe(nombre_edificio) == true && nombre_edificio != NOMBRE_EDIFICIO_OBELISCO){
                
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

            } else {msjeError(ERROR_NOMBRE_EDIFICIO);}
        }

        bool modificar_madera(int& numero_madera, bool& confirmacion){
            string cantidad_madera;
            bool entrada_correcta = true;

            msjeInstruccion(DESEA_CAMBIAR_MADERA);

            int pedir_conf = pedir_confirmacion();
            
            if(pedir_conf == OPCION_DE_CONFIRMACION){
                confirmacion = true;
                msjeInstruccion(INGRESE_VALOR_MADERA);
                getline(cin, cantidad_madera);
                if(es_numero_y_positivo(cantidad_madera) == true && stoi(cantidad_madera) < 50000){
                    numero_madera = stoi(cantidad_madera); 
                }   else{
                        entrada_correcta = false;
                        msjeError(ERR_NUMERO_INVALIDO);
                    }
            }   else if(pedir_conf == -1){
                    entrada_correcta = false;
                } else {confirmacion = false;}

            return entrada_correcta;
        }

        bool modificar_piedra(int& numero_piedra, bool& confirmacion){
            string cantidad_piedra;
            bool entrada_correcta = true;

            msjeInstruccion(DESEA_CAMBIAR_PIEDRA);
            int pedir_conf = pedir_confirmacion();

            if(pedir_conf == OPCION_DE_CONFIRMACION){
                confirmacion = true;
                msjeInstruccion(INGRESE_VALOR_PIEDRA);
                getline(cin, cantidad_piedra);
                if(es_numero_y_positivo(cantidad_piedra) == true && stoi(cantidad_piedra) < 50000){
                    numero_piedra = stoi(cantidad_piedra);
                }   else{
                        entrada_correcta = false;
                        msjeError(ERR_NUMERO_INVALIDO);
                    }            
            }   else if(pedir_conf == -1){
                    entrada_correcta = false;
                } else {confirmacion = false;}

            return entrada_correcta;
        }

        bool modificar_metal(int& numero_metal, bool& confirmacion){
            string cantidad_metal;
            bool entrada_correcta = true;

            msjeInstruccion(DESEA_CAMBIAR_METAL);
            int pedir_conf = pedir_confirmacion();
            if(pedir_conf == OPCION_DE_CONFIRMACION){
                confirmacion = true;
                msjeInstruccion(INGRESE_VALOR_METAL);
                getline(cin, cantidad_metal);
                if(es_numero_y_positivo(cantidad_metal) == true && stoi(cantidad_metal) < 50000){
                    numero_metal = stoi(cantidad_metal); 
                }   else{
                        entrada_correcta = false;
                        msjeError(ERR_NUMERO_INVALIDO);
                    }           
            }   else if(pedir_conf == -1){
                    entrada_correcta = false;
                } else {confirmacion = false;}


            return entrada_correcta;
        }

};


#endif //MODIFICAREDIFICIO_HPP