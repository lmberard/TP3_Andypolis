#include "parser.hpp"

//LECTURA-----------------------------------------------------------------------------------------------

bool Parser::existe_archivo_edificios()
{
    fstream archivo(PATH_EDIFICIOS);
    return archivo.is_open();
}

bool Parser::existe_archivo_materiales()
{
    fstream archivo(PATH_MATERIALES);
    return archivo.is_open();
}

void Parser::crear_archivo_vacio(const string &PATH, fstream &archivo)
{
    cout << "No se encontro un archivo con nombre \"" << PATH << "\", se va a crear el archivo" << endl;
    archivo.open(PATH, ios::out);
    archivo.close();
    archivo.open(PATH, ios::in);
}

// CARGAR INFORMACION DE LOS ARCHIVOS TXT ----------------------------

void Parser::cargar_inventario(Recurso &recurso, Juego &juego)
{
    fstream archivo_materiales(PATH_MATERIALES);

    if (!existe_archivo(PATH_MATERIALES))
        crear_archivo_vacio(PATH_MATERIALES, archivo_materiales);

    string nombre, cantidad;
    while (archivo_materiales >> nombre){
        archivo_materiales >> cantidad;
        juego.obtener_jugador_1().agregar_material_al_inventario(nombre, stoi(cantidad), recurso);

        archivo_materiales >> cantidad;
        juego.obtener_jugador_2().agregar_material_al_inventario(nombre, stoi(cantidad), recurso);
    }

    juego.obtener_jugador_1().mostrar_inventario(); //TODO: SACAR (PRUEBA)
    juego.obtener_jugador_2().mostrar_inventario(); //TODO: SACAR (PRUEBA)
}

void Parser::cargar_edificios(Constructor &bob)
{
    fstream archivo_edificios(PATH_EDIFICIOS);

    if (!existe_archivo(PATH_EDIFICIOS))
        crear_archivo_vacio(PATH_EDIFICIOS, archivo_edificios);

    string nombre, piedra, madera, metal, permitidos, aux;
    while (archivo_edificios >> nombre){
        archivo_edificios >> piedra;
        if(es_palabra(piedra)){
            nombre = nombre + " " + piedra;
            archivo_edificios >> piedra;
        }
        archivo_edificios >> madera;
        archivo_edificios >> metal;
        archivo_edificios >> permitidos;

        bob.agregar_edificio(nombre, stoi(piedra), stoi(madera), stoi(metal), stoi(permitidos));
    }
}

//para cargar las ubicaciones.txt

void Parser::cargar_ubicaciones(Juego &juego)
{
    fstream archivo_ubicaciones(PATH_UBICACIONES);

    if (!existe_archivo_ubicaciones())
        crear_archivo_vacio(PATH_UBICACIONES, archivo_ubicaciones);
    
    string aux;
    bool partida_guardada = true;
    int cant_jugadores = 2;

    if(archivo_ubicaciones >> aux){

        if(es_palabra(aux))
            cargar_materiales(archivo_ubicaciones, recurso, mapa, aux);
        for(int i = 0; i < cant_jugadores; i++){
            cargar_posicion(archivo_ubicaciones, jugador[i], aux);
            if(es_palabra(aux))
                cargar_edificios(archivo_ubicaciones,jugador[i],mapa,bob, aux);
        }
    }
    else
        partida_guardada = false;

    return partida_guardada;
}

//GUARDADO---------------------------------------------------------------------------------------------------

