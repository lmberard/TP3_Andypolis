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
        partida_nueva = false;
}

Juego::~Juego()
{   
    //guarda los valores seteados en edificios.txt
    archivo.guardar(bob);

    //guarda el inventario de los jugadores en materiales.txt
    archivo.guardar_inventario(jugadores);

    //guarda la partida 
    if(!partida_nueva)
        archivo.guardar_partida(mapa,jugadores);

    for(int i = 0; i < 2; i++)
        mapa.liberar_edificios(jugadores[i].lista_edificios());
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

void Juego::asignar_objetivos()
{
    int numero;
    bool flag;

    for(int i = 0; i < CANT_JUGADORES ; i++){
        jugadores[i].asignar_objetivos_jugador(new ConstruirObelisco()); //Objetivo principal
        int numeros_generados[CANT_OBJETIVOS_SECUNDARIOS_JUGADOR] = {}; //inicializa en 0;

        for(int j = 0; j < CANT_OBJETIVOS_SECUNDARIOS_JUGADOR; j++){
    
            do{
                flag = false;
                numero = rand()%(CANT_OBJETIVOS_SECUNDARIOS_JUEGO) + 1;
                for (int k = 0; k < CANT_OBJETIVOS_SECUNDARIOS_JUGADOR; k++){
                    if(numeros_generados[k] == numero)
                        flag = true;
                }
            } while(flag == true);                 
            numeros_generados[j] = numero;

            asignar_objetivos_secundarios(numero, i);
        }
    }
}

void Juego::asignar_objetivos_secundarios(int numero, int i)
{
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

void Juego::comenzar_partida()
{   
    Jugada * jugada;
    int turno = 0;
    bool ganador = false;
    id_jugador_actual = rand()%(2) + 1;
    
    asignar_objetivos();
    lluvia_recursos();
    
    do{  
        mapa.mostrar();
        menu.mostrar_menu_juego(id_jugador_actual);
        jugada = menu.menu_juego(id_jugador_actual);
        if(jugada){
            mapa.mostrar();
            jugada->jugar(bob,mapa,turno,jugadores,id_jugador_actual);
        }
        if(jugadores[id_jugador_actual-1].gano())
            ganador = true;
        if(turno == CANT_JUGADORES){
            lluvia_recursos();
            turno = 0;
        }
        menu.volver();
        delete jugada;
    }while(jugada && !ganador);

    if(ganador)
        celebrar();
}

void Juego::colocar_material_random(int cantidad,string material, const int cant_bloque)
{
    int numero;
    while (cantidad)
    {
        if(mapa.cant_coord_transitables()){
            numero = rand() % (1 + mapa.cant_coord_transitables() - 1) + 1;
            mapa.agregar_material(mapa.obtener_coord_transitables(numero), recurso.dar_material(material,cant_bloque));
        }
        else
            cantidad = 1;
        cantidad--;
    }
}

void Juego::lluvia_recursos()
{
    if(mapa.cant_coord_transitables())
    {
        int cantidad = rand() % (1 + LLUVIA_METAL_MAX - LLUVIA_METAL_MIN) + LLUVIA_METAL_MIN;
        colocar_material_random(cantidad, "metal",CANT_METAL_BLOQUE);
    
        cantidad = rand() % (1 + LLUVIA_PIEDRA_MAX - LLUVIA_PIEDRA_MIN) + LLUVIA_PIEDRA_MIN;
        colocar_material_random(cantidad, "piedra", CANT_PIEDRA_BLOQUE);

        cantidad = rand() % (1 + LLUVIA_MADERA_MAX - LLUVIA_MADERA_MIN) + LLUVIA_MADERA_MIN;
        colocar_material_random(cantidad, "madera", CANT_MADERA_BLOQUE);   

        cantidad = rand() % (1 + LLUVIA_ANDYCOINS_MAX - LLUVIA_ANDYCOINS_MIN) + LLUVIA_ANDYCOINS_MIN;
        colocar_material_random(cantidad, "andycoins", CANT_ANDYCOINS_BLOQUE);   
    }
    else
        msjeInstruccion("Todos los casilleros se encuentran ocupados.");   
}

void Juego::celebrar()
{
    cout << TXT_LIGHT_GREEN_46 << "Felicidades jugador  " << id_jugador_actual << ", ganaste :)" << END_COLOR << endl;
}
