#include "menu.hpp"
#include "casillero.hpp"

using namespace std;
////////////////////////////////////////////////////////////////
bool char_son_iguales(char &c1, char &c2)
{
    if (c1 == c2)
        return true;
    else if (toupper(c1 == toupper(c2)))
        return true;
    return false;
}

bool strings_son_iguales(string &str1, string &str2)
{
    return ((str1.size() == str2.size()) &&
            equal(str1.begin(), str1.end(), str2.begin(), &char_son_iguales));
}

////////////////////////////////////////////////////////////////
string Menu::devolver_rta_usuario()
{
    string rta;
    cin >> rta;
    return rta;
}

bool Menu::confirmacion_usuario()
{
    string rta, si = "si", no = "no";
    rta = devolver_rta_usuario();
    if (strings_son_iguales(rta, si))
        return true;
    else if (!strings_son_iguales(rta, no))
    {
        msjeError("Error. Opciones validas: 'si' o 'no'");
        return false;
    }
    else
        return false;
}

int Menu::obtener_opcion_usuario()
{
    int opcion_elegida;
    cin >> opcion_elegida;
    return opcion_elegida;
}
////////////////////////////////////////////////////////////////
void Menu::mostrar_menu_juego()
{
    cout << " " << TXT_BOLD << TXT_UNDERLINE << TXT_LIGHT_BLUE_6 << "¡¡Bienvenido a Andypolis, Jugador X!! ¿Que desea hacer?" << END_COLOR << " " << endl;
    cout << endl;
    cout << "\t" << TXT_LIGHT_PURPLE_141 << "╔══════════════════════════════════════════════╗" << END_COLOR << " " << endl;
    cout << "\t" << TXT_LIGHT_PURPLE_141 << "║ 1. Construir edificios por nombre.           ║" << END_COLOR << " " << endl;
    cout << "\t" << TXT_LIGHT_PURPLE_141 << "║ 2. Listar mis edificios construidos.         ║" << END_COLOR << " " << endl;
    cout << "\t" << TXT_LIGHT_PURPLE_141 << "║ 3. Demoler un edificio por coordenada.       ║" << END_COLOR << " " << endl;
    cout << "\t" << TXT_LIGHT_PURPLE_141 << "║ 4. Atacar un edificio por coordenada.        ║" << END_COLOR << " " << endl;
    cout << "\t" << TXT_LIGHT_PURPLE_141 << "║ 5. Reparar un edificio por coordenada.       ║" << END_COLOR << " " << endl;
    cout << "\t" << TXT_LIGHT_PURPLE_141 << "║ 6. Comprar bombas.                           ║" << END_COLOR << " " << endl;
    cout << "\t" << TXT_LIGHT_PURPLE_141 << "║ 7. Consultar coordenada.                     ║" << END_COLOR << " " << endl;
    cout << "\t" << TXT_LIGHT_PURPLE_141 << "║ 8. Mostrar inventario.                       ║" << END_COLOR << " " << endl;
    cout << "\t" << TXT_LIGHT_PURPLE_141 << "║ 9. Mostrar objetivos.                        ║" << END_COLOR << " " << endl;
    cout << "\t" << TXT_LIGHT_PURPLE_141 << "║ 10. Recolectar recursos producidos.          ║" << END_COLOR << " " << endl;
    cout << "\t" << TXT_LIGHT_PURPLE_141 << "║ 11. Moverse a una coordenada.                ║" << END_COLOR << " " << endl;
    cout << "\t" << TXT_LIGHT_PURPLE_141 << "║ 12. Finalizar turno.                         ║" << END_COLOR << " " << endl;
    cout << "\t" << TXT_LIGHT_PURPLE_141 << "║ 13. Guardar y salir.                         ║" << END_COLOR << " " << endl;
    cout << "\t" << TXT_LIGHT_PURPLE_141 << "╚══════════════════════════════════════════════╝" << endl;
    cout << END_COLOR;
    cout << endl;
    msjeInstruccion("Ingrese la opcion con un NUMERO del 1 al 13:");
}

