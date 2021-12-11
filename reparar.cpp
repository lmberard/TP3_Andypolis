#include "reparar.hpp"

void Reparar::jugar(Constructor & bob, Mapa & mapa, int & turno, Jugador * jugadores, int & id_jugador_actual){
    Coordenada coordenadas;
    Edificio * edif_ptr;
    string edificio_a_reparar;

    if(jugadores[id_jugador_actual - 1].obtener_energia() >= ENERGIA_NECESARIA_PARA_REPARAR){
        coordenadas = pedir_coordenadas();
        if(mapa.coordenadas_validas(coordenadas)){
            if(mapa.obtener_edificio(coordenadas) != NULL){
                if(jugadores[id_jugador_actual - 1].tiene_edificio_por_coordenada(coordenadas, edificio_a_reparar) == true){
                    edif_ptr = mapa.obtener_edificio(coordenadas);
                    if(chequear_si_requiere_reparacion(edif_ptr)){;
                        if(chequear_materiales_reparacion(edif_ptr, jugadores[id_jugador_actual - 1])){
                            edif_ptr->subir_vida();
                            imprimir_edificio_reparado(edif_ptr);
                            descontar_materiales(edif_ptr, jugadores[id_jugador_actual - 1]);
                            jugadores[id_jugador_actual - 1].decrementar_puntos_energia(ENERGIA_NECESARIA_PARA_REPARAR);
                        }
                    }
                } else {msjeError("El edificio seleccionado no le pertenece.");}
            } else{msjeError("El casillero seleccionado no contiene un edificio construido.");}
        }
    }

    bool fin_turno = false;
    jugadores[id_jugador_actual-1].chequear_objetivos(fin_turno,bob);
    
}

bool Reparar::chequear_si_requiere_reparacion(Edificio * edif_ptr){
    string nombre_edificio = edif_ptr->obtener_nombre();
    int vida_edificio = edif_ptr->obtener_vida();
    bool requiere_reparacion = false;

    if(nombre_edificio == "fabrica" || nombre_edificio == "mina"){
        if(vida_edificio == 1)
            requiere_reparacion = true;
        else
            msjeError("El edificio no requiere ser reparado.");
    }
    else
        msjeError("El edificio no requiere ser reparado.");

    return requiere_reparacion;
}

bool Reparar::chequear_materiales_reparacion(Edificio * edif_ptr, Jugador & jugador){
    return jugador.inv().chequear_stock_reparaciones(edif_ptr, false);
}

void Reparar::imprimir_edificio_reparado(Edificio * edif_ptr){
    cout << TXT_LIGHT_GREEN_46 << "Se ha reparado satisfactoriamente el edificio: " 
    << edif_ptr->obtener_nombre() << END_COLOR << endl;
}

bool Reparar::descontar_materiales(Edificio * edif_ptr, Jugador & jugador){
    return jugador.inv().chequear_stock_reparaciones(edif_ptr, true);
}
