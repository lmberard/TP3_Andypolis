#ifndef CANSADO_HPP
#define CANSADO_HPP

#include "objetivo.hpp"

static const int CANTIDAD_MIN_ENERGIA = 0;

class Cansado : public Objetivo
{
private:


public:
    Cansado(string objetivo, string tipo);
    ~Cansado();

    bool chequear_estado(int energia);
};



#endif 