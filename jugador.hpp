#ifndef JUGADOR_HPP
#define JUGADOR_HPP
#include <iostream>
#include <string>
#include <algorithm>
#include <fstream>
#include <cstdlib>
#include <iomanip>
#include <cctype>
#include "colors.hpp"
#include "lista.hpp"
#include "ubicaciones.hpp"
#include "constructor.hpp"
#include "inventario.hpp"
#include "recurso.hpp"
#include "terreno.hpp"
#include "objetivo.hpp"

class Jugador
{
private:
    int id;                     //si es jugador 1, va el 1
    Lista<Ubicacion> edificios; //ubicaciones de los edificios construidos por este jugador
    Inventario inventario;      //lista de materiales de este jugador
    int x;                      //coordenada x del jugador
    int y;                      //coordenada y del jugador
    int puntos_energia;
    Lista<Objetivo> objetivos;

public:
    //-----------------CONSTRUCTORES DESTRUCTORES----------------------------
    Jugador(int _id, int puntos_iniciales);
    Jugador();
    ~Jugador();

    //-------------------------GETTERS---------------------------------------
    int obtener_id();
    int obtener_puntos_energia();
    int obtener_cant_andycoins();
    int obtener_cant_bombas();

    //-------------------------SETTERS---------------------------------------
    void setear_objetivos_secundarios();
    void setear_objetivo_principal();
    void setear_id(int _id);

    //--------------------------PARA PARSER----------------------------------
    void agregar_material_al_inventario(string nombre, int cantidad, Recurso &recurso); //materiales.txt
    void agregar_ubicacion_lista_edificios(Ubicacion ubicacion);                        //ubicaciones.txt

    //------------------------MODIFICADORES----------------------------------
    void modificar_puntos_energia(int cantidad);
    void modificar_andypoints(int cantidad);

    void modificar_cant_material(string nombre_material, int cantidad);
    void eliminar_ubicacion_edificio(Ubicacion ubicacion);

    //------------------------FUNCIONES UTILES-------------------------------
    bool se_quedo_sin_energia();
    bool es_su_edificio(Ubicacion ubicacion);
    bool cantidad_suficiente_material(Edificio *edificio, bool construir);

    //------------------------OPCIONES JUGADOR-------------------------------
    void moverse_a_coordenada(int x, int y);
    void mostrar_inventario();
<<<<<<< HEAD

/*
    bool chequear_objetivos(Lista<Objetivo> objetivos){
        if(obj.getobjetivo == "Construir Obelisco")
            obj.chequear_estado()
    }*/
=======
    void mostrar_objetivos_y_progreso();
>>>>>>> 907979593a0205da5274f9102aa2bf889964cc21
};
#endif //JUGADOR_HPP
