#include "parser.hpp"

//LECTURA

void Parser::cargar(Recurso &recurso, Jugador * jugador)
{
    fstream archivo_materiales(PATH_MATERIALES);

    if (!existe_archivo(PATH_MATERIALES))
        crear_archivo_vacio(PATH_MATERIALES, archivo_materiales);

    string nombre, cantidad;
    while (archivo_materiales >> nombre){
        archivo_materiales >> cantidad;
        jugador[0].agregar_material_al_inventario(nombre, stoi(cantidad), recurso);

        archivo_materiales >> cantidad;
        jugador[1].agregar_material_al_inventario(nombre, stoi(cantidad), recurso);
    }
}

void Parser::cargar(Constructor &bob)
{
    fstream archivo_edificios(PATH_EDIFICIOS);

    if (!existe_archivo(PATH_EDIFICIOS))
        crear_archivo_vacio(PATH_EDIFICIOS, archivo_edificios);

    string nombre, piedra, madera, metal, permitidos, aux;
    while (archivo_edificios >> nombre){
        if (nombre == "planta")
            archivo_edificios >> aux;
        archivo_edificios >> piedra;
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
            mapa.agregar_casillero(coordenada, casillero, superficie);
        }
    }
}

bool Parser::cargar_partida_guardada(Mapa & mapa, Constructor & bob, Recurso & recurso, Jugador* jugador, int cant_jugadores)
{
    fstream archivo_ubicaciones(PATH_UBICACIONES);

    if (!existe_archivo(PATH_UBICACIONES))
        crear_archivo_vacio(PATH_UBICACIONES, archivo_ubicaciones);
    
    string aux;
    bool partida_guardada = true;
    
    if(archivo_ubicaciones >> aux){

        if(cambio_jugador(aux))
            cargar_materiales(archivo_ubicaciones, recurso, mapa, aux);
        for(int i = 0; i < cant_jugadores; i++){
            cargar_posicion(archivo_ubicaciones, jugador[i], mapa, aux);
            if(cambio_jugador(aux))
                cargar_edificios(archivo_ubicaciones,jugador[i],mapa,bob, aux);
        }
    }
    else
        partida_guardada = false;

    return partida_guardada;
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
        }
        return true;
    }
    else
        return false;
}
*/

// EXTRAS:
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

bool Parser::cambio_jugador(string & aux)
{
    bool status = false;

    if (aux.empty())
        status = false;

    for (unsigned int i = 0; i < aux.length(); i++){
        if (!isdigit(aux[i]))
            status = true;
    }

    return status;
}

Coordenada Parser::obtener_coordenada(fstream & archivo_ubicaciones)
{
    string aux_coordenada;
    Coordenada coordenada;
     archivo_ubicaciones >> aux_coordenada;

        if (aux_coordenada[0] == '('){
            coordenada.coord_x = aux_coordenada[1] - '0';
            coordenada.coord_y = aux_coordenada[3] - '0';
        }

    return coordenada;
}

void Parser::cargar_materiales(fstream & archivo_ubicaciones, Recurso & recurso, Mapa & mapa, string & aux)
{   
    while(cambio_jugador(aux)){
        string material = aux;
        Coordenada coordenada = obtener_coordenada(archivo_ubicaciones);
        mapa.agregar_material(coordenada,recurso.dar_material(material));
        archivo_ubicaciones >> aux;
    }
}

void Parser::cargar_edificios(fstream & archivo_ubicaciones, Jugador & jugador, Mapa & mapa, Constructor & bob, string & aux)
{   
    while(cambio_jugador(aux)){
        string edificio = aux;
        Coordenada coordenada = obtener_coordenada(archivo_ubicaciones);
        mapa.agregar_edificio(coordenada, bob.construye(edificio));
        jugador.agregar_ubicacion_lista_edificios(edificio, coordenada);
        if(!(archivo_ubicaciones >> aux))
            aux.clear();  
    }
}

void Parser::cargar_posicion(fstream & archivo_ubicaciones, Jugador & jugador, Mapa & mapa, string & aux)
{
    jugador.setear_posicion(obtener_coordenada(archivo_ubicaciones));
    //FALTA VER COMO QUEREMOS REPRESENTAR ESTO EN EL MAPA :U
    archivo_ubicaciones >> aux;
}