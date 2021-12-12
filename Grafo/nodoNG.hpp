#ifndef NODO_H_INCLUDED
#define NODO_H_INCLUDED

//typedef int Dato;

template <class Dato>
class NodoNG {
//Atributos
private:
    Dato dato;
    NodoNG* siguiente;

//Metodos
public:
    //constructor
    //PRE:
    //POS:
    NodoNG(Dato d) {
        dato = d;
        siguiente = 0;
    }

    //PRE:
    //POS:
    void cambiar_dato(Dato d) {
        dato = d;
    }

    //PRE:
    //POS:
    void cambiar_siguiente(NodoNG* pn) {
        siguiente = pn;
    }

    //PRE:
    //POS:
    Dato & obtener_dato(){
        return dato;
    }

    //PRE:
    //POS:
    NodoNG* obtener_siguiente(){
        return siguiente;
    }

    /*~Nodo(){
        delete dato;
    }*/
};

#endif // NODO_H_INCLUDED
