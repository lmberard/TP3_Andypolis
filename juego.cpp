#include "juego.hpp"
//--------------------CONSTRUCTORES DESTRUCTORES-------------------
Juego::Juego()
{
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

//----------------------------MAPA---------------------------------
void Juego::crear_mapa(int filas, int columnas)
{
    mapa.crear_memoria_mapa(filas, columnas);
}

void Juego::agregar_casillero(Coordenada coord, string casillero)
{
    mapa.agregar_casillero(coord, casillero, terreno);
}

//-------------------OPCIONES MENU PRINCIPAL-----------------------
//FALTAA
void Juego::modificar_edificio_por_nombre()
{
    cout << "falta" << endl;
}

//FALTAN COSAS
void Juego::mostrar_todos_edificios()
{
    /*
   FALTA:
    cuantos fueron construidos hasta el momento, 
    cuantos más puedo construir3sin superar el máximo permitido 
    */

    int cant_edificios = bob.cant_edificios();
    Edificio *edificio;

    cout << left << TXT_BOLD << TXT_UNDERLINE << BGND_BLUE_4
         << setw(23) << "Nombre" << '\t'
         << setw(23) << "Cant de madera" << '\t'
         << setw(23) << "Cant de metal" << '\t'
         << setw(23) << "Cant de piedra" << '\t'
         << setw(23) << "Cant maxima" << '\t'
         << setw(23) << "Cant de produccion" << '\t'
         << setw(23) << "Tipo de material que produce"
         << END_COLOR << endl;
    for (int i = 1; i < cant_edificios + 1; i++)
    {
        edificio = bob.mostrar_edificio(i);
        cout << left
             << setw(23) << edificio->obtener_nombre() << '\t'
             << setw(23) << edificio->obtener_madera() << '\t'
             << setw(23) << edificio->obtener_metal() << '\t'
             << setw(23) << edificio->obtener_piedra() << '\t'
             << setw(23) << edificio->obtener_cant_max() << '\t'
             << setw(23) << edificio->obtener_cant_mat_producido() << '\t'
             << setw(23) << edificio->obtener_mat_producido()
             << endl;
    }
    cout << "falta" << endl;
}

void Juego::mostrar_mapa()
{
    mapa.mostrar();
}

//FALTAA
void Juego::comenzar_partida()
{
    /*
    Se le deberá pedir al usuario que seleccione si desea ser
    el jugador 1 o el jugador 2. 
    Una vez seleccionadoel número de jugador se le pedirá a cada uno que 
    ingrese la coordenada5en la cual desea posicionarse para comenzar el juego. 
    Cuando ambos jugadores se encuentren posicionados se da por comenzado el juego
    */
    cout << "falta" << endl;
}

//-----------------------OPCIONES JUEGO----------------------------
void Juego::construir_por_nombre_coordenada(int id_jugador, Constructor &bob)
{
    string nombre_edificio = pedir_nombre_edificio();

    if (chequear_permisos_edificio(nombre_edificio, bob, id_jugador))
    {
        Coordenada coord = pedir_coordenadas();
        construir_edificio(coord, nombre_edificio, bob, id_jugador);
    }
}

void Juego::mostrar_edificios_construidos(int id_jugador)
{
    if (id_jugador_es_valido(id_jugador))
        jugadores[id_jugador - 1].mostrar_edificios_construidos();
}

void Juego::demoler_por_coordenada(int id_jugador)
{
    Coordenada coord = pedir_coordenadas();
    demoler_edificio(coord, id_jugador);
}

//FALTAA
void Juego::atacar_por_coordenada(int id_jugador)
{
    cout << "falta" << endl;
}

//FALTAA
void Juego::reparar_por_coordenada(int id_jugador)
{
    cout << "falta" << endl;
}

void Juego::consultar_coordenada()
{
    Coordenada coord = pedir_coordenadas();
    if (mapa.coordenadas_validas(coord))
    {
        msjeInstruccion("Hola, estas en la posicion (" + to_string(coord.coord_x) + ", " + to_string(coord.coord_y) + ")");
        mapa.consultar_coordenada(coord);
    }
}

void Juego::mostrar_inventario(int id_jugador)
{
    if (id_jugador_es_valido(id_jugador))
        jugadores[id_jugador - 1].mostrar_inventario();
}

//FALTAN COSAS
void Juego::recolectar(int id_jugador)
{
    cout << "falta" << endl;
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

void Juego::moverse_a_coordenada(int id_jugador)
{
    if (id_jugador_es_valido(id_jugador))
    {
        Coordenada coord = pedir_coordenadas();
        jugadores[id_jugador - 1].moverse_a_coordenada(coord.coord_x, coord.coord_y);
    }
}

//FALTAA
void Juego::finalizar_turno(int id_jugador)
{
    cout << "falta" << endl;
}

//-----------------------FUNCIONES UTILES--------------------------
bool Juego::id_jugador_es_valido(int id_jugador)
{
    return (id_jugador >= 1 && id_jugador <= CANT_JUGADORES);
}

Coordenada Juego::pedir_coordenadas()
{
    string x, y;
    msjeInstruccion("Ingrese las coordenadas.");
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

//-----------------------------------------------------------------
//FALTAN DETALLES
void Juego::construir_edificio(Coordenada coord, const string &eledificio, Constructor &bob, int id_jugador)
{
    if (mapa.coordenadas_validas(coord))
    {
        if (!mapa.obtener_edificio(coord))
        {
            Edificio *edificio = bob.construye(eledificio);
            if (jugadores[id_jugador - 1].cantidad_suficiente_material(edificio, true))
            {
                string rta;
                msjeInstruccion("Desea confirmar la construccion?(si/no)");
                cin >> rta;
                if (rta == "si")
                {
                    if (mapa.agregar_contenido(coord, edificio))
                    {
                        jugadores[id_jugador - 1].agregar_ubicacion_lista_edificios(eledificio, coord);
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

/*
void Juego::agregar_material_coordenada(string nombre, int cantidad, Coordenada coord)
{
    while (cantidad)
    {
        int numero = generar_valor_random(1, coordenadasTransitables.mostrar_cantidad());
        mapa.agregar_contenido(coordenadasTransitables[numero], recurso.dar_material(nombre));
        cout << "\t-> (" << coordenadasTransitables[numero].coord_x << ", " << coordenadasTransitables[numero].coord_y << ")" << endl;
        materiales.alta(coordenadasTransitables[numero]);
        coordenadasTransitables.baja(numero);
        cantidad--;
    }
}*/

bool Juego::chequear_permisos_edificio(const string &eledificio, Constructor &bob, int id_jugador)
{
    Edificio *edificio = bob.construye(eledificio);
    int flag = 1;
    if (edificio)
    {
        int cant_construidos = jugadores[id_jugador - 1].obtener_cant_edificios_construidos(eledificio);
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

void Juego::demoler_edificio(Coordenada coord, int id_jugador)
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
                jugadores[id_jugador - 1].agregar_materiales_reciclados(edificio);
                jugadores[id_jugador - 1].eliminar_ubicacion_edificio(edificio->obtener_nombre(), coord);
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

void Juego::llenar_coordenada_transitable()
{
    Coordenada coord;

    for (int x = 0; x < mapa.obtener_filas(); x++)
    {
        for (int y = 0; y < mapa.obtener_columnas(); y++)
        {
            coord.coord_x = x;
            coord.coord_y = y;
            if (mapa.coordenada_es_transitable(coord))
                coordenadasTransitables.alta(coord);
        }
    }
}
