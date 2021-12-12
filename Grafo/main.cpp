#include "grafo.hpp"

#include "coordenada.hpp"

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
    coordenada G; G.coord_x = 3; G.coord_y = 0;

    Grafo grafo;

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
    grafo.caminoMinimo(A, F);

    // 4) agarrar los materiales del camino restarle la energía al jugador
    
    return 0;
}
