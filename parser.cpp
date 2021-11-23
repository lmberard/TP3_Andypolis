#include "parser.hpp"

bool Parser::existe_archivo_ubicaciones()
{
    fstream archivo(PATH_UBICACIONES);
    return archivo.is_open();
}

bool Parser::existe_archivo_mapa()
{
    fstream archivo(PATH_MAPA);
    return archivo.is_open();
}

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

// Esta OK

/*

void Parser::cargar_inventario(Recurso &recurso, Jugador jugador1, jugador jugador2)
{
    fstream archivo_materiales(PATH_MATERIALES);

    if (!existe_archivo_materiales())
        crear_archivo_vacio(PATH_MATERIALES, archivo_materiales);

    string nombre, cantidad;
    while (archivo_materiales >> nombre)
    {
        archivo_materiales >> cantidad;
        jugador1.cargar_material_lista(nombre, stoi(cantidad), recurso);
        archivo_materiales >> cantidad;
        jugador2.cargar_material_lista(nombre, stoi(cantidad), recurso);
    
    }
}

*/

void Parser::cargar_inventario(Inventario &inventario, Recurso &recurso)
{
    fstream archivo_materiales(PATH_MATERIALES);

    if (!existe_archivo_materiales())
        crear_archivo_vacio(PATH_MATERIALES, archivo_materiales);

    string nombre, cantidad;
    while (archivo_materiales >> nombre)
    {
        archivo_materiales >> cantidad;
        inventario.agregar_material(nombre, stoi(cantidad), recurso);
    }
}

//donde iría is a number

// Esta OK

/*

void Parser::cargar_edificios(Constructor &bob)
{
    fstream archivo_edificios(PATH_EDIFICIOS);

    if (!existe_archivo_edificios())
        crear_archivo_vacio(PATH_EDIFICIOS, archivo_edificios);

    string nombre, piedra, madera, metal, permitidos, aux;

    while (archivo_edificios >> nombre)
    {
            file >> aux;

            if (isANumber(aux) == true) {
                piedra = stoi(aux);
            } else {
                nombre = nombre + " " + aux;
                file >> piedra;
            }

            file >> madera;
            file >> metal;
            file >> permitidos;

            bob.agregar_edificio(nombre, stoi(piedra), stoi(madera), stoi(metal), stoi(permitidos));
    }
}

*/

void Parser::cargar_edificios(Constructor &bob)
{
    fstream archivo_edificios(PATH_EDIFICIOS);

    if (!existe_archivo_edificios())
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

//para cargar las ubicaciones.txt

void Parser::cargar_ubicaciones(Juego &juego)
{
    fstream archivo_ubicaciones(PATH_UBICACIONES);

    if (!existe_archivo_ubicaciones())
        crear_archivo_vacio(PATH_UBICACIONES, archivo_ubicaciones);

    Ubicacion ubicacion;

    string nombre, aux, coord_x, coord_y, aux2;
    while (getline(archivo_ubicaciones, nombre, ' '))
    {
        if (nombre == "planta")
        {
            getline(archivo_ubicaciones, aux, ' ');
            ubicacion.nombre = nombre + ' ' + aux;
        }
        else
        {
            ubicacion.nombre = nombre;
        }
        getline(archivo_ubicaciones, aux, '(');
        getline(archivo_ubicaciones, coord_x, ',');
        ubicacion.coord_x = stoi(coord_x);

        getline(archivo_ubicaciones, aux, ' ');
        getline(archivo_ubicaciones, coord_y, ')');
        ubicacion.coord_y = stoi(coord_y);
        getline(archivo_ubicaciones, aux);

        juego.agregar_ubicacion_edificio(ubicacion);
    }
}

//para cargar mapa.txt

void Parser::cargar_mapa(Juego &juego)
{
    fstream archivo_mapa(PATH_MAPA);

    if (!existe_archivo_mapa())
        crear_archivo_vacio(PATH_MAPA, archivo_mapa);

    string casillero, filas, columnas;

    archivo_mapa >> filas;
    archivo_mapa >> columnas;

    juego.crear_mapa(stoi(filas), stoi(columnas));
    for (int i = 0; i < stoi(filas); i++)
    {
        for (int j = 0; j < stoi(columnas); j++)
        {
            archivo_mapa >> casillero;
            juego.agregar_casillero(i, j, casillero);
        }
    }
}

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
