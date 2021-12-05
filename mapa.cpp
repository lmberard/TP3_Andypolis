#include "mapa.hpp"

//---------------CONSTRUCTORES DESTRUCTORES-----------------------
Mapa::Mapa()
{
}

Mapa::~Mapa()
{
    //borrar_todo();
    mapa[5][0]->quitar_elemento();
    mapa[5][3]->quitar_elemento();
    mapa[1][2]->quitar_elemento();
    mapa[5][1]->quitar_elemento();
    mapa[6][0]->quitar_elemento();
    mapa[4][0]->quitar_elemento();
    mapa[1][1]->quitar_elemento();
    mapa[0][0]->quitar_elemento();
    mapa[1][0]->quitar_elemento();
    mapa[0][1]->quitar_elemento();

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

int Mapa::obtener_tam_lista_ubicaciones()
{
    return materiales.mostrar_cantidad();
}

int Mapa::obtener_cant_material(int i)
{
    return obtener_cantidad(materiales[i]); 
}

Coordenada Mapa::obtener_coordenada(int i, int j)
{
    return materiales[i].coordenadas[j];
}

string Mapa::obtener_nombre_material(int i)
{
    return materiales[i].nombre;
}

Lista<Ubicaciones> & Mapa::lista_materiales()
{
    return materiales;
}

//------------------------SETTERS---------------------------------
void Mapa::agregar_coordenada_transitable(Coordenada coord)
{
    coordenadas_transitables.alta(coord);
}

void Mapa::agregar_material(Coordenada coord, Material* material)
{

    for (int i = 1; i < materiales.mostrar_cantidad() + 1; i++)
    {
        if (materiales[i].nombre == material->obtener_nombre()){
            agregar_coordenada(materiales[i], coord);
            return;
        }
    }   

    Ubicaciones nuevo_material;
    setear_nombre(nuevo_material, material->obtener_nombre());
    agregar_coordenada(nuevo_material, coord);
    materiales.alta(nuevo_material);
    mapa[coord.coord_x][coord.coord_y]->agregar(material);
}

void Mapa::agregar_edificio(Coordenada coord, Edificio* edificio)
{
    mapa[coord.coord_x][coord.coord_y]->agregar(edificio);
}

void Mapa::actualizar_tam_mapa(int _filas, int _columnas)
{
    filas = _filas;
    columnas = _columnas;
}

void Mapa::agregar_casillero(Coordenada coord, Casillero* casillero)
{
    mapa[coord.coord_x][coord.coord_y] = casillero;
}

Edificio *Mapa::obtener_edificio(Coordenada coord)
{
    return mapa[coord.coord_x][coord.coord_y]->info_edificio();
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
            mapa[i][j]->mostrar_por_pantalla();
        }
        cout << endl;
    }
}

void Mapa::consultar_coordenada(Coordenada coord)
{
    mapa[coord.coord_x][coord.coord_y]->info();
}

void Mapa::demoler_contenido(Coordenada coord)
{
    mapa[coord.coord_x][coord.coord_y]->quitar_elemento();
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

/*
void Mapa::borrar_todo()
{
    for (int i = 1; i < edificios.mostrar_cantidad() + 1; i++)
        mapa[edificios[i].coord_x][edificios[i].coord_y]->demoler();
    for (int i = 1; i < materiales.mostrar_cantidad() + 1; i++)
        mapa[materiales[i].coord_x][materiales[i].coord_y]->demoler();
}*/