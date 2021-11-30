#ifndef CONSTRUCTOR_O_HPP
#define CONSTRUCTOR_O_HPP

#include "objetivo.hpp"

class ConstructorO : public Objetivo
{
private:


public:
    ConstructorO(string objetivo, string tipo);
    ~ConstructorO();

    bool chequear_estado(Lista<Ubicaciones> & edificios);
};



#endif 