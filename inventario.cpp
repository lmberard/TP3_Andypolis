#include "inventario.hpp"
#include <iomanip>

Inventario::Inventario()
{
}

void Inventario::cargar(const string &PATH, Recurso &recurso)
{
    fstream archivo_materiales(PATH, ios::in);

    if (!archivo_materiales.is_open())
    {
        cout << "No se encontro un archivo con nombre \"" << PATH << "\", se va a crear el archivo" << endl;
        archivo_materiales.open(PATH, ios::out);
        archivo_materiales.close();
        archivo_materiales.open(PATH, ios::in);
    }

    string nombre, cantidad;
    while (archivo_materiales >> nombre)
    {
        archivo_materiales >> cantidad;
        materiales1.alta(recurso.dar_material(nombre, stoi(cantidad)));
    }
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
    ofstream archivo_materiales("materiales.txt");
    for (int i = 1; i < materiales1.mostrar_cantidad() + 1; i++)
    {
        archivo_materiales << materiales1[i]->obtener_nombre() << ' ' << materiales1[i]->obtener_cantidad() << '\n';
        delete materiales1[i];
    }
}

void Inventario::recolectar(Edificio * edificio){
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