void Menu::mostrar_menu_partida_nueva()
{
    cout << " " << TXT_BOLD << TXT_UNDERLINE << TXT_LIGHT_BLUE_6 << "¡¡Bienvenido a Andypolis!! ¿Que desea hacer hoy?" << END_COLOR << " " << endl;
    cout << endl;
    cout << "\t" << TXT_LIGHT_PURPLE_141 << "╔══════════════════════════════════════════════╗" << END_COLOR << " " << endl;
    cout << "\t" << TXT_LIGHT_PURPLE_141 << "║ 1.  Modificar edificio por nombre.           ║" << END_COLOR << " " << endl;
    cout << "\t" << TXT_LIGHT_PURPLE_141 << "║ 2.  Listar todos los edificios.              ║" << END_COLOR << " " << endl;
    cout << "\t" << TXT_LIGHT_PURPLE_141 << "║ 3.  Mostrar mapa de                          ║" << END_COLOR << " " << endl;
    cout << "\t" << TXT_LIGHT_PURPLE_141 << "║ 4.  Comenzar partida                         ║" << END_COLOR << " " << endl;
    cout << "\t" << TXT_LIGHT_PURPLE_141 << "║ 5.  Guardar y salir.                         ║" << END_COLOR << " " << endl;
    cout << "\t" << TXT_LIGHT_PURPLE_141 << "╚══════════════════════════════════════════════╝" << endl;
    cout << END_COLOR;
    cout << endl;
    msjeInstruccion("Ingrese la opcion con un NUMERO del 1 al 5:");
}

void Menu::menu_juego(Ciudad &andypolis, Constructor &bob, Recurso &recurso, int opcion_elegida)
{
    limpiar_pantalla();
    do
    {
        mostrar_menu_juego();
        opcion_elegida = obtener_opcion_usuario();
        validar_opcion_juego(opcion_elegida);
        procesar_opcion_juego(opcion_elegida, andypolis, bob, recurso);
    } while (opcion_elegida != SALIR_JUEGO);
}

void Menu::menu_partida_nueva(Ciudad &andypolis, Constructor &bob, Recurso &recurso, int opcion_elegida)
{
    limpiar_pantalla();
    do
    {
        mostrar_menu_partida_nueva();
        opcion_elegida = obtener_opcion_usuario();
        validar_opcion_partida_nueva(opcion_elegida);
        procesar_opcion_partida_nueva(opcion_elegida, andypolis, bob, recurso);
    } while (opcion_elegida != SALIR_INICIAL);
}

////////////////////////////////////////////////////////////////
void Menu::validar_opcion_juego(int opcion_elegida)
{
    while (!es_opcion_valida(opcion_elegida, OPCION_MINIMA, OPCION_MAXIMA_JUEGO))
    {
        if (!cin.good())
        {
            cin.clear();
            cin.ignore(100, '\n');
            msjeError("Se tiene que ingresar un numero entero del " + to_string(OPCION_MINIMA) + "al " + to_string(OPCION_MAXIMA_JUEGO) + "\nIntentemos de nuevo:");
            mostrar_menu_juego();
            cin >> opcion_elegida;
        }
        cin.clear();
        cin.ignore(100, '\n');
        msjeError("Ese numero de opcion no es valido, intentemos otra vez:");
        mostrar_menu_juego();
        cin >> opcion_elegida;
    }
}

