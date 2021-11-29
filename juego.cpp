#include "juego.hpp"
//--------------------CONSTRUCTORES DESTRUCTORES-------------------
Juego::Juego()
{   
    //carga los datos de los edificios en el diccionario del constructor
    archivo.cargar(bob);
    
    //crea la superficie del mapa 
    archivo.cargar(superficie,mapa);

    //carga el inventario de cada jugador 
    archivo.cargar(recurso,jugadores);

    //carga una partida guardada 
    if(archivo.cargar_partida_guardada(mapa,bob,recurso,jugadores,CANT_JUGADORES))
        partida_nueva = true;
}

Juego::~Juego()
{
}

//--------------------------GETTERS--------------------------------
int Juego::obtener_filas_mapa()
{
    return mapa.obtener_filas();
}

int Juego::obtener_columnas_mapa()
{
    return mapa.obtener_columnas();
}

Jugador& Juego::obtener_jugador_1()
{    
    return jugadores[0];
} //YO

Jugador& Juego::obtener_jugador_2()
{    
    return jugadores[1];
} //YO

Jugador* Juego::obtener_jugador()
{
    return jugadores;
}

int Juego::obtener_cant_construidos(string nombre_edificio)
{
    int suma = 0;
    for (int i = 0; i < CANT_JUGADORES; i++)
        suma += jugadores[i].obtener_cant_edificios_construidos(nombre_edificio);

    return suma;
}

int Juego::obtener_id_jugador_actual()
{
    return id_jugador_actual;
}

bool Juego::es_partida_nueva()
{
    return partida_nueva;
}

//--------------------------SETTERS--------------------------------
void Juego::setear_coordenada_jugador(int id_jugador)
{
    msjeInstruccion("Jugador " + to_string(id_jugador) + ", donde quiere empezar el juego?");
    Coordenada coord_jugador = pedir_coordenadas();
    //esto deberia ser un loop para que te siga pidiendo
    if (mapa.coordenadas_validas(coord_jugador))
        jugadores[id_jugador - 1].setear_posicion(coord_jugador);
}

void Juego::setear_id_jugador_actual(int id_jugador)
{
    id_jugador_actual = id_jugador;
}

void Juego::setear_estado_partida(bool flag)
{
    partida_nueva = flag;
}

//----------------------------MAPA---------------------------------
void Juego::crear_mapa(int filas, int columnas)
{
    mapa.crear_memoria_mapa(filas, columnas);
}

void Juego::agregar_casillero(Coordenada coord, string casillero)
{
    mapa.agregar_casillero(coord, casillero, superficie);
}

//FALTAN DETALLES
void Juego::construir_edificio(Coordenada coord, const string &eledificio)
{
    if (mapa.coordenadas_validas(coord))
    {
        if (!mapa.obtener_edificio(coord))
        {
            Edificio *edificio = bob.construye(eledificio);
            if (jugadores[id_jugador_actual - 1].cantidad_suficiente_material(edificio, true))
            {
                string rta;
                msjeInstruccion("Desea confirmar la construccion?(si/no)");
                cin >> rta;
                if (rta == "si")
                {
                    if (mapa.agregar_contenido(coord, edificio))
                    {
                        jugadores[id_jugador_actual - 1].agregar_ubicacion_lista_edificios(eledificio, coord);
                        // descontar materiales de cosntruccion al jugador de su inventario
                        msjeOK("Se restaron los materiales de construccion, se construyo el edificio y se agrego a la lista de ubicaciones");
                    }
                }
                else if (rta == "no")
                {
                    msjeInstruccion("No se construyo el edificio.");
                    delete edificio;
                }
                else
                    msjeError("Opcion invalida. Ingrese 'si' o 'no'");
            }
            else
            {
                msjeError("No hay materiales suficientes para la construccion de ese edificio :(");
                delete edificio;
            }
        }
        else
            msjeError("Ya hay un edificio en esa coordenada");
    }
}

void Juego::agregar_material_coordenada_lista(string nombre, Coordenada coord)
{
    mapa.agregar_ubicacion_material_lista(nombre, coord);
} //YO

void Juego::agregar_material_coordenada(string nombre, Coordenada coord)
{
    mapa.agregar_contenido(coord, recurso.dar_material(nombre));
}
//-------------------OPCIONES MENU PRINCIPAL-----------------------
//FALTAA (hacer diccionario)
void Juego::modificar_edificio_por_nombre()
{
    string nombre_edificio = pedir_nombre_edificio();
    /*---verificar que exista el nombre---*/
    //diccionario.nombre_es_valido(nombre_edificio);

    /*---pedirle al usuario---*/
    //string madera,piedra, metal, permitidos;
    //pedir_datos_para_modificar(&madera, &piedra, &metal, &permitidos);

    /*---modificar en el diccionario---*/
    //diccionario.modificar(nombre_edificio,madera, piedra, madera, metal, permitidos)
    cout << "falta" << endl;
}

