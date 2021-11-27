#include "parser.hpp"

//LECTURA

void Parser::cargar_inventario(Recurso &recurso, Jugador &jugador1, Jugador &jugador2)
{
    fstream archivo_materiales(PATH_MATERIALES);

    if (!existe_archivo(PATH_MATERIALES))
        crear_archivo_vacio(PATH_MATERIALES, archivo_materiales);

    string nombre, cantidad;
    while (archivo_materiales >> nombre)
    {
        archivo_materiales >> cantidad;
        jugador1.agregar_material_al_inventario(nombre, stoi(cantidad), recurso);

        archivo_materiales >> cantidad;
        jugador2.agregar_material_al_inventario(nombre, stoi(cantidad), recurso);
    }
}

void Parser::cargar_edificios(Constructor &bob)
{
    fstream archivo_edificios(PATH_EDIFICIOS);

    if (!existe_archivo(PATH_EDIFICIOS))
        crear_archivo_vacio(PATH_EDIFICIOS, archivo_edificios);

    string nombre, piedra, madera, metal, permitidos, aux;
    while (archivo_edificios >> nombre)
    {
        if (nombre == "planta")
            archivo_edificios >> aux;
        archivo_edificios >> piedra;
        archivo_edificios >> madera;
        archivo_edificios >> metal;
        archivo_edificios >> permitidos;

        bob.agregar_edificio(nombre, stoi(piedra), stoi(madera), stoi(metal), stoi(permitidos));
    }
}

void Parser::cargar_ubicaciones(Juego &juego)
{
    fstream archivo_ubicaciones(PATH_UBICACIONES);

    if (!existe_archivo(PATH_UBICACIONES))
        crear_archivo_vacio(PATH_UBICACIONES, archivo_ubicaciones);

    //Ubicacion ubicacion;

    string primer_str, aux_coordenadas;
    Coordenada coordenadas;
    bool estado_jugador_1, estado_jugador_2 = false;
    bool flag = true;

    // TODO: validar que las coordenadas esten dentro del mapa
    // TODO: Primero cargar mapa.txt (acordarse que cambia) y despues cuando llamo a 
    // esta funcion instanciar los materiales en transitables y los eficios en construibles.
    while(archivo_ubicaciones >> primer_str){
        flag = false;
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

    juego.setear_estado_partida(flag);

    //TODO: Despues sacarlo, es una prueba.

    //cout << "ID Jugador 1: " << juego.obtener_jugador_1().obtener_id() << endl;
    //cout << "Coordenada X Jugador 1: " << juego.obtener_jugador_1().obtener_posicion_jugador().coord_x << endl;
    //cout << "Coordenada Y Jugador 1: " << juego.obtener_jugador_1().obtener_posicion_jugador().coord_y << endl;
    //juego.obtener_jugador_1().mostrar_lista_de_edificios();
    //cout << "ID Jugador 2: " << juego.obtener_jugador_2().obtener_id() << endl;
    //cout << "Coordenada X Jugador 2: " << juego.obtener_jugador_2().obtener_posicion_jugador().coord_x << endl;
    //cout << "Coordenada X Jugador 2: " << juego.obtener_jugador_2().obtener_posicion_jugador().coord_y << endl;
    //juego.obtener_jugador_2().mostrar_lista_de_edificios();

}

void Parser::cargar_mapa(Juego &juego)
{
    fstream archivo_mapa(PATH_MAPA);

    if (!existe_archivo(PATH_MAPA))
        crear_archivo_vacio(PATH_MAPA, archivo_mapa);

    string casillero; 
    int filas, columnas;
    Coordenada coordenada;

    archivo_mapa >> filas;
    archivo_mapa >> columnas;

    juego.crear_mapa(filas, columnas);
    for (coordenada.coord_x = 0; coordenada.coord_x < filas; coordenada.coord_x++)
    {
        for (coordenada.coord_y = 0; coordenada.coord_y < columnas; coordenada.coord_y++)
        {
            archivo_mapa >> casillero;
            juego.agregar_casillero(coordenada, casillero);
        }
    }

    cargar_ubicaciones(juego);
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