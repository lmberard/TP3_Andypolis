#ifndef NODE_H
#define NODE_H

#include <iostream>
#include <string>

#include "list.h"

using namespace std;

template <typename T> class List;

template<typename T>
class Node {
	friend class List <T>;

private:
	T data;
	Node <T> *next;
	Node <T> *prev;

public:
	//PRE:
	//POST: Construye un nodo con los mismos datos que el nodo recibido
	Node(T &value);

	//PRE:
	//POST: Retorna el dato contenido en el nodo
	T & getData();
    
	//PRE:
	//POST: Retorna un puntero al siguiente nodo de la lista	
	Node <T>* getNext();
/*
	void remove(List<T> *);
	void removeAll();
	void print() const;
*/
};

template <typename N> Node<N> ::Node(N &value){
	data = value; 
	next = 0; 
}

template <typename T> T & Node<T>::getData(){
	return data;
}

template <typename T> Node <T>* Node<T>::getNext(){
	return next;
}

#endif