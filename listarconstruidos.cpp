#include "listarconstruidos.hpp"

void ListarConstruidos::jugar(Constructor & bob, Mapa & mapa, int & turno, Jugador * jugador, int & id_jugador_actual)
{    
    Lista<Ubicaciones> edificios = jugador[id_jugador_actual - 1].lista_edificios();
    Coordenada coordenada;
    Edificio * edificio;
    int vida;
            
    for (int i = 1; i < edificios.mostrar_cantidad() + 1; i++){   
        cout << "Tipo de edificio: " << edificios[i].nombre << endl;
        cout << "Cantidad: " << obtener_cantidad(edificios[i]) << endl;
        vida = bob.mostrar_edificio(edificios[i].nombre)->obtener_vida();
        for(int j = 1; j < obtener_cantidad(edificios[i]) + 1; j++){
            coordenada = edificios[i].coordenadas[j];
            edificio = mapa.obtener_edificio(coordenada);
            cout << "\t->(" << coordenada.coord_x << ", " << coordenada.coord_y << ") " << " ";
            if(vida - edificio->obtener_vida())
                cout << "necesita reparacion" << endl;
            else
                cout << "no necesita ser reparado" << endl; 
        }
    }
}