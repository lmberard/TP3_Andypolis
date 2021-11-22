#include "juego.hpp"

Juego::Juego()
{
}

Juego::~Juego()
{
    demoler_todo();
}

void Juego::demoler_todo()
{
    //borro lo que esta en el mapa
    for (int i = 1; i < edificios.mostrar_cantidad() + 1; i++)
        mapa.demoler_contenido(edificios[i].coord_x, edificios[i].coord_y);
    for (int i = 1; i < materiales.mostrar_cantidad() + 1; i++)
        mapa.demoler_contenido(materiales[i].coord_x, materiales[i].coord_y);
}

void Juego::crear_mapa(int filas, int columnas)
{
    mapa.crear_memoria_mapa(filas, columnas);
}

void Juego::agregar_casillero(int x, int y, string casillero)
{
    mapa.agregar_casillero(x, y, casillero, terreno);
}

int Juego::obtener_filas_mapa()
{
    return mapa.obtener_filas();
}

int Juego::obtener_columnas_mapa()
{
    return mapa.obtener_columnas();
}

//----------------------------------------------------------------
void Juego::mostrar_mapa()
{
    mapa.mostrar();
}

void Juego::consultar_coordenada()
{
    string x, y, separador = ", ";
    msjeInstruccion("Ingrese las coordenadas del mapa para demoler:");
    msjeInstruccion("Coordenada X:");
    cin >> x;
    msjeInstruccion("Coordenada Y:");
    cin >> y;
    //verificar que no se pase de las coordenadas del mapa
    msjeInstruccion("Hola, estas en la posicion (" + x + separador + y + ")");
    mapa.consultar_coordenada(stoi(x), stoi(y));
}

//----------------------------------------------------------------
void Juego::construir_por_nombre_coordenada(Constructor &bob)
{
    string x, y, nombre_edificio, aux;
    msjeInstruccion("Ingrese el nombre del edificio que quiere construir:");
    cin >> nombre_edificio;
    if (nombre_edificio == "planta")
    {
        cin >> aux;
        nombre_edificio = nombre_edificio + " " + aux;
    }

    if (chequear_permisos_edificio(nombre_edificio, bob))
    {
        msjeInstruccion("Ingrese las coordenadas donde quiere construirlo.");
        msjeInstruccion("Coordenada X:");
        cin >> x;
        msjeInstruccion("Coordenada Y:");
        cin >> y;
        construir(stoi(x), stoi(y), nombre_edificio, bob);
    }
}

void Juego::construir(int x, int y, const string &eledificio, Constructor &bob)
{
    if (x < mapa.obtener_filas() && y < mapa.obtener_columnas())
    {
        Edificio *edificio = bob.construye(eledificio);
        if (inventario.chequear_stock(edificio, true))
        {
            if (!mapa.obtener_edificio(x, y))
            {
                string rta;
                msjeInstruccion("Desea confirmar la construccion?(si/no)");
                cin >> rta;
                if (rta == "si")
                {
                    if (mapa.agregar_contenido(x, y, edificio))
                    {
                        agregar_ubicacion(x, y, eledificio);
                        msjeOK("Se construyo el edificio y se agrego a la lista de ubicaciones");
                    }
                }
                else if (rta == "no")
                {
                    msjeInstruccion("No se construyo el edificio.");
                    delete edificio;
                }
                else
                {
                    msjeError("Opcion invalida. Ingrese 'si' o 'no'");
                }
            }
            else
            {
                mapa.agregar_contenido(x, y, edificio);
                delete edificio;
            }
        }
        else
        {
            msjeError("No hay materiales suficientes para la construccion de ese edificio :(");
            delete edificio;
        }
    }
    if (x > mapa.obtener_filas())
        msjeError("Esa coordenada X no existe en el mapa");
    if (y > mapa.obtener_columnas())
        msjeError("Esa coordenada Y no existe en el mapa");
}

void Juego::demoler_por_coordenada()
{
    string x, y;
    msjeInstruccion("Ingrese las coordenadas del mapa para demoler:");
    msjeInstruccion("Coordenada X:");
    cin >> x;
    msjeInstruccion("Coordenada Y:");
    cin >> y;
    demoler_edificio(stoi(x), stoi(y));
}

