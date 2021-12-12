#ifndef LISTA_H_INCLUDED
#define LISTA_H_INCLUDED
#include <iostream>
#include "nodoNG.hpp"

using namespace std;

template <class Dato>
class ListaNG {
    // Atributos
private:
    NodoNG <Dato>* primero;
    int cantidad;

    // Metodos
public:
    //Constructor
    //PRE: -
    //POS: tope = 0
    ListaNG(){
        primero = 0;
        cantidad = 0;
    }

    ListaNG(ListaNG& otra){
        primero = 0;
        cantidad =  0;
        for (int i = 1; i < otra.cantidad + 1; i++) {
            this->alta(otra[i]);
        }
    } //TODO: Cambie esto

    ListaNG& operator=(ListaNG& otra){
        this->vaciar();
        cantidad =  0;
        for (int i = 1; i < otra.cantidad + 1; i++) {
            this->alta(otra[i]);  
        }

        return *this;
    } //TODO: Cambie esto

    void vaciar() {
        while (! vacia())
            baja(1);
    } //TODO: Cambie esto

    //PRE: 1 <= pos <= cantidad + 1
    //POS: agrega d arriba de la pila e incrementa tope en 1
    void alta(Dato d){
        NodoNG<Dato>* nuevo = new NodoNG<Dato>(d);
        NodoNG<Dato>* siguiente = primero;

        if (1) {
            primero = nuevo;
        }
        /*else{
            Nodo<Dato>* anterior = obtener_nodo(pos - 1);
            siguiente = anterior->obtener_siguiente();
            anterior->cambiar_siguiente(nuevo);
        }*/
        nuevo->cambiar_siguiente(siguiente);
        cantidad++;
    }

    int mostrar_cantidad(){
        return cantidad;
    }

    //PRE: 1 <= pos <= cantidad
    //POS: devuelve el dato que esta arriba
    Dato & operator[](int pos){
        NodoNG<Dato>* aux = obtener_nodo(pos);
        return aux->obtener_dato();
    }


    //PRE: 1 <= pos <= cantidad
    //POS: devuelve el dato que esta arriba y decrementa tope
    void baja(int pos){
        NodoNG<Dato>* baja = primero;
        if (pos == 1)
            primero = baja->obtener_siguiente();
        else {
            NodoNG<Dato>* anterior = obtener_nodo(pos - 1);
            baja = anterior->obtener_siguiente();
            anterior->cambiar_siguiente(baja->obtener_siguiente());
        }
        cantidad--;

        delete baja;
    }

    //PRE: -
    //POS: devuelve true si la pila esta vacia, false si no
    bool vacia() {
        return (cantidad == 0);
    }

    //Destructor
    ~ListaNG(){
        while (! vacia())
            baja(1);
    }

    //NO VA COMO PRIMITIVA DE LISTA�
    /*void mostrar() {
        Nodo<Dato>* aux = primero;
        while (aux) {
            std::cout << aux->obtener_dato() << " - ";
            aux = aux->obtener_siguiente();
        }
    }*/

   /* void liberar(){
        Nodo<Dato>* aux = primero;
        aux->liberar();
    }*/




private:
    NodoNG<Dato>* obtener_nodo(int pos){
    NodoNG<Dato>* aux = primero;
    for (int i = 1; i < pos; i++)
        aux = aux->obtener_siguiente();
    return aux;
}
};

#endif // LISTA_H_INCLUDED