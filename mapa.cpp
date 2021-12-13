#include "mapa.hpp"

//---------------CONSTRUCTORES DESTRUCTORES-----------------------
Mapa::Mapa()
{
}

Mapa::~Mapa()
{
    liberar_materiales();

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

Lista<Ubicaciones> &Mapa::lista_materiales()
{
    return materiales;
}

int Mapa::obtener_peso_del_mapa(int jugador_id, Coordenada coordenadas)
{
    return mapa[coordenadas.coord_x][coordenadas.coord_y]->obtener_peso(jugador_id);
}

//------------------------SETTERS---------------------------------
void Mapa::agregar_coordenada_transitable(Coordenada coord)
{
    coordenadas_transitables.alta(coord);
}

void Mapa::agregar_material(Coordenada coord, Material *material)
{
    bool se_encontro = false;
    for (int i = 1; i < materiales.mostrar_cantidad() + 1; i++)
    {
        if (materiales[i].nombre == material->obtener_nombre())
        {
            agregar_coordenada(materiales[i], coord);
            se_encontro = true;
        }
    }
    if (!se_encontro)
    {
        Ubicaciones nuevo_material;
        setear_nombre(nuevo_material, material->obtener_nombre());
        agregar_coordenada(nuevo_material, coord);
        materiales.alta(nuevo_material);
    }

    mapa[coord.coord_x][coord.coord_y]->agregar(material);
    quitar_coord_transitable(coord);
}

void Mapa::agregar_edificio(Coordenada coord, Edificio *edificio)
{
    mapa[coord.coord_x][coord.coord_y]->agregar(edificio);
}

bool Mapa::agregar_jugador(Coordenada coord, Jugador *jugador, int i)
{

    bool flag = mapa[coord.coord_x][coord.coord_y]->agregar(jugador);
    if (flag)
    {
        if (i == 1)
            jugador1 = coord;
        if (i == 2)
            jugador2 = coord;
        quitar_coord_transitable(coord);
    }
    return flag;
}

bool Mapa::mover_jugador(Coordenada coord, Jugador *jugador, int i)
{
    bool flag;

    flag = (mapa[coord.coord_x][coord.coord_y]->agregar(jugador));
    if (flag)
    {
        if (i == 1)
            jugador1 = coord;
        if (i == 2)
            jugador2 = coord;
        quitar_coord_transitable(coord);
    }
    return flag;
}

void Mapa::borrar_jugador_de_coordenada(Coordenada coord)
{
    mapa[coord.coord_x][coord.coord_y]->borrar_jugador();
    agregar_coordenada_transitable(coord);
}

void Mapa::actualizar_tam_mapa(int _filas, int _columnas)
{
    filas = _filas;
    columnas = _columnas;
}

void Mapa::agregar_casillero(Coordenada coord, Casillero *casillero)
{
    if (casillero->estransitable())
        coordenadas_transitables.alta(coord);

    mapa[coord.coord_x][coord.coord_y] = casillero;
}

Edificio *Mapa::obtener_edificio(Coordenada coord)
{
    return mapa[coord.coord_x][coord.coord_y]->info_edificio();
}

void Mapa::agregar_ubicacion_material_lista(string nombre, Coordenada coord)
{
    // TODO: Resolver el problema de la 2ble lista
} // YO

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

void Mapa::recolectar_materiales_del_mapa(Coordenada &coordenadas)
{
    // mapa[coordenadas.coord_x][coordenadas.coord_y]->recolectar_material()
}

void Mapa::recorrer(Coordenada coord)
{
    mapa[coord.coord_x][coord.coord_y]->recorrer();
}

void Mapa::desrecorrer(Coordenada coord)
{
    mapa[coord.coord_x][coord.coord_y]->desrecorrer();
}

//--------------------FUNCIONES UTILES-----------------------------
bool Mapa::coordenadas_validas(Coordenada coord)
{
    // to do: filas y columnas son accesibles. Ta de más
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

void Mapa::liberar_materiales()
{
    Coordenada coordenada;
    for (int i = 1; i < materiales.mostrar_cantidad() + 1; i++)
    {
        for (int j = 1; j < obtener_cantidad(materiales[i]) + 1; j++)
        {
            coordenada = materiales[i].coordenadas[j];
            mapa[coordenada.coord_x][coordenada.coord_y]->quitar_elemento();
        }
    }
}

void Mapa::liberar_edificios(Lista<Ubicaciones> &lista)
{
    Coordenada coordenada;
    for (int i = 1; i < lista.mostrar_cantidad() + 1; i++)
    {
        for (int j = 1; j < obtener_cantidad(lista[i]) + 1; j++)
        {
            coordenada = lista[i].coordenadas[j];
            mapa[coordenada.coord_x][coordenada.coord_y]->quitar_elemento();
        }
    }
}

int Mapa::cant_coord_transitables()
{
    return coordenadas_transitables.mostrar_cantidad();
}

Coordenada Mapa::obtener_posicion_jugador(int i)
{
    if (i == 1)
        return jugador1;
    else
        return jugador2;
}

Coordenada Mapa::obtener_coord_transitables(int i)
{
    return coordenadas_transitables[i];
}

void Mapa::quitar_coord_transitable(Coordenada coord)
{
    for (int i = 1; i < coordenadas_transitables.mostrar_cantidad() + 1; i++)
    {
        if ((coordenadas_transitables[i].coord_x == coord.coord_x) && (coordenadas_transitables[i].coord_y == coord.coord_y))
        {
            coordenadas_transitables.baja(i);
        }
    }
}
