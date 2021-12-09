#ifndef NODO_ABB_H
#define NODO_ABB_H


template <typename T, typename C>
class ABBNodo
{
private:
    // Atributos:
    T* dato;
    C clave;
    ABBNodo<T,C>* izquierda; // Hijo izquierda
    ABBNodo<T,C>* derecha; // Hijo derecha
    ABBNodo<T,C>* padre;

public:
    // Metodos: 

    // pre:
    // pos:
    ABBNodo(T* dato, C clave);

    // pre:
    // pos:
    ~ABBNodo();

    // pre:
    // pos:
    T* obtener_dato();

    // pre:
    // pos:
    T* obtener_dato_const() const;

    // pre:
    // pos:
    C obtener_clave();

    // pre:
    // pos:
    void colocar_dato(T* dato);

    // pre:
    // pos:
    void colocar_clave(C clave);

    // pre:
    // pos:
    void colocar_derecha(ABBNodo<T,C>* derecha, ABBNodo<T,C>* padre);

    // pre:
    // pos:
    void colocar_izquierda(ABBNodo<T,C>* izquierda, ABBNodo<T,C>* padre);

    // pre:
    // pos:
    void colocar_derecha(ABBNodo<T,C>* derecha);

    // pre:
    // pos:
    void colocar_izquierda(ABBNodo<T,C>* izquierda);

    // pre:
    // pos:
    void colocar_padre(ABBNodo<T,C>* padre);

    // pre:
    // pos:
    ABBNodo<T,C>* obtener_derecha();

    // pre:
    // pos:
    ABBNodo<T,C>* obtener_izquierda();

    // pre:
    // pos:
    ABBNodo<T,C>* obtener_padre();
    
    // pre:
    // pos:
    bool es_hoja();

    // pre:
    // pos:
    bool tiene_solo_hijo_derecho();

    // pre:
    // pos:
    bool tiene_solo_hijo_izquierdo();
};


// -----------------------------------------------------------------------------------------


template <typename T, typename C>
ABBNodo<T,C>::ABBNodo(T* dato, C clave){

    this -> clave = clave;
    this -> dato = dato;
    this -> izquierda = NULL;
    this -> derecha = NULL;
    this -> padre = NULL;
}


// -----------------------------------------------------------------------------------------


template <typename T, typename C>
ABBNodo<T,C>::~ABBNodo(){

    delete dato;
}

// -----------------------------------------------------------------------------------------


template <typename T, typename C>
T* ABBNodo<T,C>::obtener_dato(){

    return this -> dato;
}


// -----------------------------------------------------------------------------------------


template <typename T, typename C>
T* ABBNodo<T,C>::obtener_dato_const() const{

    return this -> dato;
}


// -----------------------------------------------------------------------------------------


template <typename T, typename C>
C ABBNodo<T,C>::obtener_clave(){

    return this -> clave;
}


// -----------------------------------------------------------------------------------------


template <typename T, typename C>
void ABBNodo<T,C>::colocar_dato(T* dato){

    this -> dato = dato;
}


// -----------------------------------------------------------------------------------------


template <typename T, typename C>
void ABBNodo<T,C>::colocar_clave(C clave){

    this -> clave = clave;
}


// -----------------------------------------------------------------------------------------


template <typename T, typename C>
void ABBNodo<T,C>::colocar_derecha(ABBNodo<T,C>* derecha, ABBNodo<T,C>* padre){

    this -> derecha = derecha;
    this -> padre = padre;
}


// -----------------------------------------------------------------------------------------


template <typename T, typename C>
void ABBNodo<T,C>::colocar_derecha(ABBNodo<T,C>* derecha){

    this -> derecha = derecha;
}


// -----------------------------------------------------------------------------------------


template <typename T, typename C>
void ABBNodo<T,C>::colocar_izquierda(ABBNodo<T,C>* izquierda, ABBNodo<T,C>* padre){

    this -> izquierda = izquierda;
    this -> padre = padre;
}


// -----------------------------------------------------------------------------------------


template <typename T, typename C>
void ABBNodo<T,C>::colocar_izquierda(ABBNodo<T,C>* izquierda){

    this -> izquierda = izquierda;
}


// -----------------------------------------------------------------------------------------


template <typename T, typename C>
void ABBNodo<T,C>::colocar_padre(ABBNodo<T,C>* padre){

    this -> padre = padre;
}


// -----------------------------------------------------------------------------------------


template <typename T, typename C>
ABBNodo<T,C>* ABBNodo<T,C>::obtener_derecha(){

    return this -> derecha;
}


// -----------------------------------------------------------------------------------------


template <typename T, typename C>
ABBNodo<T,C>* ABBNodo<T,C>::obtener_izquierda(){
    
    return this -> izquierda;
}


// -----------------------------------------------------------------------------------------


template <typename T, typename C>
ABBNodo<T,C>* ABBNodo<T,C>::obtener_padre(){
    
    return this -> padre;
}


// -----------------------------------------------------------------------------------------


template <typename T, typename C>
bool ABBNodo<T,C>::es_hoja(){

    return (this -> obtener_izquierda() == NULL && this -> obtener_derecha() == NULL);
}


// -----------------------------------------------------------------------------------------


template <typename T, typename C>
bool ABBNodo<T,C>::tiene_solo_hijo_derecho(){

    return (this -> obtener_izquierda() == NULL && this -> obtener_derecha() != NULL);
}


// -----------------------------------------------------------------------------------------


template <typename T, typename C>
bool ABBNodo<T,C>::tiene_solo_hijo_izquierdo(){

    return (this -> obtener_izquierda() != NULL && this -> obtener_derecha() == NULL);
}


#endif //NODO_ABB_H