void Juego::mostrar_ubicaciones()
{
    Lista<Ubicacion> copia;
    Lista<Ubicacion> auxiliar;
    int cant = 1;

    for (int i = 1; i < edificios.mostrar_cantidad() + 1; i++)
        copia.alta(edificios[i]);

    for (int i = 1; i < copia.mostrar_cantidad() + 1; i++)
    {
        auxiliar.alta(copia[i]);
        for (int j = i + 1; j < copia.mostrar_cantidad() + 1; j++)
        {
            if (auxiliar[1].nombre == copia[j].nombre)
            {
                auxiliar.alta(copia[j]);
                cant++;
                copia.baja(j);
                --j;
            }
        }
        cout << TXT_BOLD << TXT_UNDERLINE << BGND_DARK_BLUE_17 << "Tipo de edificio: " << auxiliar[1].nombre << END_COLOR << endl;
        cout << "\t-> Cantidad construida: " << cant << endl;
        cout << "\t-> Coordenadas:" << endl;

        for (int i = 1; i < auxiliar.mostrar_cantidad() + 1; i++)
        {
            cout << "\t\t-> (" << auxiliar[i].coord_x << ", "
                 << auxiliar[i].coord_y << ')' << endl;
        }
        cout << endl;
        cant = 1;
        while (!auxiliar.vacia())
            auxiliar.baja(1);
    }
}

void Juego::recolectar()
{
    Edificio *edificio;

    msjeOK("Se recolectaron los siguientes materiales:");
    for (int i = 1; i < edificios.mostrar_cantidad() + 1; i++)
    {
        edificio = mapa.obtener_edificio(edificios[i].coord_x, edificios[i].coord_y);
        inventario.recolectar(edificio);
    }
    msjeOK("Se guardaron los materiales en la lista de materiales. Pueden ser usados para construir nuevos edificios :)");
}

void Juego::lluvia()
{
    if (coordenadasTransitables.mostrar_cantidad() > 6)
    {
        cout << "LLUVIA DE RECURSOS!" << endl;
        int cant_metal = generar_valor_random(LLUVIA_METAL_MIN, LLUVIA_METAL_MAX);
        msjeTitulo("Cantidad de metales generados: " + to_string(cant_metal));
        agregar_materiales_casillero_random("metal", cant_metal);

        int cant_piedra = generar_valor_random(LLUVIA_PIEDRA_MIN, LLUVIA_PIEDRA_MAX);
        msjeTitulo("Cantidad de piedras generadas: " + to_string(cant_piedra));
        agregar_materiales_casillero_random("piedra", cant_piedra);

        int cant_madera = generar_valor_random(LLUVIA_MADERA_MIN, LLUVIA_MADERA_MAX);
        msjeTitulo("Cantidad de maderas generadas: " + to_string(cant_madera));
        agregar_materiales_casillero_random("madera", cant_madera);
    }
}

//----------------------------------------------------------------
void Juego::agregar_materiales_casillero_random(string nombre, int cantidad)
{
    while (cantidad)
    {
        int numero = generar_valor_random(1, coordenadasTransitables.mostrar_cantidad());
        mapa.agregar_contenido(coordenadasTransitables[numero].coord_x, coordenadasTransitables[numero].coord_y, recurso.dar_material(nombre));
        cout << "\t-> (" << coordenadasTransitables[numero].coord_x << ", " << coordenadasTransitables[numero].coord_y << ")" << endl;
        materiales.alta(coordenadasTransitables[numero]);
        coordenadasTransitables.baja(numero);
        cantidad--;
    }
}

void Juego::agregar_ubicacion_edificio(Ubicacion ubicacion)
{
    edificios.alta(ubicacion);
}

