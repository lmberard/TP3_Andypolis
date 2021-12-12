#ifndef GRAFOS_LISTA_H
#define GRAFOS_LISTA_H
#include <string>
#include "nodo.hpp"
#include "coordenada.hpp"
#include <iostream>

using namespace std;

const int POSICION_NO_ENCONTRADA = -1;
const string NOMBRE_NO_ENCONTRADO = "";

template <typename Tipo>
class Lista
{
    /*ATRIBUTOS*/
private:
    int cantidadDeElementos;
    Nodo<Tipo> *primero;
    Nodo<Tipo> *ultimo;

    /*MÉTODOS*/
public:
    Lista();

    // post: devuelve la cantidad de elementos que tiene la lista
    int obtenerCantidadDeElementos();

    // post: devuelve la posicion en la que se encuentra el nombre que recibe o -1 si no lo encuentra
    int obtenerPosicion(coordenada nombre);

    // post: devuelve el  nombre que se encuentra en la posicion recibida o NOMBRE_NO_ENCONTRADO si no lo encuentra
    coordenada obtenerNombre(int posicion);

    // post: agrega un nuevo elemento a la lista
    void agregar(coordenada nuevoElemento);

    ~Lista();
};

template <typename Tipo>
Lista<Tipo>::Lista()
{
    cantidadDeElementos = 0;
    ultimo = nullptr;
    primero = nullptr;
}

template <typename Tipo>
int Lista<Tipo>::obtenerCantidadDeElementos()
{
    return cantidadDeElementos;
}

template <typename Tipo>
int Lista<Tipo>::obtenerPosicion(coordenada nombre)
{
    bool elementoEncontrado = false;
    int i = 0;
    Nodo<Tipo> *auxiliar = primero;

    while (!elementoEncontrado && i < cantidadDeElementos)
    {
        if ((auxiliar->obtenerNombre().coord_x == nombre.coord_x) && (auxiliar->obtenerNombre().coord_y == nombre.coord_y) )
        {
            elementoEncontrado = true;
        }
        i++;
        auxiliar = auxiliar->obtenerSiguiente();
        
    }

    if (!elementoEncontrado)
    {
        return POSICION_NO_ENCONTRADA;
    }
    return i - 1;
}

template <typename Tipo>
void Lista<Tipo>::agregar(coordenada nuevoElemento)
{
    Nodo<Tipo> *nuevoNodo = new Nodo<Tipo>(nuevoElemento);
    if (primero == nullptr)
    {
        primero = nuevoNodo;
        ultimo = primero;
    }
    else
    {
        ultimo->asignarSiguiente(nuevoNodo);
        ultimo = nuevoNodo;
    }
    cantidadDeElementos++;
}

template <typename Tipo>
Lista<Tipo>::~Lista()
{
    Nodo<Tipo> *siguiente;
    while (primero != nullptr)
    {
        siguiente = primero->obtenerSiguiente();
        delete primero;
        primero = siguiente;
    }
}

template <typename Tipo>
coordenada Lista<Tipo>::obtenerNombre(int posicion)
{
    int i = 0;
    Nodo<Tipo> *auxiliar = primero;

    if (posicion > cantidadDeElementos)
    {
        //return NOMBRE_NO_ENCONTRADO;
    }

    while (i != posicion - 1)
    {
        auxiliar = auxiliar->obtenerSiguiente();
        i++;
    }
    return auxiliar->obtenerNombre();
}

#endif // GRAFOS_LISTA_H
