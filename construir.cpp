#include "construir.hpp"

void Construir::jugar(Constructor &bob, Mapa &mapa, int &turno, Jugador *jugadores, int &id_jugador_actual)
{
    Coordenada coordenadas;
    Edificio *edif_ptr;
    string edificio;

    if (jugadores[id_jugador_actual - 1].obtener_energia() >= ENERGIA_NECESARIA_PARA_CONSTRUIR)
    {
        edificio = pedir_edificio();
        if (chequear_existencia_de_edificio(bob, edificio))
        {
            edif_ptr = bob.mostrar_edificio(edificio);
            if (chequear_edificios_disponibles(edif_ptr, jugadores[id_jugador_actual - 1]))
            {
                if (chequear_requerimientos_edificio(edif_ptr, jugadores[id_jugador_actual - 1]))
                {
                    coordenadas = pedir_coordenadas();
                    if (mapa.coordenadas_validas(coordenadas))
                    {
                        if (pedir_confirmacion() == OPCION_DE_CONFIRMACION)
                        {
                            if (mapa.agregar_contenido(coordenadas, bob.construye(edif_ptr->obtener_nombre())))
                            {
                                imprimir_edificio_construido(edif_ptr);
                                descontar_materiales(edif_ptr, jugadores[id_jugador_actual - 1]);
                                jugadores[id_jugador_actual - 1].agregar_ubicacion_lista_edificios(edif_ptr->obtener_nombre(), coordenadas);
                                jugadores[id_jugador_actual - 1].decrementar_puntos_energia(ENERGIA_NECESARIA_PARA_CONSTRUIR);
                            }
                        }
                    }
                }
            }
        }
    }

    bool fin_turno = false;
    jugadores[id_jugador_actual - 1].chequear_objetivos(fin_turno, bob);
}

bool Construir::chequear_existencia_de_edificio(Constructor &bob, string edificio)
{
    bool estado = true;

    if (!bob.existe(edificio))
    {
        msjeError("No se puede construir el edificio. El edificio que desea construir no existe en Andypolis.");
        estado = false;
    }
    return estado;
}

bool Construir::chequear_edificios_disponibles(Edificio *edif_ptr, Jugador &jugador)
{
    bool estado = true;
    int cantidad_construidos;

    cantidad_construidos = jugador.obtener_cant_edificios_construidos(edif_ptr->obtener_nombre());
    if (cantidad_construidos >= edif_ptr->obtener_cant_max())
    {
        msjeError("No se puede construir el edificio. No quedan edificios disponibles por construir.");
        estado = false;
    }

    return estado;
}

bool Construir::chequear_requerimientos_edificio(Edificio *edif_ptr, Jugador &jugador)
{
    return jugador.inv().chequear_stock(edif_ptr, false);
}

bool Construir::descontar_materiales(Edificio *edif_ptr, Jugador &jugador)
{
    return jugador.inv().chequear_stock(edif_ptr, true);
}

void Construir::imprimir_edificio_construido(Edificio *edif_ptr)
{
    cout << TXT_LIGHT_GREEN_46 << "Se ha construido satisfactoriamente una unidad del edificio: "
         << edif_ptr->obtener_nombre() << END_COLOR << endl;
}