void Juego::mostrar_todos_edificios()
{
    int cant_edificios = bob.cant_edificios();
    int cant_construidos = 0, cant_disponible = 0;
    Edificio *edificio;

    cout << left << TXT_BOLD << TXT_UNDERLINE << BGND_BLUE_4
         << setw(23) << "Nombre" << '\t'
         << setw(23) << "Cant de madera" << '\t'
         << setw(23) << "Cant de metal" << '\t'
         << setw(23) << "Cant de piedra" << '\t'
         << setw(23) << "Cant construida" << '\t'
         << setw(23) << "Cant disponible para construir" << '\t'
         << setw(23) << "Tipo de material que produce" << '\t'
         << setw(23) << "Cant de produccion"
         << END_COLOR << endl;
    for (int i = 1; i < cant_edificios + 1; i++)
    {
        edificio = bob.mostrar_edificio(i);
        cant_construidos = obtener_cant_construidos(edificio->obtener_nombre());
        cant_disponible = edificio->obtener_cant_max() - cant_construidos;

        cout << left
             << setw(23) << edificio->obtener_nombre() << '\t'
             << setw(23) << edificio->obtener_madera() << '\t'
             << setw(23) << edificio->obtener_metal() << '\t'
             << setw(23) << edificio->obtener_piedra() << '\t'
             << setw(23) << cant_construidos << '\t'
             << setw(23) << cant_disponible << '\t'
             << setw(23) << edificio->obtener_mat_producido() << '\t'
             << setw(23) << edificio->obtener_cant_mat_producido()
             << endl;
    }
}

void Juego::mostrar_mapa()
{
    mapa.mostrar();
}

//detalles de interfaz(loops que sigan pidiendo cosas en vez de que te lo corte)
bool Juego::comenzar_partida()
{
    id_jugador_actual = pedir_id_jugador();
    if (id_jugador_es_valido(id_jugador_actual))
    {
        setear_coordenada_jugador(id_jugador_actual);

        for (int i = 0; i < CANT_JUGADORES; i++)
        {
            if ((id_jugador_actual - 1) != i)
                setear_coordenada_jugador(i + 1);
        }
        return true;
    }
    else
    {
        msjeInstruccion("Intente de nuevo!");
        return false;
    }
}

//-----------------------OPCIONES JUEGO----------------------------
void Juego::construir_por_nombre_coordenada()
{
    if (jugador_tiene_energia(CANT_ENERGIA_CONSTRUIR))
    {
        string nombre_edificio = pedir_nombre_edificio();

        if (chequear_permisos_edificio(nombre_edificio))
        {
            Coordenada coord = pedir_coordenadas();
            construir_edificio(coord, nombre_edificio);
        }
        jugadores[id_jugador_actual - 1].modificar_puntos_energia(-CANT_ENERGIA_CONSTRUIR);
    }
}

void Juego::mostrar_edificios_construidos()
{
    //if (jugador_tiene_energia(CANT_ENERGIA_LISTAR_EDIF))
    //{
        //if (id_jugador_es_valido(id_jugador_actual))
            jugadores[id_jugador_actual - 1].mostrar_edificios_construidos();
    //}
}

void Juego::demoler_por_coordenada()
{
    if (jugador_tiene_energia(CANT_ENERGIA_DEMOLER))
    {
        Coordenada coord = pedir_coordenadas();
        demoler_edificio(coord);
    }
}

//FALTAA
void Juego::atacar_por_coordenada()
{
    if (jugador_tiene_energia(CANT_ENERGIA_ATACAR))
    {
        cout << "falta" << endl;
    }
}

//FALTAA
void Juego::reparar_por_coordenada()
{
    if (jugador_tiene_energia(CANT_ENERGIA_REPARAR))
    {
        cout << "falta" << endl;
    }
}

void Juego::comprar_bombas()
{
    if (jugador_tiene_energia(CANT_ENERGIA_COMPRAR_BOMBAS))
    {
        cout << "falta" << endl;
    }
}

void Juego::consultar_coordenada()
{
    if (jugador_tiene_energia(CANT_ENERGIA_CONSULTAR))
    {
        Coordenada coord = pedir_coordenadas();
        if (mapa.coordenadas_validas(coord))
        {
            msjeInstruccion("Hola, estas en la posicion (" + to_string(coord.coord_x) + ", " + to_string(coord.coord_y) + ")");
            mapa.consultar_coordenada(coord);
        }
    }
}

void Juego::mostrar_objetivos()
{
    if (jugador_tiene_energia(CANT_ENERGIA_MOSTRAR_OBJ))
    {
        cout << "falta" << endl;
    }
}

void Juego::mostrar_inventario()
{
    if (jugador_tiene_energia(CANT_ENERGIA_MOSTRAR_INV))
    {
        if (id_jugador_es_valido(id_jugador_actual))
            jugadores[id_jugador_actual - 1].mostrar_inventario();
    }
}

