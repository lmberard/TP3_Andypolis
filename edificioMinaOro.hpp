#ifndef EDIFICIOMINOORO_HPP
#define EDIFICIOMINAORO_HPP
#include "edificio.hpp"

class MinaOro : public Edificio
{
private:

    string material_producido;
    int cantidad_producida;

public:

    // PRE:
    // POS:
    MinaOro();

    void caracteristicas();

    int obtener_cantidad_producida();

    string recurso_producido();
    
};

#endif // EDIFICIOMINAORO_HPP
