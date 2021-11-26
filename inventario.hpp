#ifndef INVENTARIO_HPP
#define INVENTARIO_HPP

#include "lista.hpp"
#include "edificio.hpp"
#include "recurso.hpp"
#include <fstream>
class Inventario
{

private:
    Lista<Material *> materiales1;
    int andycoins_contador;


public:
    // PRE: -
    // POS: Se crea un inventario
    Inventario();

    // PRE:
    // POS: Muestra por la terminal la lista de materiales con sus cantidades
    void mostrar_inventario();

    // PRE:
    // POS:
    void agregar_material(string nombre, int cantidad, Recurso &recurso);

    // PRE:
    // POS: Verifica si hay materiales suficientes para la construccion de un edificio. Devuelve true si tiene y false si no.
    bool chequear_stock(Edificio *edificio, bool construir);

    // PRE:
    // POS: Devuelve la cantidad de materiales reciclados a la lista de materiales. (Se devuelve la mitad de la cantidad necesaria para construir ese tipo de edificio)
    void llenar_stock(Edificio *edificio);

    // PRE:
    // POS: se destruye el inventario
    ~Inventario();

    // PRE:
    // POS:
    void recolectar(Edificio *edificio);


    /////////////////////////GETTERS////////////////////////////
    int obtener_andycoins_contador();
    Material * obtener_material(string material_recibido); //Función de uso interna . Un PRE tendría que ser que el material_recibido esté en la lista.


    // PRE:
    // POS:
    int obtener_cantidad();

    // PRE:
    // POS:
    string obtener_nombre_material(int posicion);

    // PRE:
    // POS:
    int obtener_cant_material(int posicion);

    void modificar_cant_material(string nombre, int cantidad);
};

#endif
