PROGRAM= andypolis
CC:= g++
FLAGS:= -Wall -Werror -Wconversion -pedantic -g
LDLFLAGS= -lm

all: andypolis

#main: 
andypolis: main.cpp

#lectora de archivos: 
andypolis: parser.cpp

#menu: 
#andypolis: menu.cpp 
andypolis: menu2.cpp 
#juego: 
#andypolis: juego.cpp
andypolis: juego2.cpp
#jugador:
andypolis: jugador.cpp 

#diccionario
#andypolis: diccionario.cpp 

#mapa:
andypolis: mapa.cpp
andypolis: ubicaciones.cpp

#inventario: 
andypolis: inventario.cpp

#casilleros abstractos: 
andypolis: casillero.cpp 
andypolis: casilleroConstruible.cpp 
andypolis: casilleroInaccesible.cpp
andypolis: casilleroTransitable.cpp

#casilleros: 
andypolis: betun.cpp 
andypolis: camino.cpp 
andypolis: lago.cpp 
andypolis: terreno.cpp 
andypolis: muelle.cpp 

#objetivo abstracto: 
andypolis: objetivo.cpp

#objetivos: 
andypolis: armado.cpp
andypolis: bombardero.cpp
andypolis: cansado.cpp
andypolis: comprarAndypolis.cpp
andypolis: constructorO.cpp
andypolis: construirObelisco.cpp
andypolis: edadDePiedra.cpp
andypolis: energetico.cpp
andypolis: extremista.cpp
andypolis: letrado.cpp
andypolis: minero.cpp

#edificio abstracto:
andypolis: edificio.cpp

#edificios: 
andypolis: edificioAserradero.cpp
andypolis: edificioEscuela.cpp 
andypolis: edificioFabrica.cpp
andypolis: edificioMina.cpp 
andypolis: edificioMinaOro.cpp 
andypolis: edificioObelisco.cpp 
andypolis: edificioPlantaElectrica.cpp 
andypolis: edificioYacimiento.cpp 

#material abstracto: 
andypolis: material.cpp

#materiales: 
andypolis: materialMadera.cpp 
andypolis: materialPiedra.cpp 
andypolis: materialMetal.cpp 
andypolis: materialBomba.cpp
andypolis: andycoins.cpp

#fabricas: 
andypolis: constructor.cpp
andypolis: recurso.cpp 
andypolis: superficie.cpp 

#jugadas:
andypolis: jugada.cpp

#jugadas del primer meno:
andypolis: listaredificios.cpp
andypolis: mostrarmapa.cpp
andypolis: comenzarpartida.cpp

#jugadas del segundo menu:
andypolis: construir.cpp
andypolis: listarconstruidos.cpp
andypolis: demoler.cpp
andypolis: atacar.cpp
andypolis: comprar.cpp
andypolis: consultarcoordenada.cpp
andypolis: mostrarinventario.cpp
andypolis: mostrarobjetivos.cpp
andypolis: recolectar.cpp
andypolis: finalizarturno.cpp
andypolis: reparar.cpp

#libreria para los colores: 
andypolis: colors.cpp 

	$(CC) $(FLAGS) $^ -o andypolis

clean:
	rm -vf *.o $(PROGRAM)

gdb: andypolis
	gdb ./andypolis

valgrind: andypolis
	valgrind --leak-check=full --show-leak-kinds=all --track-origins=yes -s ./andypolis