#ifndef INVENTARIO_HPP
#define INVENTARIO_HPP

#include <iomanip>

#include "lista.hpp"
#include "material.hpp"
#include "edificio.hpp"

class Inventario
{

private:
    Lista<Material *> materiales1;
    int andycoins_gastadas;
    int bombas_usadas;
    int bombas_compradas;

public:
    // PRE: -
    // POS: Se crea un inventario
    Inventario();

    // PRE:
    // POS: Muestra por la terminal la lista de materiales con sus cantidades
    void mostrar_inventario();

    // PRE:
    // POS:
    void agregar_material(Material *material);

    // PRE:
    // POS: Verifica si hay materiales suficientes para la construccion de un edificio. Devuelve true si tiene y false si no.
    bool chequear_stock(Edificio *edificio, bool construir);

    // PRE:
    // POS: Verifica si hay materiales suficientes para la reparacion de un edificio. Devuelve true si tiene y false si no.
    bool chequear_stock_reparaciones(Edificio *edificio, bool reparar);

    // PRE:
    // POS: Devuelve la cantidad de materiales reciclados a la lista de materiales. (Se devuelve la mitad de la cantidad necesaria para construir ese tipo de edificio)
    void llenar_stock(Edificio *edificio);

    // PRE:
    // POS: se destruye el inventario
    ~Inventario();

    // PRE:
    // POS:
    void recolectar(Edificio *edificio);

    void agregar_bombas_compradas(int cantidad);

    /////////////////////////GETTERS////////////////////////////
    int obtener_andycoins_gastadas();
    void aniadir_andycoins_gastadas(int cantidad);
    int obtener_andycoins();
    void comprar_bombas(int cantidad);
    int obtener_bombas_compradas();
    void decrementar_bombas_contador();
    int obtener_bombas_usadas();
    void aumentar_bombas_usadas();
    Material *obtener_material(string material_recibido); // Función de uso interna . Un PRE tendría que ser que el material_recibido esté en la lista.
    Lista<Material *> &obtener_lista_de_materiales();

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

    void aniadir_cant_material(string nombre, int cantidad);
};

#endif
