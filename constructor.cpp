#include "constructor.hpp"

Constructor::Constructor(){}

void Constructor::agregar_edificio(string nombre, int piedra, int madera, int metal, int permitidos)
{
    if (nombre == "aserradero")
        diccionario.insertar(new Aserradero(piedra, madera, metal, permitidos), nombre);
    if (nombre == "fabrica")
        diccionario.insertar(new Fabrica(piedra, madera, metal, permitidos), nombre);
    if (nombre == "escuela")
        diccionario.insertar(new Escuela(piedra, madera, metal, permitidos), nombre);
    if (nombre == "yacimiento")
        diccionario.insertar(new Yacimiento(piedra, madera, metal, permitidos), nombre);
    if (nombre == "mina")
        diccionario.insertar(new Mina(piedra, madera, metal, permitidos), nombre);
    if (nombre == "mina oro")
        diccionario.insertar(new MinaOro(piedra, madera, metal, permitidos), nombre);
    if (nombre == "obelisco")
        diccionario.insertar(new Obelisco(piedra, madera, metal, permitidos), nombre);
    if (nombre == "planta electrica")
        diccionario.insertar(new PlantaElectrica(piedra, madera, metal, permitidos), nombre);
        
    edificios.alta(nombre);
}

Edificio *Constructor::construye(const string &edificio)
{
    Edificio *construido = NULL;

    if(!diccionario.buscar(edificio))
        return construido;
    
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

Edificio *Constructor::mostrar_edificio(int i)
{
    return diccionario.consultar(edificios[i])->obtener_dato();
}

Edificio *Constructor::mostrar_edificio(string & edificio)
{
    return diccionario.consultar(edificio)->obtener_dato();
}

int Constructor::cant_edificios()
{
    return edificios.mostrar_cantidad();
}

bool Constructor::existe(string edificio)
{
    return diccionario.buscar(edificio);
}
