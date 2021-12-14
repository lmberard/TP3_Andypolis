# TP3 Andypolis

Integrantes:

- Aguirre, Pedro
- Berard, Lucía Magdalena
- Guglieri, Mariano
- Fernández Mosquera, Guillermo

# Juego

Es la clase principal que engloba el funcionamiento de todo el juego. Se encarga de instanciar las jugadas segun las opciones del menu.

- juego.cpp/hpp

## Jugador

Se encarga de todo lo referente a cada jugador.

- jugador.cpp/hpp

## Jugadas

Se creo una clase Jugada abstracta que tiene como subclases a cada tipo de Jugada

- jugada.cpp/hpp
  - Jugadas del primer menu:
    - listaredificios.cpp/hpp
    - mostrarmapa.cpp/hpp
    - comenzarpartida.cpp/hpp
    - modificaredificio.cpp/hpp
  - Jugadas del segundo menu:
    - construir.cpp/hpp
    - listarconstruidos.cpp/hpp
    - demoler.cpp/hpp
    - atacar.cpp/hpp
    - comprar.cpp/hpp
    - consultarcoordenada.cpp/hpp
    - mostrarinventario.cpp/hpp
    - mostrarobjetivos.cpp/hpp
    - recolectar.cpp/hpp
    - finalizarturno.cpp/hpp
    - reparar.cpp/hpp

## Lectora de archivos

Se encarga de "completar" la informacion proveniente de los archivos .txt

- parser.cpp/hpp

## Menu

- menu.cpp/hpp

## Mapa

El mapa es una matriz de Casilleros.

- mapa.cpp/hpp
- ubicaciones.cpp/hpp: estructuras de Ubicacion y Coordenada

### Casilleros:

- casillero.cpp/hpp
  - casilleroConstruible.cpp/hpp
    - terreno.cpp/hpp
  - casilleroInaccesible.cpp/hpp
    - lago.cpp/hpp
  - casilleroTransitable.cpp/hpp
    - betun.cpp/hpp:
    - camino.cpp/hpp
    - muelle.cpp/hpp

# Objetivos

- objetivo.cpp/hpp
  - armado.cpp/hpp
  - bombardero.cpp/hpp
  - cansado.cpp/hpp
  - comprarAndypolis.cpp/hpp
  - constructorO.cpp/hpp
  - construirObelisco.cpp/hpp
  - edadDePiedra.cpp/hpp
  - energetico.cpp/hpp
  - extremista.cpp/hpp
  - letrado.cpp/hpp
  - minero.cpp/hpp
  - moverse.cpp/hpp

# Edificios

- edificio.cpp/hpp
  - edificioAserradero.cpp/hpp
  - edificioEscuela.cpp/hpp
  - edificioFabrica.cpp/hpp
  - edificioMina.cpp/hpp
  - edificioMinaOro.cpp/hpp
  - edificioObelisco.cpp/hpp
  - edificioPlantaElectrica.cpp/hpp
  - edificioYacimiento.cpp/hpp

# Materiales

- material.cpp/hpp

  - materialMadera.cpp/hpp
  - materialPiedra.cpp/hpp
  - materialMetal.cpp/hpp
  - materialBomba.cpp/hpp
  - andycoins.cpp/hpp

- inventario.cpp/hpp: Lista de materiales

# Fabricas

- constructor.cpp/hpp
  - Guarda la informacion de los edificios (diccionario con formato ABB)
  - Crea y destruye los edificios en el mapa.
- recurso.cpp/hpp
  - Crea y destruye los materiales
- superficie.cpp/hpp
  - Agrega un tipo de Casillero

# Herramientas

### Grafo:

Se utilizo un grafo y el algoritmo de camino minimo Dijkstra para mover al jugador por el mapa.

- dijkstra.cpp/hpp
- grafo.cpp/hpp

### Libreria para los colores:

Se utiliza para los mensajes coloridos en la terminal.

- colors.cpp/hpp

### Templates:

Se utilizaron listas para guardar materiales, ubicaciones, coordenadas, etc. Y el ABB para armar el diccionario con la receta de los edificios.

- lista.hpp
- nodo.hpp
- ABB.hpp
- ABBNodo.hpp
