#ifndef ABB_H
#define ABB_H

#include "ABBNodo.hpp"
#include <iostream>

template <typename T, typename C>
class ABB
{
private:
    // Atributos:
    ABBNodo<T, C> *raiz;

    // Metodos:

    ABBNodo<T, C> *insertar(ABBNodo<T, C> *nodo, T *dato, C clave);
    // void imprimir_en_orden(ABBNodo<T,C>* nodo); // Posiblemente lo saque
    ABBNodo<T, C> *buscar(ABBNodo<T, C> *nodo, C clave);
    ABBNodo<T, C> *buscar_const(ABBNodo<T, C> *nodo, C clave) const;
    C buscar_minimo(ABBNodo<T, C> *nodo);
    C buscar_maximo(ABBNodo<T, C> *nodo);
    C sucesor(ABBNodo<T, C> *nodo);
    C predecesor(ABBNodo<T, C> *nodo);
    ABBNodo<T, C> *remover(ABBNodo<T, C> *nodo, C clave);
    void remover_todo(ABBNodo<T, C> *nodo);
    void imprimir_en_orden(ABBNodo<T, C> *node);

public:
    // Metodos:

    // pre:
    // pos:
    ABB();

    // pre:
    // pos:
    void insertar(T *dato, C clave);

    // pre:
    // pos:
    // void imprimir_en_orden();

    // pre:
    // pos:
    bool buscar(C clave);

    // pre:
    // pos:
    ABBNodo<T, C> *consultar(C clave);

    // pre:
    // pos:
    ABBNodo<T, C> *consultar_const(C clave) const;

    // pre:
    // pos:
    C buscar_minimo();

    // pre:
    // pos:
    C buscar_maximo();

    // pre:
    // pos:
    C sucesor(C clave);

    // pre:
    // pos:
    C predecesor(C clave);

    // pre:
    // pos:
    void remover(C clave);

    // pre:
    // pos:
    ABBNodo<T, C> *obtener_raiz();

    // pre:
    // pos:
    bool vacio();

    // pre:
    // pos:
    void remover_todo();

    // pre:
    // pos:
    ~ABB<T, C>();

    void imprimir_en_orden();
};

// -----------------------------------------------------------------------------------------

template <typename T, typename C>
ABB<T, C>::ABB()
{

    this->raiz = NULL;
}

// -----------------------------------------------------------------------------------------

template <typename T, typename C>
ABBNodo<T, C> *ABB<T, C>::insertar(ABBNodo<T, C> *nodo, T *dato, C clave)
{

    if (nodo == NULL)
    {
        nodo = new ABBNodo<T, C>(dato, clave);
    }

    else if (clave > nodo->obtener_clave())
    {
        nodo->colocar_derecha(insertar(nodo->obtener_derecha(), dato, clave), nodo);
    }

    else
    {
        nodo->colocar_izquierda(insertar(nodo->obtener_izquierda(), dato, clave), nodo);
    }

    return nodo;
}

// -----------------------------------------------------------------------------------------

template <typename T, typename C>
void ABB<T, C>::insertar(T *dato, C clave)
{

    this->raiz = insertar(this->raiz, dato, clave);
}

// -----------------------------------------------------------------------------------------
/*
// Este deberia sacarlo o modificarlo
template <typename T, typename C>
void ABB<T,C>::imprimir_en_orden(ABBNodo<T,C>* nodo){

    if (nodo != NULL){
        imprimir_en_orden(nodo -> obtener_izquierda());
        std::cout << nodo -> obtener_dato() << ' ';
        imprimir_en_orden(nodo -> obtener_derecha());
    }
}
*/

// -----------------------------------------------------------------------------------------

/*
template <typename T, typename C>
void ABB<T,C>::imprimir_en_orden(){

    this -> imprimir_en_orden(this -> raiz);
}
*/

// -----------------------------------------------------------------------------------------

template <typename T, typename C>
ABBNodo<T, C> *ABB<T, C>::buscar(ABBNodo<T, C> *nodo, C clave)
{

    if (nodo == NULL || nodo->obtener_clave() == clave)
    {
        return nodo;
    }

    if (clave > nodo->obtener_clave())
        return buscar(nodo->obtener_derecha(), clave);

    return buscar(nodo->obtener_izquierda(), clave);
}

