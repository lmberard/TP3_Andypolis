#include "juego2.hpp"
//--------------------CONSTRUCTORES DESTRUCTORES-------------------
Juego::Juego()
{   
    //carga los datos de los edificios en el diccionario del constructor
    archivo.cargar(bob);
    
    //crea la superficie del mapa 
    archivo.cargar(superficie,mapa);

    //carga el inventario de cada jugador 
    archivo.cargar(recurso,jugadores);

    //carga una partida guardada 
    if(archivo.cargar_partida_guardada(mapa,jugadores,bob,recurso))
        partida_nueva = true;
}

Juego::~Juego()
{   
    //guarda los valores seteados en edificios.txt
    archivo.guardar(bob);

    //guarda el inventario de los jugadores en materiales.txt
    archivo.guardar_inventario(jugadores);

    //guarda la partida 
    archivo.guardar_partida(mapa,jugadores);
}

void Juego::jugar()
{
    if (partida_nueva)
    {
        preparar_partida();
    }

    if(!partida_nueva)
    {
        comenzar_partida();
    }
}

void Juego::preparar_partida()
{
    bool partida = true;
    Jugada * opcion;
    int comenzar = 0;

    do{  
        menu.partida_nueva_mostrar();
        opcion = menu.inicial();
        if(opcion)
            opcion->jugar(bob,mapa,comenzar,jugadores,id_jugador_actual);
        delete opcion;
        if(comenzar == 1){    
            opcion = NULL;
            partida = false;
        }
        menu.volver();
    }while(opcion);

    partida_nueva = partida;
}

void Juego::asignar_objetivos(){
    int numero;
    bool flag;

    for(int i = 0; i < CANT_JUGADORES ; i++){
        jugadores[i].asignar_objetivos_jugador(new ConstruirObelisco()); //Objetivo principal
        int numeros_generados[CANT_OBJETIVOS_SECUNDARIOS_JUGADOR] = {}; //inicializa en 0;

        for(int j = 0; j < CANT_OBJETIVOS_SECUNDARIOS_JUGADOR; j++){
            
            do{
                flag = false;
                numero = rand()%(1 - CANT_OBJETIVOS_SECUNDARIOS_JUEGO + 1) + CANT_OBJETIVOS_SECUNDARIOS_JUEGO; 
                for (int k = 0; k < CANT_OBJETIVOS_SECUNDARIOS_JUGADOR; k++){
                    if(numeros_generados[k] == numero)
                        flag = true;
                }
            } while(flag == true);     
            
            numeros_generados[j] = numero;

            if(numero == 1)
                jugadores[i].asignar_objetivos_jugador(new ComprarAndypolis());
            if(numero == 2)
                jugadores[i].asignar_objetivos_jugador(new EdadDePiedra());    
            if(numero == 3)
                jugadores[i].asignar_objetivos_jugador(new Bombardero());
            if(numero == 4)
                jugadores[i].asignar_objetivos_jugador(new Energetico());
            if(numero == 5)
                jugadores[i].asignar_objetivos_jugador(new Letrado());
            if(numero == 6)
                jugadores[i].asignar_objetivos_jugador(new Minero());
            if(numero == 7)
                jugadores[i].asignar_objetivos_jugador(new Cansado());
            if(numero == 8)
                jugadores[i].asignar_objetivos_jugador(new ConstructorO());
            if(numero == 9)
                jugadores[i].asignar_objetivos_jugador(new Armado());
            if(numero == 10)
                jugadores[i].asignar_objetivos_jugador(new Extremista());
                   
        }
    }
}

void Juego::comenzar_partida()
{   
    Jugada * jugada;
    int turno = 0;
    bool ganador = false;

    asignar_objetivos();
    //lluvia_recursos();
    
    do{  
        mapa.mostrar();
        menu.mostrar_menu_juego(id_jugador_actual);
        jugada = menu.menu_juego(id_jugador_actual);
        if(jugada){
            mapa.mostrar();
            jugada->jugar(bob,mapa,turno,jugadores,id_jugador_actual);
        }
        //if(jugadores[id_jugador_actual].gano()) chequea si cumplio poner el obelisco o los 2 auxiliares;
        //    ganador;
        if(turno == CANT_JUGADORES){
            lluvia_recursos();
            turno = 0;
        }
        menu.volver();
        delete jugada;
    } while(jugada && !ganador);

    if(ganador)
        celebrar();
}

void Juego::lluvia_recursos()
{
    cout << "lluviaaaaaaaaaaa" << endl;
}

void Juego::celebrar()
{
    cout << "felicidades jugador  " << id_jugador_actual << ", ganaste :)" << endl; 
}

