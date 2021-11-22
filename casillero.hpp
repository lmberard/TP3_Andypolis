#ifndef CASILLERO_HPP
#define CASILLERO_HPP

#include <iostream>
#include <string>
#include <fstream>
#include "colors.hpp"
#include "material.hpp"
#include "edificio.hpp"

using namespace std;

class Casillero{

protected: 

    string color;
    string casillero_nombre;

public:
  
    Casillero();
    virtual ~Casillero();

    virtual void info() = 0;
    virtual void mostrar_por_pantalla() = 0;

    virtual bool agregar(Edificio *);
    virtual bool agregar(Material *);

    virtual Edificio *info_edificio();
    virtual void quitar_elemento();

    //DUDA CON ESTO :/ 
    virtual bool estransitable();
};

#endif // CASILLERO_HPP