// -----------------------------------------------------------------------------------------

template <typename T, typename C>
ABBNodo<T, C> *ABB<T, C>::buscar_const(ABBNodo<T, C> *nodo, C clave) const
{

    if (nodo == NULL || nodo->obtener_clave() == clave)
    {
        return nodo;
    }

    if (clave > nodo->obtener_clave())
        return buscar_const(nodo->obtener_derecha(), clave);

    return buscar_const(nodo->obtener_izquierda(), clave);
}

// -----------------------------------------------------------------------------------------

template <typename T, typename C>
bool ABB<T, C>::buscar(C clave)
{

    ABBNodo<T, C> *resultado = buscar(this->raiz, clave);

    return resultado != NULL;
}

// -----------------------------------------------------------------------------------------

template <typename T, typename C>
ABBNodo<T, C> *ABB<T, C>::consultar(C clave)
{

    ABBNodo<T, C> *resultado = buscar(this->raiz, clave);

    return resultado;
}

// -----------------------------------------------------------------------------------------

template <typename T, typename C>
ABBNodo<T, C> *ABB<T, C>::consultar_const(C clave) const
{

    ABBNodo<T, C> *resultado = buscar_const(this->raiz, clave);

    return resultado;
}

// -----------------------------------------------------------------------------------------

template <typename T, typename C>
C ABB<T, C>::buscar_minimo(ABBNodo<T, C> *nodo)
{

    if (nodo == NULL)
        return "?"; // Antes habia un '-1'

    else if (nodo->obtener_izquierda() == NULL)
        return nodo->obtener_clave();

    else
        return buscar_minimo(nodo->obtener_izquierda());
}

// -----------------------------------------------------------------------------------------

template <typename T, typename C>
C ABB<T, C>::buscar_minimo()
{
    return buscar_minimo(this->raiz);
}

// -----------------------------------------------------------------------------------------

template <typename T, typename C>
C ABB<T, C>::buscar_maximo(ABBNodo<T, C> *nodo)
{

    if (nodo == NULL)
        return "?"; // Antes habia un '-1'

    else if (nodo->obtener_derecha() == NULL)
        return nodo->obtener_clave();

    else
        return buscar_maximo(nodo->obtener_derecha());
}

// -----------------------------------------------------------------------------------------

template <typename T, typename C>
C ABB<T, C>::buscar_maximo()
{
    return buscar_maximo(this->raiz);
}

// -----------------------------------------------------------------------------------------

template <typename T, typename C>
C ABB<T, C>::sucesor(ABBNodo<T, C> *nodo)
{

    if (nodo->obtener_derecha() != NULL)
    {

        return buscar_minimo(nodo->obtener_derecha());
    }

    ABBNodo<T, C> *sucesor = NULL;
    ABBNodo<T, C> *ancestro = this->raiz;
    while (ancestro != nodo)
    {
        if (nodo->obtener_clave() < ancestro->obtener_clave())
        {
            sucesor = ancestro;
            ancestro = ancestro->obtener_izquierda();
        }
        else
            ancestro = ancestro->obtener_derecha();
    }

    return sucesor->obtener_clave();
}

// -----------------------------------------------------------------------------------------

template <typename T, typename C>
C ABB<T, C>::sucesor(C clave)
{

    ABBNodo<T, C> *nodo_clave = this->buscar(this->raiz, clave);

    if (nodo_clave == NULL)
        return "?"; // Antes habia un '-1'

    else
        return sucesor(nodo_clave);
}

// -----------------------------------------------------------------------------------------

template <typename T, typename C>
C ABB<T, C>::predecesor(ABBNodo<T, C> *nodo)
{
    if (nodo->obtener_izquierda() != NULL)
    {
        return buscar_maximo(nodo->obtener_izquierda());
    }

    ABBNodo<T, C> *sucesor = NULL;
    ABBNodo<T, C> *ancestro = this->raiz;
    while (ancestro != nodo)
    {
        if (nodo->obtener_clave() < ancestro->obtener_clave())
        {
            sucesor = ancestro;
            ancestro = ancestro->obtener_derecha();
        }
        else
            ancestro = ancestro->obtener_izquierda();
    }

    return sucesor->obtener_clave();
}

