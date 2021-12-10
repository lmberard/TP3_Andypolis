#include "parser.hpp"

//LECTURA-----------------------------------------------------------------------------------------------

void Parser::cargar(Recurso &recurso, Jugador * jugador)
{
    fstream archivo_materiales(PATH_MATERIALES);

    if (!existe_archivo(PATH_MATERIALES))
        crear_archivo_vacio(PATH_MATERIALES, archivo_materiales);

    string nombre, cantidad;
    while (archivo_materiales >> nombre){
        archivo_materiales >> cantidad;
       
        jugador[0].agregar_material_al_inventario(recurso.dar_material(nombre, stoi(cantidad)));
        archivo_materiales >> cantidad;
        jugador[1].agregar_material_al_inventario(recurso.dar_material(nombre, stoi(cantidad)));
    }

}

void Parser::cargar(Constructor &bob)
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

void Parser::cargar(Superficie & superficie, Mapa & mapa)
{
    fstream archivo_mapa(PATH_MAPA);

    if (!existe_archivo(PATH_MAPA))
        crear_archivo_vacio(PATH_MAPA, archivo_mapa);

    string casillero; 
    int filas, columnas;
    Coordenada coordenada;

    archivo_mapa >> filas;
    archivo_mapa >> columnas;

    mapa.crear_memoria_mapa(filas, columnas);
    for (coordenada.coord_x = 0; coordenada.coord_x < filas; coordenada.coord_x++){
        for (coordenada.coord_y = 0; coordenada.coord_y < columnas; coordenada.coord_y++){
            archivo_mapa >> casillero;
            mapa.agregar_casillero(coordenada, superficie.agregar(casillero));
        }
    }
}

bool Parser::cargar_partida_guardada(Mapa & mapa, Jugador* jugador, Constructor & bob, Recurso & recurso)
{
    fstream archivo_ubicaciones(PATH_UBICACIONES);

    if (!existe_archivo(PATH_UBICACIONES))
        crear_archivo_vacio(PATH_UBICACIONES, archivo_ubicaciones);
    
    string aux;
    bool partida_guardada = true;
    int cant_jugadores = 2;

    if(archivo_ubicaciones >> aux){

        if(es_palabra(aux))
            cargar_materiales(archivo_ubicaciones, recurso, mapa, aux);
        for(int i = 0; i < cant_jugadores; i++){
            jugador[i].setear_jugador(i+1);
            cargar_posicion(archivo_ubicaciones, jugador[i], mapa, i, aux);
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

        return true;
    }
    else
        return false;
}

//PODRIA ESTAR MEJOR PERO FUE, FUNCIONA BIEN
bool Parser::guardar_inventario(Jugador * jugador)
{
    ofstream archivo_materiales(PATH_MATERIALES);

    if (archivo_materiales.is_open())
    {
        for (int i = 1; i < jugador[0].inv().obtener_cantidad() + 1; i++)
            archivo_materiales << jugador[0].inv().obtener_nombre_material(i) << ' ' 
            << jugador[0].inv().obtener_cant_material(i) << ' '
            << jugador[1].inv().obtener_cant_material(i) << '\n';

        return true;
    }
    else
        return false;
}

bool Parser::guardar_partida(Mapa & mapa,Jugador *jugador)
{

    ofstream archivo_ubicaciones(PATH_UBICACIONES);

    if (archivo_ubicaciones.is_open()){
       
        guardar_ubicaciones(mapa.lista_materiales(), archivo_ubicaciones);
        for(int i = 0; i < 2; i++){
            guardar_ubicacion_jugador(mapa, i, archivo_ubicaciones);
            guardar_ubicaciones(jugador[i].lista_edificios(), archivo_ubicaciones);
        }

        return true;
    }
    else
        return false;
   
}

//EXTRA-----------------------------------------------------------------------------------------------
bool Parser::existe_archivo(const string & PATH)
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

Coordenada Parser::obtener_coordenada(fstream &archivo_ubicaciones, string & aux_coordenada)
{
    Coordenada coordenada;
    //string aux_coordenada2;
 
    aux_coordenada.erase(remove(aux_coordenada.begin(), aux_coordenada.end(), '('), aux_coordenada.end());
    aux_coordenada.erase(remove(aux_coordenada.begin(), aux_coordenada.end(), ','), aux_coordenada.end());
    coordenada.coord_x = stoi(aux_coordenada);

    archivo_ubicaciones >> aux_coordenada;

    aux_coordenada.erase(remove(aux_coordenada.begin(), aux_coordenada.end(), ')'), aux_coordenada.end());
    coordenada.coord_y = stoi(aux_coordenada);
      
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

void Parser::cargar_posicion(fstream & archivo_ubicaciones, Jugador & jugador, Mapa & mapa, int i, string & aux)
{   
    archivo_ubicaciones >> aux;
    mapa.agregar_jugador(obtener_coordenada(archivo_ubicaciones,aux), &jugador, i+1);
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
        }
    }
}

void Parser::guardar_ubicacion_jugador(Mapa & mapa, int i, ofstream & archivo_ubicaciones)
{
    Coordenada coordenada;
    
    archivo_ubicaciones << i+1 << ' ';
    coordenada = mapa.obtener_posicion_jugador(i+1);
    guardar_coordenadas(coordenada, archivo_ubicaciones);
}

void Parser::guardar_coordenadas(Coordenada & coordenada, ofstream & archivo_ubicaciones)
{
    archivo_ubicaciones << "(" << coordenada.coord_x <<", ";
    archivo_ubicaciones << coordenada.coord_y << ")" << '\n';
}