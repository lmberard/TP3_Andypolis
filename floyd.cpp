#include "floyd.hpp"

int **Floyd::crearMatrizCaminos()
{
    int **caminos = new int *[cantidadVertices];
    for (int i = 0; i < cantidadVertices; i++)
    {
        caminos[i] = new int[cantidadVertices];
    }

    for (int i = 0; i < cantidadVertices; i++)
    {
        for (int j = 0; j < cantidadVertices; j++)
        {
            caminos[i][j] = j;
        }
    }
    return caminos;
}

int **Floyd::crearMatrizCostos(int **matrizAdyacencia)
{
    int **costos = new int *[cantidadVertices];
    for (int i = 0; i < cantidadVertices; i++)
    {
        costos[i] = new int[cantidadVertices];
    }
    for (int i = 0; i < cantidadVertices; i++)
    {
        for (int j = 0; j < cantidadVertices; j++)
        {
            costos[i][j] = matrizAdyacencia[i][j];
        }
    }
    return costos;
}

// util para debuggear
void Floyd::mostrarMatrices()
{
    cout << "Matriz de costos: Matriz de caminos:" << endl;
    string filaCostos;
    string filaCaminos;
    for (int i = 0; i < cantidadVertices; i++)
    {
        for (int j = 0; j < cantidadVertices * 2; j++)
        {

            if (j == cantidadVertices * 2 - 1)
            {
                filaCostos += "         ||              ";
                filaCaminos += "\n";
            }
            else if (j % 2 == 0)
            {
                if (matrizCostos[i][j / 2] == INFINITO)
                {
                    filaCostos += "inf";
                }
                else
                {
                    filaCostos += to_string(matrizCostos[i][j / 2]);
                }
                if (matrizCaminos[i][j / 2] == POSICION_NO_ENCONTRADA)
                {
                    filaCaminos += "-";
                }
                else
                {
                    filaCaminos += to_string(matrizCaminos[i][j / 2]);
                }
            }
            else
            {
                filaCaminos += "|";
                filaCostos += "|";
            }
        }
        cout << filaCostos << filaCaminos;
        filaCostos = "";
        filaCaminos = "";
    }
    cout << endl;
}

void Floyd::calcularMatrices()
{
    cantidadVertices = vertices->obtenerCantidadDeElementos();
    matrizCostos = crearMatrizCostos(matrizAdyacencia);
    matrizCaminos = crearMatrizCaminos();

    // TODO: Escribir el código necesario
    /*
    en cada iteracion lo que hace es chequear si para el Vertice A a B, si hay un vertice
    en el medio que me lo haga mas facil, es decir, buscar el camino optimo.
    esto lo hace muchas veces (cant de vertices que haya en la matriz)
    es recursivo
    */
}

// revisar
void Floyd::liberarMatrices()
{
    if (matrizCostos != NULL && matrizCaminos != NULL)
    {
        for (int i = 0; i < cantidadVertices; i++)
        {
            delete[] matrizCostos[i];
            delete[] matrizCaminos[i];
        }
        delete[] matrizCostos;
        delete[] matrizCaminos;

        matrizCostos = NULL;
        matrizCaminos = NULL;
    }
}

// falta
void Floyd::calcularMatrices()
{
}

// public
// falta
Floyd::Floyd(Lista<Vertice> *vertices, int **matrizAdyacencia)
{
}

void Floyd::caminoMinimo(int origen, int destino)
{
    if (matrizCaminos[origen][destino] == POSICION_NO_ENCONTRADA)
    {
        cout << "No hay un camino que conecte " << vertices->obtenerNombre(origen + 1) << "con " << vertices->obtenerNombre(destino + 1);
    }
    else
    {
        cout << "El camino minimo que une " << vertices->obtenerNombre(origen + 1) << "con " << vertices->obtenerNombre(destino + 1);
        cout << "tiene un costo de: " << matrizCostos[origen][destino] << " y es el siguiente: ";
        cout << vertices->obtenerNombre(origen + 1);
        do
        {
            origen = matrizCaminos[origen][destino];
            cout << " -> " << vertices->obtenerNombre(origen + 1);
        } while (origen != destino);
    }
}

Floyd::~Floyd()
{
}
