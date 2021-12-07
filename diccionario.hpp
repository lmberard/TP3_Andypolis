#ifndef DICCIONARIO_HPP
#define DICCIONARIO_HPP

#include "ABB.hpp"
#include "edificio.hpp"
#include "constructor.hpp"
class Diccionario
{
private:
    BST<Edificio*> diccionario;

public:
    //----------------------------------------------------------------
    Diccionario();
    ~Diccionario();

    //-------------------------SETTERS--------------------------------
    void agregar(string nombre, int piedra, int madera, int metal, int permitidos); // ver esto que onda
    void eliminar(Edificio nuevo);
    void eliminar(string nombre);

    //-------------------------GETTERS--------------------------------
    int obtener_cant_madera(string nombre, Constructor &bob);
    int obtener_cant_piedra(string nombre, Constructor &bob);
    int obtener_cant_metal(string nombre, Constructor &bob);
    int obtener_cant_permitida(string nombre, Constructor &bob);
    int obtener_cant_material_prod(string nombre, Constructor &bob);
    string obtener_tipo_material_prod(string nombre, Constructor &bob);
    string obtener_codigo(string nombre, Constructor &bob);

    //----------------------------------------------------------------
    void mostrar_todos();
    bool buscar_edificio(string nombre, Constructor &bob);
};
#endif
