
#include "ABBNode.hpp"
#include <iostream>

#ifndef ABB_HPP
#define ABB_HPP

template <class T>
class BST
{
private:
    BSTNode<T> *root;
    // cada nodo de estos tiene 3 punteros:
    //  el de la derecha, el de la izquierda y el padre

public:
    // Creates an empty tree
    BST();

    // Adds a new node to the actual BST. If its the tree is empty
    // the node inserted will be the root
    void insert(T data);

    // Prints all the data stored in the BST, sorted from the
    // smallest value to the greatest value.
    void print_in_order();

    // Finds a given value in the BST. If the key exists it returns
    // TRUE, otherwise it returns FALSE.
    bool search(T data);

    // Finds the minimum value that exist in the BST.
    T find_min();

    // Finds the maximum value that exist in the BST.
    T find_max();

    // Finds the successor of a given data value.
    T successor(T data);

    // Finds the predecessor of a given data value.
    T predecessor(T data);

    // Removes a given data from the BST
    void remove(T data);

    BSTNode<T> *get_root();

    bool empty();

    // Deletes all the nodes in the BST
    void delete_all();

    ~BST<T>();

private:
    /*los metodos que haya que ingresar el nodo son privados
ya que no se tiene porque saber como esta implementada el abb
aca es donde esta la implementacion posta, los otros son solo
como una interfaz para la persona que use el ABB
*/
    BSTNode<T> *insert(BSTNode<T> *node, T data);
    void print_in_order(BSTNode<T> *node);
    BSTNode<T> *search(BSTNode<T> *node, T data);
    T find_min(BSTNode<T> *node);
    T find_max(BSTNode<T> *node);
    T successor(BSTNode<T> *node);
    T predecessor(BSTNode<T> *node);
    BSTNode<T> *remove(BSTNode<T> *node, T data);
    void delete_all(BSTNode<T> *node);
};

// Creates an empty tree
// Inicializa la raiz en cero
template <class T>
BST<T>::BST()
{
    this->root = NULL;
}

template <class T>
BSTNode<T> *BST<T>::insert(BSTNode<T> *node, T data)
{
    // cuando llega a un nodo que esta vacio lo agrega
    if (node == NULL)
    {
        ////corte de la recursion. caso base
        node = new BSTNode<T>(data);
    }
    // si es mas grande lo pongo a la derecha
    else if (data > node->get_data())
    {
        // aca hay recursividad, pero en vez de acceder al nodo raiz
        // accede al nodo que tiene a la derecha (ver implement del nodo)
        node->set_right(insert(node->get_right(), data), node);
        // le setea el nodo
    }
    // si no a la izquierda
    else
    {
        node->set_left(insert(node->get_left(), data), node);
    }
    return node;
    /*
    Cual es la complejidad de este algoritmo?
    Cuando el arbol no esta balanceada la complejidad no es tan precisa, se puede calcular una
    cota superior. Aca se recorre la cantidad de veces como niveles, es la altura.
    y la altura se calcula como log_2(cantNodos)
    */
}

template <class T>
void BST<T>::insert(T data)
{
    this->root = insert(this->root, data);
}

template <class T>
void BST<T>::print_in_order(BSTNode<T> *node)
{
    // me imprime de menor a mayor
    // el menor es cuando el nodo de la izquierda es nulo
    if (node != NULL)
    {
        print_in_order(node->get_left());
        // si es nulo se corta ahi y sigue del otro lado
        std::cout << node->get_data() << ' ';
        print_in_order(node->get_right());
    }
    // la complejidad es O(n) siendo n la cant de nodos
}

template <class T>
void BST<T>::print_in_order()
{
    this->print_in_order(this->root);
}

template <class T>
BSTNode<T> *BST<T>::search(BSTNode<T> *node, T data)
{
    if (node == NULL || node->get_data() == data)
        return node; // devuelve null si no encontro o el nodo si lo encontro

    // busco de una parte y si no busco del otro (busqueda binaria)
    if (data > node->get_data())
        return search(node->get_right(), data);

    return search(node->get_left(), data);
    // complejidad logaritmica
}

template <class T>
bool BST<T>::search(T data)
{
    BSTNode<T> *result = search(this->root, data);

    return result != NULL;
}

