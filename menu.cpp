#include "menu.hpp"

using namespace std;

////////////////////////////////////////////////////////////////

int Menu::obtener_opcion_usuario()
{
    int opcion_elegida = -1;
    string aux;
    getline(cin, aux);
    if (es_numero_y_positivo(aux))
        opcion_elegida = stoi(aux);
    return opcion_elegida;
}

////////////////////////////////////////////////////////////////

void Menu::mostrar_menu_juego(int id_jugador)
{
    cout << "\n " << TXT_BOLD << TXT_UNDERLINE << TXT_LIGHT_BLUE_6 << "¡¡Bienvenido a Andypolis, Jugador " << id_jugador << "!! ¿Que desea hacer?" << END_COLOR << " " << endl;
    cout << endl;
    cout << "     " << TXT_LIGHT_PURPLE_141 << "╔══════════════════════════════════════════════╗" << END_COLOR << " " << endl;
    cout << "     " << TXT_LIGHT_PURPLE_141 << "║ 1. Construir edificios por nombre.           ║" << END_COLOR << " " << endl;
    cout << "     " << TXT_LIGHT_PURPLE_141 << "║ 2. Listar mis edificios construidos.         ║" << END_COLOR << " " << endl;
    cout << "     " << TXT_LIGHT_PURPLE_141 << "║ 3. Demoler un edificio por coordenada.       ║" << END_COLOR << " " << endl;
    cout << "     " << TXT_LIGHT_PURPLE_141 << "║ 4. Atacar un edificio por coordenada.        ║" << END_COLOR << " " << endl;
    cout << "     " << TXT_LIGHT_PURPLE_141 << "║ 5. Reparar un edificio por coordenada.       ║" << END_COLOR << " " << endl;
    cout << "     " << TXT_LIGHT_PURPLE_141 << "║ 6. Comprar bombas.                           ║" << END_COLOR << " " << endl;
    cout << "     " << TXT_LIGHT_PURPLE_141 << "║ 7. Consultar coordenada.                     ║" << END_COLOR << " " << endl;
    cout << "     " << TXT_LIGHT_PURPLE_141 << "║ 8. Mostrar inventario.                       ║" << END_COLOR << " " << endl;
    cout << "     " << TXT_LIGHT_PURPLE_141 << "║ 9. Mostrar objetivos.                        ║" << END_COLOR << " " << endl;
    cout << "     " << TXT_LIGHT_PURPLE_141 << "║ 10. Recolectar recursos producidos.          ║" << END_COLOR << " " << endl;
    cout << "     " << TXT_LIGHT_PURPLE_141 << "║ 11. Moverse a una coordenada.                ║" << END_COLOR << " " << endl;
    cout << "     " << TXT_LIGHT_PURPLE_141 << "║ 12. Finalizar turno.                         ║" << END_COLOR << " " << endl;
    cout << "     " << TXT_LIGHT_PURPLE_141 << "║ 13. Guardar y salir.                         ║" << END_COLOR << " " << endl;
    cout << "     " << TXT_LIGHT_PURPLE_141 << "╚══════════════════════════════════════════════╝" << endl;
    cout << END_COLOR;
    cout << endl;
    msjeInstruccion("Ingrese la opcion con un NUMERO del 1 al 13:");
}

void Menu::partida_nueva_mostrar()
{
    cout << "\n " << TXT_BOLD << TXT_UNDERLINE << TXT_LIGHT_BLUE_6 << "¡¡Bienvenido a Andypolis!! ¿Que desea hacer?" << END_COLOR << " " << endl;
    cout << endl;
    cout << "\t" << TXT_LIGHT_PURPLE_141 << "╔══════════════════════════════════════════════╗" << END_COLOR << " " << endl;
    cout << "\t" << TXT_LIGHT_PURPLE_141 << "║ 1.  Modificar edificio por nombre.           ║" << END_COLOR << " " << endl;
    cout << "\t" << TXT_LIGHT_PURPLE_141 << "║ 2.  Listar todos los edificios.              ║" << END_COLOR << " " << endl;
    cout << "\t" << TXT_LIGHT_PURPLE_141 << "║ 3.  Mostrar mapa                             ║" << END_COLOR << " " << endl;
    cout << "\t" << TXT_LIGHT_PURPLE_141 << "║ 4.  Comenzar partida                         ║" << END_COLOR << " " << endl;
    cout << "\t" << TXT_LIGHT_PURPLE_141 << "║ 5.  Guardar y salir.                         ║" << END_COLOR << " " << endl;
    cout << "\t" << TXT_LIGHT_PURPLE_141 << "╚══════════════════════════════════════════════╝" << endl;
    cout << END_COLOR;
    cout << endl;
    msjeInstruccion("Ingrese la opcion con un NUMERO del 1 al 5: ");
}

