#ifndef GRAFOS_NODO_H
#define GRAFOS_NODO_H
#include <string>
#include "coordenada.hpp"

using namespace std;

template < typename Tipo >
class Nodo {
/*ATRIBUTOS*/
private:
    Tipo* elemento;
    Nodo<Tipo>* siguiente;

/*MÉTODOS*/
public:
    Nodo(coordenada nombre);

    //post: devuelve el nodo siguiente.
    Nodo<Tipo>* obtenerSiguiente();

    //post: devuelve el nombre del nodo
    coordenada obtenerNombre();

    //post: le asigna como siguiente el nodo recibido
    void asignarSiguiente(Nodo<Tipo>* siguiente);

    ~Nodo();
};

template<typename Tipo>
Nodo<Tipo>::Nodo(coordenada nombre) {
    elemento = new Tipo(nombre);
    siguiente = nullptr;
}

template<typename Tipo>
Nodo<Tipo> *Nodo<Tipo>::obtenerSiguiente() {
    return siguiente;
}

template<typename Tipo>
coordenada Nodo<Tipo>::obtenerNombre() {
    return elemento->obtenerCoordenada();
}

template<typename Tipo>
void Nodo<Tipo>::asignarSiguiente(Nodo<Tipo> *siguiente) {
    this -> siguiente = siguiente;
}

template<typename Tipo>
Nodo<Tipo>::~Nodo() {
    delete elemento;
}


#endif //GRAFOS_NODO_H
