#ifndef GRAFOS_NODO_H
#define GRAFOS_NODO_H
#include <string>
#include "coordenada.hpp"

using namespace std;

template < typename Tipo >
class NodoG {
/*ATRIBUTOS*/
private:
    Tipo* elemento;
    NodoG<Tipo>* siguiente;

/*MÉTODOS*/
public:
    NodoG(coordenada nombre);

    //post: devuelve el nodo siguiente.
    NodoG<Tipo>* obtenerSiguiente();

    //post: devuelve el nombre del nodo
    coordenada obtenerNombre();

    //post: le asigna como siguiente el nodo recibido
    void asignarSiguiente(NodoG<Tipo>* siguiente);

    ~NodoG();
};

template<typename Tipo>
NodoG<Tipo>::NodoG(coordenada nombre) {
    elemento = new Tipo(nombre);
    siguiente = nullptr;
}

template<typename Tipo>
NodoG<Tipo> *NodoG<Tipo>::obtenerSiguiente() {
    return siguiente;
}

template<typename Tipo>
coordenada NodoG<Tipo>::obtenerNombre() {
    return elemento->obtenerCoordenada();
}

template<typename Tipo>
void NodoG<Tipo>::asignarSiguiente(NodoG<Tipo> *siguiente) {
    this -> siguiente = siguiente;
}

template<typename Tipo>
NodoG<Tipo>::~NodoG() {
    delete elemento;
}


#endif //GRAFOS_NODO_H