bool Juego::chequear_permisos_edificio(const string &eledificio, Constructor &bob)
{
    Edificio *edificio = bob.construye(eledificio);
    int flag = 1;
    if (edificio)
    {
        if (inventario.chequear_stock(edificio, false))
        {
            msjeOK("Hay materiales suficientes para construir este edificio");
            flag = 1;
            if (edificio->obtener_cant_max() > cant_construidos(eledificio))
            {
                msjeOK("y todavia hay capacidad para construir edificios de ese estilo!");
                flag = 1;
            }
            else
            {
                flag = 0;
                msjeError("pero ya no se pueden construir mas edificios de ese estilo. Llegamos al maximo :(");
            }
        }
        else
            flag = 0;
        delete edificio;
    }
    else
    {
        msjeError("No existe ese tipo de edificio. Intente con otro nombre");
        flag = 0;
    }
    return flag;
}

int Juego::cant_construidos(const string &edificio)
{
    int cant = 0;
    for (int i = 1; i < edificios.mostrar_cantidad() + 1; i++)
        if (edificios[i].nombre == edificio)
            cant++;

    return cant;
}

void Juego::agregar_ubicacion(int x, int y, string edificio)
{
    Ubicacion ubicacion;
    ubicacion.nombre = edificio;
    ubicacion.coord_x = x;
    ubicacion.coord_y = y;
    edificios.alta(ubicacion);
}

void Juego::demoler_edificio(int x, int y)
{
    // int cuenta = 0;
    if (x < mapa.obtener_filas() && y < mapa.obtener_columnas())
    {
        Edificio *edificio = mapa.obtener_edificio(x, y);

        if (edificio)
        {
            msjeInstruccion("Se va a eliminar un edificio del tipo '" + edificio->obtener_nombre() + "'");
            string rta;
            msjeInstruccion("Desea confirmar la demolicion?(si/no)");
            cin >> rta;
            if (rta == "si")
            {
                inventario.llenar_stock(edificio);
                mapa.demoler_contenido(x, y);
                quitar_ubicacion(x, y);
                msjeOK("Se demolio el edificio y se elimino de la lista de ubicaciones");
            }
            else if (rta == "no")
                msjeInstruccion("No se destruyo el edificio.");
            else
                msjeError("Opcion invalida. Ingrese 'si' o 'no'");
        }
        else
            msjeError("No hay edificio construido ahi");
    }
    if (x > mapa.obtener_filas())
        msjeError("Esa coordenada X no existe en el mapa");
    if (y > mapa.obtener_columnas())
        msjeError("Esa coordenada Y no existe en el mapa");
}

void Juego::quitar_ubicacion(int x, int y)
{
    for (int i = 1; i < edificios.mostrar_cantidad() + 1; i++)
        if (edificios[i].coord_x == x && edificios[i].coord_y == y)
            edificios.baja(i);
}

void Juego::llenar_coordenada_transitable()
{
    Ubicacion coordenada;

    for (int x = 0; x < mapa.obtener_filas(); x++)
        for (int y = 0; y < mapa.obtener_columnas(); y++)
            if (mapa.coordenada_es_transitable(x, y))
            {
                coordenada.coord_x = x;
                coordenada.coord_y = y;
                coordenadasTransitables.alta(coordenada);
            }
}

void Juego::cargar_ubicaciones()
{
    Ubicacion ubicacion;
    for (int i = 1; i < edificios.mostrar_cantidad() + 1; i++)
    {
        ubicacion = edificios[i];
        Edificio *edificio = bob.construye(ubicacion.nombre);
        mapa.agregar_contenido(ubicacion.coord_x, ubicacion.coord_y, edificio);
    }
}

void Juego::listar_edificios()
{

    int cant_edificios = bob.cant_edificios();
    Edificio *edificio;

    cout << left << TXT_BOLD << TXT_UNDERLINE << BGND_BLUE_4
         << setw(23) << "Nombre" << '\t'
         << setw(23) << "Cant de madera" << '\t'
         << setw(23) << "Cant de metal" << '\t'
         << setw(23) << "Cant de piedra" << '\t'
         << setw(23) << "Cant maxima" << '\t'
         << setw(23) << "Se pueden construir.." << '\t'
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
             << setw(23) << edificio->obtener_cant_max() - cant_construidos(edificio->obtener_nombre()) << '\t'
             << setw(23) << edificio->obtener_cant_mat_producido() << '\t'
             << setw(23) << edificio->obtener_mat_producido()
             << endl;
    }
}
