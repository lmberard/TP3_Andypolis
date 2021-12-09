
#include <iostream>
#include "ABB.hpp"
#include "edificio.hpp"
#include <string>

#include "edificioAserradero.hpp"
#include "edificioEscuela.hpp"
#include "edificioYacimiento.hpp"
#include "edificioObelisco.hpp"
#include "edificioMina.hpp"
#include "edificioMinaOro.hpp"
#include "edificioFabrica.hpp"
#include "edificioPlantaElectrica.hpp"
using namespace std;

int main()
{
    BST<EdifPuntero> *bst = new BST<EdifPuntero>();

    EdifPuntero aserradero = new Aserradero(5, 8, 3, 2);
    /*Edificio *fabrica = new Fabrica(5, 8, 3, 2);
    Edificio *mina = new Mina(5, 8, 3, 2);
    Edificio *yacimiento = new Yacimiento(5, 8, 3, 2);
    Edificio *escuela = new Escuela(5, 8, 3, 2);*/
    // bst->insert(aserradero);
    cout << aserradero.obtener_nombre();
    /*bst->insert(fabrica);
    bst->insert(mina);
    bst->insert(escuela);
    bst->insert(yacimiento);*/

    // bst->print_in_order();

    // delete bst;
    return 0;
}