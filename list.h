#ifndef LIST_H
#define LIST_H

#include <iostream>
#include <string>

#include "node.h"

using namespace std;


template <typename T>
class List{
private:
	Node<T> *first;

public:
	//PRE:
	//POST: Este constructor crea una lista vacia
	List();

	//PRE:
	//POST: Este destructor destruye la lista
	~List();

	//PRE:
	//POST: Este metodo retorna un puntero al primer nodo de la lista
	Node<T>* getFirst();
	
	//PRE:
	//POST: copia la direccion del nodo recibido en "first", que apunta al primer nodo de la lista
	void setFirst(Node<T> *);
	
	//PRE:
	//POST: Agrega al final de la lista el nodo recibido
	void addNodeEnd(Node <T> node);
	
	//PRE:
	//POST: Agrega al final de la lista un nodo que contenga el dato recibido
	void addNodeEnd(T node);
	
	//PRE:
	//POST: Retorna el ultimo nodo de la lista
	Node<T> getLastNode();
	
	//void destroy();
	
	//PRE:
	//POST: Elimina un nodo de la lista
	void removeElement(Node <T> & dataNode);

	//PRE: el operador "<<" debe poder ser implementado en el dato contenido en los nodos
	//POST: Imprime el dato de las listas
	void print() const;
	
	//PRE:
	//POST: Retorna true si la lista esta vacia, o false si la lista no esta vacia
	bool isEmpty() const;
	
	//PRE:
	//POST: Este metodo retorna la cantidad de nodos de la lista
	int getSize();
};


template <typename T> List<T>::List(){
	first = 0;
}

template <typename T> List<T>::~List(){
	Node<T> *aux = first;

	while (!isEmpty()){
		first = first->next;
		delete aux;
		aux = first;
	}
}

template <typename T> int List<T>::getSize(){
	Node<T> *aux = first;
	int counter = 0;

	while(aux != nullptr){
		aux = aux->next;
		counter++;
	}
	return counter;	
}

template <typename T> Node <T>* List<T>::getFirst(){
	return first;
}

template <typename T> void List<T>::setFirst(Node<T> * node){
	first = node;
}

template <typename T> void List<T>::addNodeEnd(Node <T> node){
	Node<T> *aux1;
	Node<T> *aux2;
	aux1 = new Node<T>(node);

	if(isEmpty()){             //si la lista está vacia, lo agrega al comienzo 
 		first = aux1;
 		first->next = 0;
		first->prev = 0;
 	} else{
		aux2 = first;
		while(aux2->next)
			aux2 = aux2->next;
		aux2->next = aux1;
		aux1->prev = aux2;
		aux1->next = 0;
	}
}

template <typename T> void List<T>::addNodeEnd(T data){
    Node<T> *aux1;
    Node<T> *aux2;
    aux1 = new Node<T>(data);

    if(isEmpty()){             //si la lista está vacia, lo agrega al comienzo 
        first = aux1;
        first->next = 0;
        first->prev = 0;
     } else{
        aux2 = first;
        while(aux2->next)
            aux2 = aux2->next;
        aux2->next = aux1;
        aux1->prev = aux2;
        aux1->next = 0;
    }
}

template <typename T> void List<T>::removeElement(Node <T> & dataNode){
	Node<T> *aux = first;
	bool deleted = false;

	while(aux != nullptr && deleted == false){
		if( (aux->data).row == (dataNode.getData()).row && (aux->data).column == (dataNode.getData()).column){
			if(aux->prev && aux->next){
				(aux->prev)->next = aux->next;
				(aux->next)->prev = aux->prev;
				delete aux;
				deleted = true;
			}else if(aux->prev){
				(aux->prev)->next = nullptr;
				delete aux;
				deleted = true;
			}else if(aux->next){
				(aux->next)->prev = nullptr;
				first = aux->next;
				delete aux;
				deleted = true;
			}else{
				delete aux;
				first = nullptr;
				deleted = true;
			}
		}
		else{
			aux = aux->next;
		}
	}
}

template <typename T> Node<T> List<T>::getLastNode(){
	Node<T> *aux = first;
	
	while(aux->next)
		aux = aux->next;
	return (*aux);
}

template <typename T> bool List<T>:: isEmpty() const{
	return (first == 0);
}

template <typename T> void List<T>::print() const{
	Node<T> * aux = first;

	if(!isEmpty()){
		while(aux != 0){
			cout << aux->data << '\n';
			aux = aux->next;
		}
		cout << endl;
	}
	//else cout << "lista vacia";
}

#endif