// -----------------------------------------------------------------------------------------

template <typename T, typename C>
C ABB<T, C>::predecesor(C clave)
{
    ABBNodo<T, C> *nodo_clave = this->buscar(this->raiz, clave);

    if (nodo_clave == NULL)
        return "?"; // Antes habia un '-1'

    else
        return predecesor(nodo_clave);
}

// -----------------------------------------------------------------------------------------

template <typename T, typename C>
ABBNodo<T, C> *ABB<T, C>::remover(ABBNodo<T, C> *nodo, C clave)
{

    if (nodo == NULL)
        return NULL;

    if (nodo->obtener_clave() == clave)
    {

        if (nodo->es_hoja())
            delete nodo;

        else if (nodo->tiene_solo_hijo_derecho())
        {

            nodo->obtener_derecha()->colocar_padre(nodo->obtener_padre());

            ABBNodo<T, C> *aux = nodo;
            nodo = nodo->obtener_derecha();
            delete aux;
        }

        else if (nodo->tiene_solo_hijo_izquierdo())
        {

            nodo->obtener_izquierda()->colocar_padre(nodo->obtener_padre());

            ABBNodo<T, C> *aux = nodo;
            nodo = nodo->obtener_izquierda();
            delete aux;
        }

        else
        {

            C clave_sucesor = this->sucesor(clave);

            T *dato_sucesor = this->consultar(clave_sucesor)->obtener_dato();

            nodo->colocar_dato(dato_sucesor);

            nodo->colocar_derecha(remover(nodo->obtener_derecha(), clave_sucesor));
        }
    }

    else if (nodo->obtener_clave() < clave)
        nodo->colocar_derecha(remover(nodo->obtener_derecha(), clave));

    else
        nodo->colocar_izquierda(remover(nodo->obtener_izquierda(), clave));

    return nodo;
}

// -----------------------------------------------------------------------------------------

template <typename T, typename C>
void ABB<T, C>::remover(C clave)
{

    this->raiz = remover(this->raiz, clave);
}

// -----------------------------------------------------------------------------------------

template <typename T, typename C>
ABBNodo<T, C> *ABB<T, C>::obtener_raiz()
{

    return this->raiz;
}

// -----------------------------------------------------------------------------------------

template <typename T, typename C>
bool ABB<T, C>::vacio()
{

    return this->raiz == NULL;
}

// -----------------------------------------------------------------------------------------

template <typename T, typename C>
void ABB<T, C>::remover_todo(ABBNodo<T, C> *nodo)
{

    if (nodo == NULL)
        return;
    this->remover_todo(nodo->obtener_izquierda());
    this->remover_todo(nodo->obtener_derecha());
    delete nodo;
}

// -----------------------------------------------------------------------------------------

template <typename T, typename C>
void ABB<T, C>::remover_todo()
{

    this->remover_todo(this->raiz);
}

// -----------------------------------------------------------------------------------------

template <typename T, typename C>
ABB<T, C>::~ABB<T, C>()
{

    this->remover_todo();
}

template <typename T, typename C>
void ABB<T, C>::imprimir_en_orden(ABBNodo<T, C> *node)
{
    // me imprime de menor a mayor
    // el menor es cuando el nodo de la izquierda es nulo
    if (node->obtener_dato() != NULL)
    {
        imprimir_en_orden(node->obtener_izquierda());
        // si es nulo se corta ahi y sigue del otro lado
        std::cout << node->obtener_clave() << endl;
        imprimir_en_orden(node->obtener_derecha());
    }
    // la complejidad es O(n) siendo n la cant de nodos
}

template <typename T, typename C>
void ABB<T, C>::imprimir_en_orden()
{
    this->imprimir_en_orden(this->raiz);
}

#endif // ABB_H