//FALTAN COSAS
void Juego::recolectar()
{
    if (jugador_tiene_energia(CANT_ENERGIA_RECOLECTAR))
    {
        cout << "falta" << endl;
    }
    /*
    Edificio *edificio;
    msjeOK("Se recolectaron los siguientes materiales:");
    for (int i = 0; i < CANT_JUGADORES + 1; i++)
    {
        int tam_lista_ubicaciones = jugadores[i].obtener_tam_lista_ubicaciones();
        for (int j = 1; j < tam_lista_ubicaciones + 1; j++)
        {
            //verificar si es un edificio que da materiales
            //contar la cantidad de cada uno de los edificios construidos
            //multiplicar ese valor por la cantidad de materiales que de 
            //guardar ese valor en el inventario del jugador 
        }
    }
    msjeOK("Se guardaron los materiales en la lista de materiales. Pueden ser usados para construir nuevos edificios :)");
*/
}

void Juego::moverse_a_coordenada()
{
    if (id_jugador_es_valido(id_jugador_actual))
    {
        Coordenada coord = pedir_coordenadas();
        jugadores[id_jugador_actual - 1].moverse_a_coordenada(coord.coord_x, coord.coord_y);
    }
}

//FALTAA
void Juego::finalizar_turno()
{
    cout << "falta" << endl;
}

//FALTAA
void Juego::lluvia()
{
    cout << "falta la lluvia" << endl;
}

bool Juego::gano_el_juego()
{
    cout << "falta" << endl;
    return false;
}

void Juego::cambiar_jugador()
{
    if (id_jugador_actual == 1)
        id_jugador_actual = 2;
    else if (id_jugador_actual == 2)
        id_jugador_actual = 1;
}
//-----------------------FUNCIONES UTILES--------------------------
bool Juego::id_jugador_es_valido(int id_jugador)
{
    if (id_jugador < 1 || id_jugador > CANT_JUGADORES)
    {
        msjeError("No existe ese numero de jugador");
        return false;
    }
    else
        return true;
}

bool Juego::chequear_permisos_edificio(const string &eledificio)
{
    Edificio *edificio = bob.construye(eledificio);
    int flag = 1;
    if (edificio)
    {
        int cant_construidos = jugadores[id_jugador_actual - 1].obtener_cant_edificios_construidos(eledificio);
        if (edificio->obtener_cant_max() > cant_construidos)
        {
            msjeOK("y todavia hay capacidad para construir edificios de ese estilo!");
            flag = 1;
        }
        else
        {
            flag = 0;
            msjeError("Ya no se pueden construir mas edificios de ese estilo. Llegamos al maximo :(");
        }
    }
    else
    {
        msjeError("No existe ese tipo de edificio. Intente con otro nombre");
        flag = 0;
    }
    return flag;
}

bool Juego::jugador_tiene_energia(const int cantidad)
{
    if (!(jugadores[id_jugador_actual - 1].tiene_energia(CANT_ENERGIA_CONSTRUIR)))
    {
        msjeError("No se tiene energia suficiente para esa opcion");
        return false;
    }
    else
        return true;
}

Coordenada Juego::pedir_coordenadas()
{
    string x, y;
    msjeInstruccion("Ingrese las coordenadas:");
    msjeInstruccion("Coordenada X:");
    cin >> x;
    msjeInstruccion("Coordenada Y:");
    cin >> y;
    return crear_coordenada(stoi(x), stoi(y));
}

string Juego::pedir_nombre_edificio()
{
    string nombre_edificio, aux;
    msjeInstruccion("Ingrese el nombre del edificio:");
    cin >> nombre_edificio;
    if (nombre_edificio == "planta")
    {
        cin >> aux;
        nombre_edificio = nombre_edificio + " " + aux;
    }
    return nombre_edificio;
}

//falta verificaciones
int Juego::pedir_id_jugador()
{
    msjeInstruccion("Seleccione un jugador (ingrese el numero):");
    for (int i = 0; i < CANT_JUGADORES; i++)
        msjeInstruccion(to_string(i + 1) + ": Jugador nro " + to_string(i + 1));
    //verificar si es valido (esto no porque se hace en otro lado)
    //verificar que se ingrese un numero entero
    int id;
    cin >> id;
    return id;
}

//-----------------------------------------------------------------
void Juego::demoler_edificio(Coordenada coord)
{
    if (mapa.coordenadas_validas(coord))
    {
        Edificio *edificio = mapa.obtener_edificio(coord);

        if (edificio)
        {
            msjeInstruccion("Se va a eliminar un edificio del tipo '" + edificio->obtener_nombre() + "'");
            string rta;
            msjeInstruccion("Desea confirmar la demolicion?(si/no)");
            cin >> rta;
            if (rta == "si")
            {
                jugadores[id_jugador_actual - 1].agregar_materiales_reciclados(edificio);
                jugadores[id_jugador_actual - 1].eliminar_ubicacion_edificio(edificio->obtener_nombre(), coord);
                mapa.demoler_contenido(coord);
                msjeOK("Se demolio el edificio, se elimino de la lista de ubicaciones y se agregaron los materiales reciclados al inventario");
            }
            else if (rta == "no")
                msjeInstruccion("No se destruyo el edificio.");
            else
                msjeError("Opcion invalida. Ingrese 'si' o 'no'");
        }
        else
            msjeError("No hay edificio construido ahi");
    }
}