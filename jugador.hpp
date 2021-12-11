#ifndef JUGADOR_HPP
#define JUGADOR_HPP

#include "lista.hpp"
#include "ubicaciones.hpp"
#include "inventario.hpp"
#include "objetivo.hpp"
#include "comprarAndypolis.hpp"
#include "edadDePiedra.hpp"
#include "bombardero.hpp"
#include "energetico.hpp"
#include "letrado.hpp"
#include "minero.hpp"
#include "cansado.hpp"
#include "constructorO.hpp"
#include "armado.hpp"
#include "extremista.hpp"

class Jugador
{
private:
    
    string codigo;
    Lista<Objetivo*> objetivos;

    Inventario inventario;        //lista de materiales de este jugador
    int puntos_energia;
    
    bool fobia_al_agua;
    bool odio_al_muelle;

    //QUE ESTA LISTA SEA UN ATRIBUTO DE JUGADOR NO SE SI ESTA TAAAN BIEN, PERO YA FUE 
    Lista<Ubicaciones> edificios; //ubicaciones de los edificios construidos por este jugador
    
    //ESTOS ATRIBUTOS NO VAN MAS:
    //Coordenada posicion_jugador;
    //int id;                       //si es jugador 1, va el 1

public:
    //-----------------CONSTRUCTORES DESTRUCTORES----------------------------
    Jugador();
    ~Jugador();
    //-------------------------GETTERS---------------------------------------
    //Coordenada obtener_posicion_jugador(); 
    Lista<Ubicaciones> & lista_edificios();
    int obtener_energia();

    //esta capaz es util para objetivos tipo "letrado", pero no va aca:
    int obtener_cant_edificios_construidos(string nombre);
    string obtener_codigo();
    //-------------------------SETTERS---------------------------------------
    /*funciones que se utilizan para parser o bien entrada por consola*/
    void setear_jugador(int id);
    //void setear_posicion(Coordenada coord);
    void agregar_material_al_inventario(Material * material);    //materiales.txt
    void agregar_ubicacion_lista_edificios(string nombre, Coordenada coordenada_edificio); //ubicaciones.txt
    bool eliminar_ubicacion_lista_edificios(string nombre, Coordenada coordenada_edificio);

    //------------------------MODIFICADORES----------------------------------
    void modificar_puntos_energia(int cantidad);
    void decrementar_puntos_energia(int cantidad);

    void modificar_cant_material(string nombre_material, int cantidad);
    bool eliminar_ubicacion_edificio(string nombre, Coordenada coordenada);
    void agregar_materiales_reciclados(Edificio *edificio);

    //------------------------FUNCIONES UTILES-------------------------------
    bool se_quedo_sin_energia();
    bool es_su_edificio(string nombre, Coordenada coordenada);
    bool cantidad_suficiente_material(Edificio *edificio, bool construir);
    bool tiene_energia(int cantidad_necesaria);
    void asignar_objetivos_jugador(Objetivo * objetivo);
    bool tiene_edificio_por_coordenada(Coordenada coordenadas, string & edificio_a_demoler);

    //------------------------OPCIONES JUGADOR-------------------------------
    void moverse_a_coordenada(int x, int y);
    void mostrar_inventario();
    //void mostrar_lista_de_edificios(); //YO
    void mostrar_edificios_construidos();
    void mostrar_objetivos_y_progreso();
    Inventario & inv(){return inventario;}

    void chequear_objetivos(bool fin_turno, Constructor & bob);

    bool gano();

};
#endif //JUGADOR_HPP