void Menu::validar_opcion_partida_nueva(int opcion_elegida)
{
    while (!es_opcion_valida(opcion_elegida, OPCION_MINIMA, OPCION_MAXIMA_NUEVA_PARTIDA))
    {
        if (!cin.good())
        {
            cin.clear();
            cin.ignore(100, '\n');
            msjeError("Se tiene que ingresar un numero entero del " + to_string(OPCION_MINIMA) + "al " + to_string(OPCION_MAXIMA_NUEVA_PARTIDA) + "\nIntentemos de nuevo:");
            mostrar_menu_partida_nueva();
            opcion_elegida = obtener_opcion_usuario();
        }
        cin.clear();
        cin.ignore(100, '\n');
        msjeError("Ese numero de opcion no es valido, intentemos otra vez:");
        mostrar_menu_partida_nueva();
        opcion_elegida = obtener_opcion_usuario();
    }
}

bool Menu::es_opcion_valida(int elegida, const int opcion_minima, const int opcion_maxima)
{
    return (elegida >= opcion_minima && elegida <= opcion_maxima);
}

////////////////////////////////////////////////////////////////
void Menu::volver()
{
    msjeInstruccion("\nPresiona ENTER para volver al menu..");
    cin.get();

    cin.get();
    system(CLR_SCREEN);
}

void Menu::limpiar_pantalla()
{
    system(CLR_SCREEN);
}

void Menu::despedir()
{
    msjeInstruccion("Hasta luego! :)");
}
////////////////////////////////////////////////////////////////
void Menu::procesar_opcion_partida_nueva(int opcion_elegida, Ciudad &andypolis, Constructor &bob, Recurso &recurso)
{
    string nombre_edificio, x, y;
    switch (opcion_elegida)
    {
    case MODIFICAR_EDIFICIO_POR_NOMBRE:
        volver();
        break;
    case LISTAR_TODOS_EDIFICIOS:
        volver();
        break;
    case MOSTRAR_MAPA:
        volver();
        break;
    case COMENZAR_PARTIDA:
        // preguntar para cada jugador en que coordenada quiere empezar
        // se genera aleatoriamente quien empieza a jugar
        menu_juego(andypolis, bob, recurso, opcion_elegida);
        break;
    case SALIR_INICIAL:
        despedir();
        break;
    default:
        msjeError("Error: opcion invalida");
    }
}

void Menu::procesar_opcion_juego(int opcion_elegida, Ciudad &andypolis, Constructor &bob, Recurso &recurso)
{
    string nombre_edificio, x, y;
    switch (opcion_elegida)
    {
    case CONSTRUIR_EDIFICIO:
        andypolis.construir_por_nombre_coordenada(bob);
        volver();
        break;
    case LISTAR_CONSTRUIDOS:
        andypolis.mostrar_ubicaciones();
        volver();
        break;
    case DEMOLER_POR_COORDENADA:
        andypolis.demoler_por_coordenada();
        volver();
        break;
    case ATACAR_POR_COORDENADA:
        volver();
        break;
    case REPARAR_POR_COORDENADA:
        volver();
        break;
    case COMPRAR_BOMBAS:
        volver();
        break;
    case CONSULTAR_COORDENADA:
        andypolis.consultar_coordenada_cin();
        volver();
        break;
    case MOSTRAR_INVENTARIO:
        andypolis.mostrar_inventario();
        volver();
        break;
    case MOSTRAR_OBJETIVOS:
        volver();
        break;
    case RECOLECTAR_RECURSOS:
        andypolis.recolectar();
        volver();
        break;
    case MOVERSE_COORDENADA:
        volver();
        break;
    case FINALIZAR_TURNO:
        //termina el juego y deja jugar al otro
        //menu_juego(jugador X)
        volver();
        break;
    case SALIR_JUEGO:
        despedir();
        break;

    default:
        msjeError("Error: opcion invalida");
    }
}

////////////////////////////////////////////////////////////////
bool Menu::comenzo_nueva_partida(int opcion_elegida)
{
    return opcion_elegida == COMENZAR_PARTIDA;
}

bool Menu::cerro_menu_inicial(int opcion_elegida)
{
    return opcion_elegida == SALIR_INICIAL;
}

bool Menu::cerro_juego(int opcion_elegida)
{
    return opcion_elegida == SALIR_JUEGO;
}