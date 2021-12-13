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

class ModificarEdificio : public Jugada
{
public:
    void jugar(Constructor &bob, Mapa &mapa, int &turno, Jugador *jugador, int &id_jugador_actual);

    bool modificar_madera(int &numero_madera, bool &confirmacion);

    bool modificar_piedra(int &numero_piedra, bool &confirmacion);

    bool modificar_metal(int &numero_metal, bool &confirmacion);
};

#endif // MODIFICAREDIFICIO_HPP