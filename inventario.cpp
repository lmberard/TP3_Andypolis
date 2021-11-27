#include "inventario.hpp"
#include <iomanip>

Inventario::Inventario()
{
    andycoins_contador = 0;
    bombas_usadas = 0;
}

void Inventario::agregar_material(string nombre, int cantidad, Recurso &recurso)
{
    materiales1.alta(recurso.dar_material(nombre, cantidad));
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
                cout << "falta " << materiales1[j]->obtener_nombre() << endl;
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
                cout << "falta " << materiales1[j]->obtener_nombre() << endl;
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
                cout << "falta " << materiales1[j]->obtener_nombre() << endl;
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
        if (edificio->obtener_mat_producido() == materiales1[j]->obtener_nombre())
        {
            cuenta = materiales1[j]->obtener_cantidad() + edificio->obtener_cant_mat_producido();
            cout << "\t-> " << edificio->obtener_cant_mat_producido() << " unidades de " << materiales1[j]->obtener_nombre() << " del edificio del tipo '" << edificio->obtener_nombre() << "'" << endl;
            materiales1[j]->modificar_cantidad(cuenta);
        }
    }
}


//////////////////////////////GETTERS///////////////////////


int Inventario::obtener_andycoins_contador()
{
    return andycoins_contador;
}

int Inventario::obtener_bombas_usadas()
{
    return bombas_usadas;
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