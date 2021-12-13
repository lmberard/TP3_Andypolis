#include "diccionario.hpp"

Diccionario::Diccionario()
{
}

Diccionario::~Diccionario()
{
}

//-------------------------SETTERS--------------------------------
void Diccionario::agregar(string nombre, int piedra, int madera, int metal, int permitidos)
{
    if (nombre == "aserradero")
        diccionario.insert(new Aserradero(piedra, madera, metal, permitidos));
    if (nombre == "fabrica")
        diccionario.insert(new Fabrica(piedra, madera, metal, permitidos));
    if (nombre == "escuela")
        diccionario.insert(new Escuela(piedra, madera, metal, permitidos));
    if (nombre == "yacimiento")
        diccionario.insert(new Yacimiento(piedra, madera, metal, permitidos));
    if (nombre == "mina")
        diccionario.insert(new Mina(piedra, madera, metal, permitidos));
    if (nombre == "obelisco")
        diccionario.insert(new Obelisco(piedra, madera, metal, permitidos));
    if (nombre == "planta")
        diccionario.insert(new PlantaElectrica(piedra, madera, metal, permitidos));
}

void Diccionario::eliminar(Edificio nuevo)
{
    diccionario.remove(nuevo);
}

void Diccionario::eliminar(string nombre)
{
    cout << "Ni idea si hace falta" << endl;
}

//----------------------------------------------------------------
void Diccionario::mostrar_todos()
{
    diccionario.print_in_order();
}

bool Diccionario::buscar_edificio(string nombre, Constructor &bob)
{
    bool se_encontro = false;
    Edificio *edif_buscado = bob.construye(nombre);
    if (!edif_buscado)
        return false;
    se_encontro = diccionario.search(edif_buscado);
    delete edif_buscado;
    return se_encontro;
}

//-------------------------GETTERS--------------------------------
int Diccionario::obtener_cant_madera(string nombre, Constructor &bob)
{
    Edificio *edif_buscado = bob.construye(nombre);
    if (!edif_buscado)
        return false;

    //OJO
    BSTNode<Edificio*> *resultado = diccionario.search(diccionario.get_root(), edif_buscado);
    int cant_madera = resultado->get_data().obtener_madera();

    delete edif_buscado;
    return cant_madera;
}

int Diccionario::obtener_cant_piedra(string nombre, Constructor &bob)
{
    Edificio *edif_buscado = bob.construye(nombre);
    if (!edif_buscado)
        return false;

    BSTNode<Edificio*> *resultado = diccionario.search(diccionario.get_root(), edif_buscado);
    int cant = resultado->get_data().obtener_piedra();

    delete edif_buscado;
    return cant;
}

int Diccionario::obtener_cant_metal(string nombre, Constructor &bob)
{
    Edificio *edif_buscado = bob.construye(nombre);
    if (!edif_buscado)
        return false;

    BSTNode<Edificio*> *resultado = diccionario.search(diccionario.get_root(), edif_buscado);
    int cant = resultado->get_data().obtener_metal();

    delete edif_buscado;
    return cant;
}

int Diccionario::obtener_cant_permitida(string nombre, Constructor &bob)
{
    Edificio *edif_buscado = bob.construye(nombre);
    if (!edif_buscado)
        return false;

    BSTNode<Edificio*> *resultado = diccionario.search(diccionario.get_root(), edif_buscado);
    int cant = resultado->get_data().obtener_cant_max();

    delete edif_buscado;
    return cant;
}

int Diccionario::obtener_cant_material_prod(string nombre, Constructor &bob)
{
    Edificio *edif_buscado = bob.construye(nombre);
    if (!edif_buscado)
        return false;

    BSTNode<Edificio*> *resultado = diccionario.search(diccionario.get_root(), edif_buscado);
    int cant = resultado->get_data().obtener_cant_mat_producido();

    delete edif_buscado;
    return cant;
}

string Diccionario::obtener_tipo_material_prod(string nombre, Constructor &bob)
{
    Edificio *edif_buscado = bob.construye(nombre);
    if (!edif_buscado)
        return false;

    BSTNode<Edificio*> *resultado = diccionario.search(diccionario.get_root(), edif_buscado);
    string material = resultado->get_data().obtener_mat_producido();

    delete edif_buscado;
    return material;
}

string Diccionario::obtener_codigo(string nombre, Constructor &bob)
{
    Edificio *edif_buscado = bob.construye(nombre);
    if (!edif_buscado)
        return false;

    BSTNode<Edificio*> *resultado = diccionario.search(diccionario.get_root(), edif_buscado);
    string codigo = resultado->get_data().obtener_codigo();

    delete edif_buscado;
    return codigo;
}
