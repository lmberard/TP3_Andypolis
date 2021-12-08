#ifndef JUEGO_HPP
#define JUEGO_HPP

#include "lista.hpp"
#include "ubicaciones.hpp"

#include "constructor.hpp"
#include "recurso.hpp"
#include "superficie.hpp"

#include "jugador.hpp"
#include "mapa.hpp"

//#include "jugada.hpp"

#include "menu2.hpp"
#include "parser.hpp"

#include "construirObelisco.hpp"

const int LLUVIA_METAL_MIN = 2;
const int LLUVIA_METAL_MAX = 4;
const int LLUVIA_MADERA_MIN = 0;
const int LLUVIA_MADERA_MAX = 3;
const int LLUVIA_PIEDRA_MIN = 1;
const int LLUVIA_PIEDRA_MAX = 2;

const int CANT_MADERA_BLOQUE = 50;
const int CANT_PIEDRA_BLOQUE = 100;
const int CANT_METAL_BLOQUE = 50;

const int CANT_JUGADORES = 2;
const int CANT_OBJETIVOS_SECUNDARIOS_JUEGO = 10; 
const int CANT_OBJETIVOS_SECUNDARIOS_JUGADOR = 3; 

const int CANT_ENERGIA_FIN_PARTIDA = 20;
const int CANT_ENERGIA_NUEVA_PARTIDA = 50;
const int CANT_ENERGIA_MAXIMA = 100;
const int CANT_ENERGIA_MINIMA = 0;

const int CANT_ENERGIA_CONSTRUIR = 15;
const int CANT_ENERGIA_LISTAR_EDIF = 0;
const int CANT_ENERGIA_DEMOLER = 15;
const int CANT_ENERGIA_ATACAR = 30;
const int CANT_ENERGIA_REPARAR = 25;
const int CANT_ENERGIA_COMPRAR_BOMBAS = 5;
const int CANT_ENERGIA_CONSULTAR = 0;
const int CANT_ENERGIA_MOSTRAR_OBJ = 0;
const int CANT_ENERGIA_MOSTRAR_INV = 0;
const int CANT_ENERGIA_RECOLECTAR = 20;
class Juego
{
private:

    //elementos del juego: casilleros, edificios y materiales
    Superficie superficie;
    Constructor bob;
    Recurso recurso;

    //mapa del juego
    Mapa mapa;
 
    //jugadores:
    Jugador jugadores[CANT_JUGADORES];

    //Gestor de archivos para cargar una partida del juego y sus elementos 
    Parser archivo;

    //Menú del juego
    Menu menu;

    //Estado del juego, quien esta jugando ahora mismo y si la partida es nueva o no
    int id_jugador_actual;
    bool partida_nueva = true; 

public:
    //--------------------CONSTRUCTORES DESTRUCTORES-------------------
    Juego();
    ~Juego();

    void jugar();

private:

    void preparar_partida();
    void asignar_objetivos();
    void comenzar_partida();
    
    void lluvia_recursos();
    void colocar_material_random(int , string, const int );
    void celebrar();

};
#endif //JUEGO_HPP