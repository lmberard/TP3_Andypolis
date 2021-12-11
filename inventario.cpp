#include "inventario.hpp"


Inventario::Inventario()
{
    andycoins_contador = 0;
    bombas_usadas = 0;
    bombas_compradas = 0;
}

void Inventario::agregar_material(Material * material)
{
    materiales1.alta(material);
}

void Inventario::mostrar_inventario()
{
    cout << left << TXT_BOLD << TXT_UNDERLINE << BGND_BLUE_4
         << setw(23) << "Nombre" << '\t'
         << setw(23) << "Cantidad"
         << END_COLOR << endl;
    for (int i = 1; i < materiales1.mostrar_cantidad() + 1; i++)
    {
        cout << left
             << setw(23) << materiales1[i]->obtener_nombre() << '\t'
             << setw(23) << materiales1[i]->obtener_cantidad()
             << endl;
    }
}

bool Inventario::chequear_stock(Edificio *edificio, bool construir)
{
    int cuenta = 0;
    bool flag = 1;

    for (int j = 1; j < materiales1.mostrar_cantidad() + 1; j++)
    {
        if (materiales1[j]->obtener_nombre() == "piedra")
        {
            cuenta = materiales1[j]->obtener_cantidad() - edificio->obtener_piedra();
            if (cuenta < 0)
            {
                msjeError("No se puede construir el edificio. No hay piedra suficiente.");
                cout << TXT_LIGHT_RED_9 << "Faltan la siguiente cantidad: " << cuenta*(-1) << END_COLOR << endl;
                flag = 0;
            }
            if (construir)
                materiales1[j]->modificar_cantidad(cuenta);
        }
        if (materiales1[j]->obtener_nombre() == "madera")
        {
            cuenta = materiales1[j]->obtener_cantidad() - edificio->obtener_madera();
            if (cuenta < 0)
            {
                msjeError("No se puede construir el edificio. No hay madera suficiente.");
                cout << TXT_LIGHT_RED_9 << "Faltan la siguiente cantidad: " << cuenta*(-1) << END_COLOR << endl;
                flag = 0;
            }
            if (construir)
                materiales1[j]->modificar_cantidad(cuenta);
        }
        if (materiales1[j]->obtener_nombre() == "metal")
        {
            cuenta = materiales1[j]->obtener_cantidad() - edificio->obtener_metal();
            if (cuenta < 0)
            {
                msjeError("No se puede construir el edificio. No hay metal suficiente.");
                cout << TXT_LIGHT_RED_9 << "Faltan la siguiente cantidad: " << cuenta*(-1) << END_COLOR << endl;
                flag = 0;
            }
            if (construir)
                materiales1[j]->modificar_cantidad(cuenta);
        }
    }

    return flag;
}

void Inventario::llenar_stock(Edificio *edificio)
{
    int cuenta = 0;
    for (int j = 1; j < materiales1.mostrar_cantidad() + 1; j++)
    {
        if (materiales1[j]->obtener_nombre() == "piedra")
        {
            cuenta = materiales1[j]->obtener_cantidad() + edificio->obtener_piedra() / 2;
            materiales1[j]->modificar_cantidad(cuenta);
        }
        if (materiales1[j]->obtener_nombre() == "madera")
        {
            cuenta = materiales1[j]->obtener_cantidad() + edificio->obtener_madera() / 2;
            materiales1[j]->modificar_cantidad(cuenta);
        }
        if (materiales1[j]->obtener_nombre() == "metal")
        {
            cuenta = materiales1[j]->obtener_cantidad() + edificio->obtener_metal() / 2;
            materiales1[j]->modificar_cantidad(cuenta);
        }
    }
}

Inventario::~Inventario()
{
    for (int i = 1; i < obtener_cantidad() + 1; i++)
    {
        delete materiales1[i];
    }
}

void Inventario::recolectar(Edificio *edificio)
{
    int cuenta;
    for (int j = 1; j < materiales1.mostrar_cantidad() + 1; j++)
    {
        if (edificio->obtener_tipo_produccion() == materiales1[j]->obtener_nombre())
        {
            cuenta = materiales1[j]->obtener_cantidad() + edificio->obtener_cant_produccion();
            cout << "\t-> " << edificio->obtener_cant_produccion() << " unidades de " << materiales1[j]->obtener_nombre() << " del edificio del tipo '" << edificio->obtener_nombre() << "'" << endl;
            materiales1[j]->modificar_cantidad(cuenta);
        }
    }
}


//////////////////////////////GETTERS///////////////////////


int Inventario::obtener_andycoins_contador()
{
    return andycoins_contador;
}

//obtener bombas compradas:
int Inventario::obtener_bombas_contador()
{
    return bombas_compradas;
}

void Inventario::agregar_bombas_compradas(int cantidad)
{
    bombas_compradas += cantidad;
}

int Inventario::obtener_andycoins()
{
    return obtener_material("andycoins")->obtener_cantidad();
}

void Inventario::decrementar_bombas_contador()
{
    Material * bomba = obtener_material("bomba");
    int cantidad = bomba->obtener_cantidad();
    cantidad--;
    bomba->modificar_cantidad(cantidad);
}

void Inventario::comprar_bombas(int cantidad)
{
    Material * bomba = obtener_material("bomba");
    int aux = bomba->obtener_cantidad();
    cantidad += aux;
    obtener_material("bomba")->modificar_cantidad(cantidad);
}

int Inventario::obtener_bombas_usadas()
{
    return bombas_usadas;
}

void Inventario::aumentar_bombas_usadas()
{
    bombas_usadas++;
}

//Función de uso interna. Un PRE tendría que ser que el material_recibido esté en la lista.
Material * Inventario::obtener_material(string material_recibido){
    Material * aux = nullptr;

    for (int i = 1; i < materiales1.mostrar_cantidad() + 1; i++){
        if (materiales1[i]->obtener_nombre() == material_recibido)
            aux = materiales1[i];
    }

    return aux;
}

Lista<Material *> & Inventario::obtener_lista_de_materiales(){
    return materiales1;
}

int Inventario::obtener_cantidad()
{
    return materiales1.mostrar_cantidad();
}

string Inventario::obtener_nombre_material(int posicion)
{
    return materiales1[posicion]->obtener_nombre();
}

int Inventario::obtener_cant_material(int posicion)
{
    return materiales1[posicion]->obtener_cantidad();
}

void Inventario::modificar_cant_material(string nombre, int cantidad)
{
    for (int j = 1; j < materiales1.mostrar_cantidad() + 1; j++)
    {
        if (materiales1[j]->obtener_nombre() == nombre)
            materiales1[j]->modificar_cantidad(cantidad);
    }
}

void Inventario::aniadir_cant_material(string nombre, int cantidad)
{
    for (int j = 1; j < materiales1.mostrar_cantidad() + 1; j++)
    {
        if (materiales1[j]->obtener_nombre() == nombre){
            cantidad += materiales1[j]->obtener_cantidad();
            materiales1[j]->modificar_cantidad(cantidad);
        }
    }
}