bool Parser::guardar(Constructor & bob)
{
    ofstream archivo_edificios(PATH_EDIFICIOS);
  
    if (archivo_edificios.is_open())
    {   
        Edificio *edificio;
        for (int i = 1; i < bob.cant_edificios() + 1; i++){
            edificio = bob.mostrar_edificio(i);
            archivo_edificios << edificio->obtener_nombre() << ' ' 
            <<  edificio->obtener_piedra() << ' '
            <<  edificio->obtener_madera() << ' '
            <<  edificio->obtener_metal() << ' '
            <<  edificio->obtener_cant_max() << '\n';
        }

    //Ubicacion ubicacion;

    string primer_str, aux_coordenadas;
    Coordenada coordenadas;
    bool estado_jugador_1, estado_jugador_2 = false;

    // TODO: validar que las coordenadas esten dentro del mapa
    // TODO: Primero cargar mapa.txt (acordarse que cambia) y despues cuando llamo a 
    // esta funcion instanciar los materiales en transitables y los eficios en construibles.
    
    while(archivo_ubicaciones >> primer_str){

        archivo_ubicaciones >> aux_coordenadas;

            // funcion void guardar_coordenadas(string &primer_str, Coordenada &coordenadas) para que no quede tan largo

        if (aux_coordenadas[0] == '(') {
            coordenadas.coord_x = aux_coordenadas[1] - '0';
            coordenadas.coord_y = aux_coordenadas[3] - '0';
        } else {
            primer_str = primer_str + " " + aux_coordenadas;
            archivo_ubicaciones >> aux_coordenadas;
            coordenadas.coord_x = aux_coordenadas[1] - '0';
            coordenadas.coord_y = aux_coordenadas[3] - '0';
        }

        if(primer_str == "1"){

            estado_jugador_1 = true;
            juego.obtener_jugador_1().setear_id(stoi(primer_str));
            juego.obtener_jugador_1().setear_posicion(coordenadas);

        } else if(primer_str == "2"){

            estado_jugador_1 = false;
            estado_jugador_2 = true;
            juego.obtener_jugador_2().setear_id(stoi(primer_str));
            juego.obtener_jugador_2().setear_posicion(coordenadas);

        } else if(estado_jugador_1 == true){
            
            juego.obtener_jugador_1().agregar_ubicacion_lista_edificios(primer_str, coordenadas);

        } else if(estado_jugador_2 == true){

            juego.obtener_jugador_2().agregar_ubicacion_lista_edificios(primer_str, coordenadas);

        } else{

            //juego.agregar_material_coordenada(primer_str, coordenadas);

        }

    }

    //TODO: Despues sacarlo, es una prueba.

    //cout << "ID Jugador 1: " << juego.obtener_jugador_1().obtener_id() << endl;
    //cout << "Coordenada X Jugador 1: " << juego.obtener_jugador_1().obtener_posicion_jugador().coord_x << endl;
    //cout << "Coordenada Y Jugador 1: " << juego.obtener_jugador_1().obtener_posicion_jugador().coord_y << endl;
    juego.obtener_jugador_1().mostrar_lista_de_edificios();
    //cout << "ID Jugador 2: " << juego.obtener_jugador_2().obtener_id() << endl;
    //cout << "Coordenada X Jugador 2: " << juego.obtener_jugador_2().obtener_posicion_jugador().coord_x << endl;
    //cout << "Coordenada X Jugador 2: " << juego.obtener_jugador_2().obtener_posicion_jugador().coord_y << endl;
    juego.obtener_jugador_2().mostrar_lista_de_edificios();

}

//para cargar mapa.txt

void Parser::cargar_mapa(Juego &juego)
{
    fstream archivo(PATH);
    return archivo.is_open();
}

void Parser::crear_archivo_vacio(const string &PATH, fstream &archivo)
{
    cout << "No se encontro un archivo con nombre \"" << PATH << "\", se va a crear el archivo" << endl;
    archivo.open(PATH, ios::out);
    archivo.close();
    archivo.open(PATH, ios::in);
}

<<<<<<< HEAD
    string casillero; 
    int filas, columnas;
    Coordenada coordenadas;

    archivo_mapa >> filas;
    archivo_mapa >> columnas;

    juego.crear_mapa(filas, columnas);
    for (coordenadas.coord_x = 0; coordenadas.coord_x < filas; coordenadas.coord_x++)
    {
        for (coordenadas.coord_y = 0; coordenadas.coord_y < columnas; coordenadas.coord_y++)
        {
            archivo_mapa >> casillero;
            juego.agregar_casillero(coordenadas, casillero);
        }
    }

    juego.mostrar_mapa(); // TODO: Despues sacarlo, es una prueba.
}

