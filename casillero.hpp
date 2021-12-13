#ifndef CASILLERO_HPP
#define CASILLERO_HPP

#include "colors.hpp"

#include "material.hpp"
#include "edificio.hpp"
#include "jugador.hpp"

using namespace std;

class Casillero{

protected: 

    string color;
    string casillero_nombre;
    Jugador *jugador;
    
public:
  
    Casillero();
    virtual ~Casillero();

    virtual void caracteristicas() = 0;

    virtual void info() = 0;
    virtual void mostrar_por_pantalla() = 0;

    virtual bool agregar(Edificio *);
    virtual bool agregar(Material *);
    virtual bool agregar(Jugador *) = 0;

    virtual Edificio *info_edificio();
    virtual void quitar_elemento();

    virtual int obtener_peso(int jugador_id) = 0;
    void borrar_jugador();

    //DUDA CON ESTO :/ 
    virtual bool estransitable();

    void recorrer();

    virtual void desrecorrer() = 0;
};

#endif // CASILLERO_HPP
