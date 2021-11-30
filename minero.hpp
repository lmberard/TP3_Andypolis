#ifndef MINERO_HPP
#define MINERO_HPP

#include "objetivo.hpp"

class Minero : public Objetivo
{
private:


public:
    Minero(string objetivo, string tipo);
    ~Minero();

    bool chequear_estado(Lista<Ubicaciones> & edificios);
};



#endif 