Jugada *Menu::menu_juego(int id_jugador_actual)
{
    int opcion_elegida = obtener_opcion_usuario();
    limpiar_pantalla();
    validar_opcion_juego(opcion_elegida, id_jugador_actual);
    return procesar_opcion_juego(opcion_elegida);
}

Jugada *Menu::inicial()
{
    int opcion_elegida = obtener_opcion_usuario();
    limpiar_pantalla();
    validar_opcion_partida_nueva(opcion_elegida);
    return procesar_opcion_partida_nueva(opcion_elegida);
}

////////////////////////////////////////////////////////////////
void Menu::validar_opcion_juego(int &opcion_elegida, int id_jugador_actual)
{
    while (!es_opcion_valida(opcion_elegida, OPCION_MINIMA, OPCION_MAXIMA_JUEGO))
    {
        msjeError("Ese numero de opcion no es valido, intente nuevamente: ");
        mostrar_menu_juego(id_jugador_actual);
        opcion_elegida = obtener_opcion_usuario();
    }
}

void Menu::validar_opcion_partida_nueva(int &opcion_elegida)
{
    while (!es_opcion_valida(opcion_elegida, OPCION_MINIMA, OPCION_MAXIMA_NUEVA_PARTIDA))
    {
        msjeError("Ese numero de opcion no es valido, intente nuevamente: ");
        partida_nueva_mostrar();
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
    msjeInstruccion("\nPresione ENTER para volver al menu.");
    cin.get();

    // cin.get();
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
Jugada *Menu::procesar_opcion_partida_nueva(int opcion_elegida)
{
    Jugada *jugada = NULL;
    switch (opcion_elegida)
    {
    case MODIFICAR_EDIFICIO_POR_NOMBRE:
        jugada = new ModificarEdificio();
        break;
    case LISTAR_TODOS_EDIFICIOS:
        jugada = new ListarEdificios();
        break;
    case MOSTRAR_MAPA:
        jugada = new MostrarMapa();
        break;
    case COMENZAR_PARTIDA:
        jugada = new ComenzarPartida();
        break;
    case SALIR_INICIAL:
        despedir();
        break;
    default:
        msjeError("Opcion invalida");
    }
    return jugada;
}

Jugada *Menu::procesar_opcion_juego(int opcion_elegida)
{
    Jugada *jugada = NULL;
    switch (opcion_elegida)
    {
    case CONSTRUIR_EDIFICIO:
        jugada = new Construir();
        break;
    case LISTAR_CONSTRUIDOS:
        jugada = new ListarConstruidos();
        break;
    case DEMOLER_POR_COORDENADA:
        jugada = new Demoler();
        break;
    case ATACAR_POR_COORDENADA:
        jugada = new Atacar();
        break;
    case REPARAR_POR_COORDENADA:
        jugada = new Reparar();
        break;
    case COMPRAR_BOMBAS:
        jugada = new Comprar();
        break;
    case CONSULTAR_COORDENADA:
        jugada = new ConsultarCoordenada();
        break;
    case MOSTRAR_INVENTARIO:
        jugada = new MostrarInventario();
        break;
    case MOSTRAR_OBJETIVOS:
        jugada = new MostrarObjetivos();
        break;
    case RECOLECTAR_RECURSOS:
        jugada = new Recolectar();
        break;
    case MOVERSE_COORDENADA:
        jugada = new Moverse();
        break;
    case FINALIZAR_TURNO:
        jugada = new FinalizarTurno();
        break;
    case SALIR_JUEGO:
        despedir();
        break;
    default:
        msjeError("Opcion invalida");
    }

    return jugada;
}
