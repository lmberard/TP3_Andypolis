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

public:
    // PRE: -
    // POS: Se crea un inventario
    Inventario();

    // PRE:
    // POS: Carga la informacion del archivo txt de los materiales y crea la lista de materiales.
    void cargar(const string &PATH, Recurso &recurso);

    // PRE:
    // POS: Muestra por la terminal la lista de materiales con sus cantidades
    void mostrar_inventario();

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

    void recolectar(Edificio *edificio);
};

#endif
