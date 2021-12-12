#include "grafo.hpp"

#include "coordenada.hpp"
#include "lista.hpp"
#include "listaNG.hpp"

int main()
{
    //A -> 3 B -> 7 C
    //5      2      5
    //D -> 1 E -> 1 F

    // 1) cargar coordenadas:
    coordenada A; A.coord_x = 0; A.coord_y = 0;
    coordenada B; B.coord_x = 0; B.coord_y = 1;
    coordenada C; C.coord_x = 0; C.coord_y = 2;
    coordenada D; D.coord_x = 1; D.coord_y = 0;
    coordenada E; E.coord_x = 1; E.coord_y = 1;
    coordenada F; F.coord_x = 1; F.coord_y = 2;

    Grafo grafo;
    
    ListaNG<coordenada> coordenadas;
    int energia;

    grafo.agregarVertice(A);
    grafo.agregarVertice(B);
    grafo.agregarVertice(C);
    grafo.agregarVertice(D);
    grafo.agregarVertice(E);
    grafo.agregarVertice(F);

    // 2) agregar los pesos iterando (lo mas paja)
    grafo.agregarCamino(A, B, 3);
    grafo.agregarCamino(B, C, 7);
    grafo.agregarCamino(A, D, 5);
    grafo.agregarCamino(B, E, 2);
    grafo.agregarCamino(D, E, 1);
    grafo.agregarCamino(E, F, 1);
    grafo.agregarCamino(F, C, 5);
    
    //grafo.agregarCamino(F, G, 5);
    //grafo.mostrarGrafo();

    // 3) pedirle al usuario a donde se quiere mover: 
    grafo.usarDijkstra();
    grafo.caminoMinimo(D, C, energia, coordenadas);
    
    // 4) agarrar los materiales del camino restarle la energía al jugador
    cout << " a ver la energía " << energia << endl;
    for(int i = 1; i < coordenadas.mostrar_cantidad() + 1; i++)
        cout << "(" << coordenadas[i].coord_x << " " << coordenadas[i].coord_y << ")" << endl;

    return 0;
}
