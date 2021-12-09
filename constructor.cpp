#include "constructor.hpp"

Constructor::Constructor(){}

void Constructor::agregar_edificio(string nombre, int piedra, int madera, int metal, int permitidos)
{
    if (nombre == "aserradero"){
        diccionario.insertar(new Aserradero(piedra, madera, metal, permitidos), "aserradero");
        //edificios.alta(new Aserradero(piedra, madera, metal, permitidos));
    }
    if (nombre == "fabrica"){
        diccionario.insertar(new Fabrica(piedra, madera, metal, permitidos), "fabrica");
        //edificios.alta(new Fabrica(piedra, madera, metal, permitidos));
    }
    if (nombre == "escuela"){
        diccionario.insertar(new Escuela(piedra, madera, metal, permitidos), "escuela");
        //edificios.alta(new Escuela(piedra, madera, metal, permitidos));
    }
    if (nombre == "yacimiento"){
        diccionario.insertar(new Yacimiento(piedra, madera, metal, permitidos), "yacimiento");
        //edificios.alta(new Yacimiento(piedra, madera, metal, permitidos));
    }
    if (nombre == "mina"){
        diccionario.insertar(new Mina(piedra, madera, metal, permitidos), "mina");
        //edificios.alta(new Mina(piedra, madera, metal, permitidos));
    }
    if (nombre == "mina oro"){
        diccionario.insertar(new MinaOro(piedra, madera, metal, permitidos), "mina oro");
        //edificios.alta(new MinaOro(piedra, madera, metal, permitidos));
    }
    if (nombre == "obelisco"){
        diccionario.insertar(new Obelisco(piedra, madera, metal, permitidos), "obelisco");
        //edificios.alta(new Obelisco(piedra, madera, metal, permitidos));
    }
    if (nombre == "planta electrica"){
        diccionario.insertar(new PlantaElectrica(piedra, madera, metal, permitidos), "planta electrica");
        //edificios.alta(new PlantaElectrica(piedra, madera, metal, permitidos));
    }
        
}

Edificio *Constructor::construye(const string &edificio)
{
    Edificio *construido = NULL;
    //int pos = buscar_edificio(edificio);

    /*if (pos > edificios.mostrar_cantidad())
        return construido;*/
    
    if (edificio == "aserradero")
        construido = new Aserradero(diccionario.consultar(edificio)->obtener_dato());
    if (edificio == "escuela")
        construido = new Escuela(diccionario.consultar(edificio)->obtener_dato());
    if (edificio == "fabrica")
        construido = new Fabrica(diccionario.consultar(edificio)->obtener_dato());
    if (edificio == "mina")
        construido = new Mina(diccionario.consultar(edificio)->obtener_dato());
    if (edificio == "mina oro")
        construido = new Mina(diccionario.consultar(edificio)->obtener_dato());
    if (edificio == "obelisco")
        construido = new Obelisco(diccionario.consultar(edificio)->obtener_dato());
    if (edificio == "planta electrica")
        construido = new PlantaElectrica(diccionario.consultar(edificio)->obtener_dato());
    if (edificio == "yacimiento")
        construido = new Yacimiento(diccionario.consultar(edificio)->obtener_dato());
    
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
