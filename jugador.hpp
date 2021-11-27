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
#include "superficie.hpp"
#include "objetivo.hpp"

class Jugador
{
private:
    int id;                       //si es jugador 1, va el 1
    Lista<Ubicaciones> edificios; //ubicaciones de los edificios construidos por este jugador
    Inventario inventario;        //lista de materiales de este jugador
    Coordenada posicion_jugador;

    int puntos_energia;
    Lista<Objetivo> objetivos;

public:
    //-----------------CONSTRUCTORES DESTRUCTORES----------------------------
    Jugador(int _id, int puntos_iniciales);
    Jugador();
    ~Jugador();

    //-------------------------GETTERS---------------------------------------
    int obtener_id();
    Coordenada obtener_posicion_jugador(); //YO
    int obtener_puntos_energia();
    int obtener_cant_andycoins();
    int obtener_cant_bombas();
    int obtener_cant_edificios_construidos(string nombre);
    int obtener_tam_lista_ubicaciones();

    //-------------------------SETTERS---------------------------------------
    void setear_objetivos_secundarios();
    void setear_objetivo_principal();
    void setear_id(int _id);
    void setear_posicion(Coordenada coord);

    //--------------------------PARA PARSER----------------------------------
    void agregar_material_al_inventario(string nombre, int cantidad, Recurso &recurso);    //materiales.txt
    void agregar_ubicacion_lista_edificios(string nombre, Coordenada coordenada_edificio); //ubicaciones.txt

    //------------------------MODIFICADORES----------------------------------
    void modificar_puntos_energia(int cantidad);
    void modificar_andypoints(int cantidad);

    void modificar_cant_material(string nombre_material, int cantidad);
    bool eliminar_ubicacion_edificio(string nombre, Coordenada coordenada);
    void agregar_materiales_reciclados(Edificio *edificio);

    //------------------------FUNCIONES UTILES-------------------------------
    bool se_quedo_sin_energia();
    bool es_su_edificio(string nombre, Coordenada coordenada);
    bool cantidad_suficiente_material(Edificio *edificio, bool construir);
    bool tiene_energia(int cantidad_necesaria);

    //------------------------OPCIONES JUGADOR-------------------------------
    void moverse_a_coordenada(int x, int y);
    void mostrar_inventario();
    void mostrar_lista_de_edificios(); //YO
    void mostrar_edificios_construidos();
    void mostrar_objetivos_y_progreso();

    /*
    bool chequear_objetivos(Lista<Objetivo> objetivos){
        if(obj.getobjetivo == "Construir Obelisco")
            obj.chequear_estado()
    }*/
};
#endif //JUGADOR_HPP