/*

// GUARDAR INFORMACION EN LOS ARCHIVOS TXT -----------------------------
void Parser::guardar_archivos(Lista<Ubicacion> edificios, Inventario &inventario)
{
    guardar_ubicaciones(edificios);
    guardar_inventario(inventario);
    msjeOK("Se guardaron los cambios en los archivos" + PATH_UBICACIONES + "y" + PATH_MATERIALES);
    msjeInstruccion("Hasta pronto!!");
}

bool Parser::guardar_ubicaciones(Lista<Ubicacion> edificios)
{
    ofstream ubicaciones_out;
    ubicaciones_out.open(PATH_UBICACIONES);

    if (ubicaciones_out.is_open())
    {
        int i = 0;
        for (i = 1; i < edificios.mostrar_cantidad(); i++)
        {
            ubicaciones_out << edificios[i].nombre << " "
                            << "(" << edificios[i].coord_x << ", "
                            << edificios[i].coord_y << ")" << endl;
        }
        ubicaciones_out << edificios[i].nombre << " "
                        << "(" << edificios[i].coord_x << ", "
                        << edificios[i].coord_y << ")";

        return true;
    }
    else
        return false;
}

bool Parser::guardar_inventario(Inventario &inventario)
{
    ofstream archivo_materiales(PATH_MATERIALES);
    if (archivo_materiales.is_open())
    {
        for (int i = 1; i < inventario.obtener_cantidad() + 1; i++)
        {
            archivo_materiales << inventario.obtener_nombre_material(i) << ' ' << inventario.obtener_cant_material(i) << endl;
=======
Coordenada Parser::obtener_coordenada(fstream &archivo_ubicaciones, string & aux_coordenada)
{
    Coordenada coordenada;
    string aux_coordenada2;
 
    coordenada.coord_x = aux_coordenada[1] - '0';
    archivo_ubicaciones >> aux_coordenada2;
    coordenada.coord_y = aux_coordenada2[0] - '0';
      
    return coordenada;
}

void Parser::cargar_materiales(fstream & archivo_ubicaciones, Recurso & recurso, Mapa & mapa, string & aux)
{   
    while(es_palabra(aux)){
        string material = aux;
        archivo_ubicaciones >> aux;
        Coordenada coordenada = obtener_coordenada(archivo_ubicaciones, aux);
        mapa.agregar_material(coordenada,recurso.dar_material(material));
        archivo_ubicaciones >> aux;
    }
}

void Parser::cargar_edificios(fstream & archivo_ubicaciones, Jugador & jugador, Mapa & mapa, Constructor & bob, string & aux)
{   
    while(es_palabra(aux)){
        string edificio = aux;
        archivo_ubicaciones >> aux;
        if(es_palabra(aux)){                      
            edificio = edificio + " " + aux;
            archivo_ubicaciones >> aux;
        }
        Coordenada coordenada = obtener_coordenada(archivo_ubicaciones, aux);
        mapa.agregar_edificio(coordenada, bob.construye(edificio));
        jugador.agregar_ubicacion_lista_edificios(edificio, coordenada);
        if(!(archivo_ubicaciones >> aux))
            aux.clear();  
    }
}

void Parser::cargar_posicion(fstream & archivo_ubicaciones, Jugador & jugador, string & aux)
{   
    archivo_ubicaciones >> aux;
    jugador.setear_posicion(obtener_coordenada(archivo_ubicaciones, aux));
    archivo_ubicaciones >> aux;
}

bool Parser::es_palabra(string & aux)
{
        bool status = true;

    if (aux.empty())
        status = false;

    for (unsigned int i = 0; i < aux.length(); i++){
        if (isdigit(aux[i]))
            status = false;
    }

    return status;
}

void Parser::guardar_ubicaciones(Lista<Ubicaciones> & lista, ofstream & archivo_ubicaciones)
{
    Coordenada coordenada;
    
    for (int i = 1; i < lista.mostrar_cantidad() + 1; i++){   
        for(int j = 1; j < obtener_cantidad(lista[i]) + 1; j++){
            archivo_ubicaciones << lista[i].nombre << ' ';
            coordenada = lista[i].coordenadas[j];
            guardar_coordenadas(coordenada, archivo_ubicaciones);
>>>>>>> marian
        }
        return true;
    }
<<<<<<< HEAD
    else
        return false;
}

*/
=======
}

void Parser::guardar_ubicacion_jugador(Jugador & jugador, int i, ofstream & archivo_ubicaciones)
{
    Coordenada coordenada;
    
    archivo_ubicaciones << i+1 << ' ';
    coordenada = jugador.obtener_posicion_jugador();
    guardar_coordenadas(coordenada, archivo_ubicaciones);
}

void Parser::guardar_coordenadas(Coordenada & coordenada, ofstream & archivo_ubicaciones)
{
    archivo_ubicaciones << "(" << coordenada.coord_x <<", ";
    archivo_ubicaciones << coordenada.coord_y << ")" << '\n';
}
>>>>>>> marian