template <class T>
T BST<T>::find_min(BSTNode<T> *node)
{

    if (node == NULL)
        return -1;                     // arbol vacio
    else if (node->get_left() == NULL) // el minimo no tiene un nodo a la izquierda!
        return node->get_data();       // caso corte de recursividad
    else
        return find_min(node->get_left()); // recursividad hasta encontrar el min
    // complejidad es logaritmica porque siempre divido a la mitad.
    // es la altura. osea log(n)
}

template <class T>
T BST<T>::find_min()
{
    return find_min(this->root);
}

template <class T>
T BST<T>::find_max(BSTNode<T> *node)
{
    // el maximo es que no tiene nodo a la derecha
    if (node == NULL)
        return -1;
    else if (node->get_right() == NULL)
        return node->get_data();
    else
        return find_max(node->get_right());
}

template <class T>
T BST<T>::find_max()
{
    return find_max(this->root);
}

template <class T>
T BST<T>::successor(BSTNode<T> *node)
{
    if (node->get_right() != NULL) // si tiene subarbol derecho
    {
        return find_min(node->get_right());
    }
    BSTNode<T> *successor = NULL;
    BSTNode<T> *ancestor = this->root;
    while (ancestor != node)
    { // tengo que buscar el mayor que el actual
        if (node->get_data() < ancestor->get_data())
        {
            successor = ancestor;
            ancestor = ancestor->get_left();
        }
        else
            ancestor = ancestor->get_right();
    }
    return successor->get_data();
}

template <class T>
T BST<T>::successor(T data)
{
    BSTNode<T> *data_node = this->search(this->root, data);
    // Return the key. If the key is not found or successor is not found, return -1
    if (data_node == NULL)
        return -1;
    else
        return successor(data_node); // metodo privado
}

template <class T>
T BST<T>::predecessor(BSTNode<T> *node)
{
    if (node->get_left() != NULL)
    {
        return find_max(node->get_left());
    }

    BSTNode<T> *successor = NULL;
    BSTNode<T> *ancestor = this->root;
    while (ancestor != node)
    {
        if (node->get_data() > ancestor->get_data())
        {
            successor = ancestor; // so far this is the deepest node for which current node is in left
            ancestor = ancestor->get_right();
        }
        else
            ancestor = ancestor->get_left();
    }
    return successor->get_data();
}

template <class T>
T BST<T>::predecessor(T data)
{
    BSTNode<T> *data_node = this->search(this->root, data);

    if (data_node == NULL)
        return -1;
    else
        return predecessor(data_node);
}

template <class T>
BSTNode<T> *BST<T>::remove(BSTNode<T> *node, T data)
{
    // The given node is not found in BST
    if (node == NULL)
        return NULL;

    if (node->get_data() == data)
    {
        if (node->isLeaf())
            delete node;
        else if (node->rightChildOnly())
        {
            // The only child will be connected to the parent's of node directly
            node->get_right()->set_parent(node->get_parent());
            // Bypass node
            BSTNode<T> *aux = node;
            node = node->get_right();
            delete aux;
        }
        else if (node->leftChildOnly())
        {
            // The only child will be connected to the parent's of node directly
            node->get_left()->set_parent(node->get_parent());
            // Bypass node
            BSTNode<T> *aux = node;
            node = node->get_left();
            delete aux;
        }

        // The node has two children (left and right)
        else
        {
            // Find successor or predecessor to avoid quarrel
            T successor_data = this->successor(data);

            // Replace node's key with successor's key
            node->set_data(successor_data);

            // Delete the old successor's key
            node->set_right(remove(node->get_right(), successor_data));
        }
    }

    else if (node->get_data() < data)
        node->set_right(remove(node->get_right(), data));

    else
        node->set_left(remove(node->get_left(), data));

    return node;
}

template <class T>
void BST<T>::remove(T data)
{
    this->root = remove(this->root, data);
}

template <class T>
BSTNode<T> *BST<T>::get_root()
{
    return this->root;
}

template <class T>
bool BST<T>::empty()
{
    return this->root == NULL;
}

template <class T>
void BST<T>::delete_all(BSTNode<T> *node)
{
    if (node == NULL)
        return;
    this->delete_all(node->get_left());
    this->delete_all(node->get_right());
    delete node;
}

template <class T>
void BST<T>::delete_all()
{
    this->delete_all(this->root);
}

template <class T>
BST<T>::~BST<T>()
{
    this->delete_all();
}

#endif // ABB_BST_H
