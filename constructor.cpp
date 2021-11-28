#include "constructor.hpp"

Constructor::Constructor(){}

void Constructor::agregar_edificio(string nombre, int piedra, int madera, int metal, int permitidos)
{
    if (nombre == "aserradero")
        edificios.alta(new Aserradero(piedra, madera, metal, permitidos));
    if (nombre == "fabrica")
        edificios.alta(new Fabrica(piedra, madera, metal, permitidos));
    if (nombre == "escuela")
        edificios.alta(new Escuela(piedra, madera, metal, permitidos));
    if (nombre == "yacimiento")
        edificios.alta(new Yacimiento(piedra, madera, metal, permitidos));
    if (nombre == "mina")
        edificios.alta(new Mina(piedra, madera, metal, permitidos));
    if (nombre == "obelisco")
        edificios.alta(new Obelisco(piedra, madera, metal, permitidos));
    if (nombre == "planta")
        edificios.alta(new PlantaElectrica(piedra, madera, metal, permitidos));
}

Edificio *Constructor::construye(const string &edificio)
{

    Edificio *construido = NULL;
    int pos = buscar_edificio(edificio);

    if (pos > edificios.mostrar_cantidad())
        return construido;

    if (edificio == "yacimiento")
        construido = new Yacimiento(edificios[pos]);
    if (edificio == "aserradero")
        construido = new Aserradero(edificios[pos]);
    if (edificio == "escuela")
        construido = new Escuela(edificios[pos]);
    if (edificio == "fabrica")
        construido = new Fabrica(edificios[pos]);
    if (edificio == "mina")
        construido = new Mina(edificios[pos]);
    if (edificio == "obelisco")
        construido = new Obelisco(edificios[pos]);
    if (edificio == "planta electrica")
        construido = new PlantaElectrica(edificios[pos]);

    return construido;
}

int Constructor::buscar_edificio(string edificio)
{
    int pos = 1;
    int cantidad = edificios.mostrar_cantidad();

    while (cantidad && (edificios[pos]->obtener_nombre() != edificio))
    {
        pos++;
        --cantidad;
    }

    return pos;
}

Edificio *Constructor::mostrar_edificio(int i)
{
    return edificios[i];
}

int Constructor::cant_edificios()
{
    return edificios.mostrar_cantidad();
}

Constructor::~Constructor()
{
    for (int i = 1; i < edificios.mostrar_cantidad() + 1; i++)
    {
        delete edificios[i];
    }
}
