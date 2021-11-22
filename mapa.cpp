#include "mapa.hpp"

Mapa::Mapa()
{
}

void Mapa::crear_memoria_mapa(int _filas, int _columnas)
{
    filas = _filas;
    columnas = _columnas;
    crear_memoria_filas_mapa(_filas);
    for (int i = 0; i < filas; i++)
        crear_memoria_columna_mapa(i, _columnas);
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

void Mapa::actualizar_tam_mapa(int _filas, int _columnas)
{
    filas = _filas;
    columnas = _columnas;
}

void Mapa::crear_memoria_filas_mapa(int _filas)
{
    mapa = new Casillero **[filas];
}

void Mapa::crear_memoria_columna_mapa(int posicion_fila, int _columnas)
{
    mapa[posicion_fila] = new Casillero *[_columnas];
}

int Mapa::obtener_filas()
{
    return filas;
}

int Mapa::obtener_columnas()
{
    return columnas;
}

void Mapa::agregar_casillero(int x, int y, string casillero, Terreno &terreno)
{
    mapa[x][y] = terreno.agregar(casillero);
}

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

void Mapa::consultar_coordenada(int x, int y)
{
    mapa[x][y]->mostrar();
}

Edificio *Mapa::obtener_edificio(int x, int y)
{
    return mapa[x][y]->mostrar_edificio();
}

bool Mapa::coordenada_es_transitable(int x, int y)
{
    return mapa[x][y]->estransitable();
}

void Mapa::demoler_contenido(int x, int y)
{
    mapa[x][y]->demoler();
}

bool Mapa::agregar_contenido(int x, int y, Edificio *edificio)
{
    return mapa[x][y]->agregar(edificio);
}

bool Mapa::agregar_contenido(int x, int y, Material *material)
{
    return mapa[x][y]->agregar(material);
}
