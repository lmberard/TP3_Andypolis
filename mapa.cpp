#include "mapa.hpp"

//---------------CONSTRUCTORES DESTRUCTORES-----------------------
Mapa::Mapa()
{
}

Mapa::~Mapa()
{
    for (int i = 0; i < filas; i++)
        for (int j = 0; j < columnas; j++)
            delete mapa[i][j];

    for (int i = 0; i < filas; i++)
        delete[] mapa[i];

    delete[] mapa;
}

//------------------------GETTERS---------------------------------
int Mapa::obtener_filas()
{
    return filas;
}

int Mapa::obtener_columnas()
{
    return columnas;
}

//------------------------SETTERS---------------------------------
void Mapa::agregar_coordenada_transitable(Coordenada coord)
{
    coordenadas_transitables.alta(coord);
}

void Mapa::actualizar_tam_mapa(int _filas, int _columnas)
{
    filas = _filas;
    columnas = _columnas;
}

void Mapa::agregar_casillero(Coordenada coord, string casillero, Terreno &terreno)
{
    mapa[coord.coord_x][coord.coord_y] = terreno.agregar(casillero);
    //if (casillero_es_transitable(casillero))
    //    agregar_coordenada_transitable(coord);
}

Edificio *Mapa::obtener_edificio(Coordenada coord)
{
    return mapa[coord.coord_x][coord.coord_y]->mostrar_edificio();
}

void Mapa::agregar_ubicacion_material_lista(string nombre, Coordenada coord)
{
    //TODO: Resolver el problema de la 2ble lista
} //YO

bool Mapa::agregar_contenido(Coordenada coord, Edificio *edificio)
{
    return mapa[coord.coord_x][coord.coord_y]->agregar(edificio);
}

bool Mapa::agregar_contenido(Coordenada coord, Material *material)
{
    return mapa[coord.coord_x][coord.coord_y]->agregar(material);
}

//-----------------------MEMORIA----------------------------------
void Mapa::crear_memoria_mapa(int _filas, int _columnas)
{
    filas = _filas;
    columnas = _columnas;
    crear_memoria_filas_mapa(_filas);
    for (int i = 0; i < filas; i++)
        crear_memoria_columna_mapa(i, _columnas);
}

void Mapa::crear_memoria_filas_mapa(int _filas)
{
    mapa = new Casillero **[filas];
}

void Mapa::crear_memoria_columna_mapa(int posicion_fila, int _columnas)
{
    mapa[posicion_fila] = new Casillero *[_columnas];
}

//----------------------PARA EL JUEGO-----------------------------
void Mapa::mostrar()
{
    msjeInstruccion("MAPA DE ANDYPOLIS:");
    for (int i = 0; i < filas; i++)
    {
        for (int j = 0; j < columnas; j++)
        {
            mapa[i][j]->display();
        }
        cout << endl;
    }
}

void Mapa::consultar_coordenada(Coordenada coord)
{
    mapa[coord.coord_x][coord.coord_y]->mostrar();
}

void Mapa::demoler_contenido(Coordenada coord)
{
    mapa[coord.coord_x][coord.coord_y]->demoler();
}

//--------------------FUNCIONES UTILES-----------------------------
bool Mapa::coordenadas_validas(Coordenada coord)
{
    int filas = obtener_filas();
    int columnas = obtener_columnas();
    if (!(coord.coord_x >= 0 && coord.coord_x <= filas && coord.coord_y >= 0 && coord.coord_y <= columnas))
    {
        msjeError("Las coordenadas estan fueras del mapa");
        msjeInstruccion("Actualmente el mapa es una matriz de " + to_string(filas) + "x" + to_string(columnas));
        return false;
    }
    else
        return true;
}

bool Mapa::coordenada_es_transitable(Coordenada coord)
{
    return mapa[coord.coord_x][coord.coord_y]->estransitable();
}

bool Mapa::casillero_es_transitable(string tipo_casillero)
{
    return (tipo_casillero == "C" || tipo_casillero == "B" || tipo_casillero == "M");
}
