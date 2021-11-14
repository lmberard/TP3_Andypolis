PROGRAM= andypolis
CC:= g++
FLAGS:= -Wall -Werror -Wconversion -pedantic -g
LDLFLAGS= -lm

all: andypolis

colors.o: colors.cpp colors.hpp
	$(CC) $(FLAGS) colors.o

lista.o: lista.cpp lista.hpp nodo.hpp nodo.cpp
	$(CC) $(FLAGS) lista.o

recurso.o: recurso.cpp recurso.hpp 
	$(CC) $(FLAGS) recurso.o	

terreno.o: terreno.cpp terreno.hpp 
	$(CC) $(FLAGS) terreno.o

constructor.o: constructor.cpp constructor.hpp 
	$(CC) $(FLAGS) constructor.o

inventario.o: inventario.cpp inventario.hpp 
	$(CC) $(FLAGS) inventario.o

material.o: material.cpp material.hpp materialMadera.cpp materialMetal.cpp materialPiedra.cpp
	$(CC) $(FLAGS) material.o

edificio.o: material.hpp edificio.hpp edificio.cpp edificioAserradero.cpp edificioEscuela.cpp edificioFabrica.cpp edificioMina.cpp edificioObelisco.cpp edificioPlantaElectrica.cpp
	$(CC) $(FLAGS) edificio.o

casillero.o: edificio.hpp material.hpp casillero.hpp casillero.cpp casilleroConstruible.cpp casilleroInaccesible.cpp casilleroTransitable.cpp 
	$(CC) $(FLAGS) casillero.o

menu.o: casillero.hpp edificio.hpp material.hpp menu.cpp menu.hpp
	$(CC) $(FLAGS) menu.o

andypolis: casillero.cpp casilleroConstruible.cpp casilleroInaccesible.cpp casilleroTransitable.cpp ciudad.cpp colors.cpp inventario.cpp constructor.cpp edificio.cpp edificioAserradero.cpp edificioEscuela.cpp edificioFabrica.cpp edificioMina.cpp edificioObelisco.cpp edificioPlantaElectrica.cpp edificioYacimiento.cpp main.cpp material.cpp materialMadera.cpp materialPiedra.cpp materialMetal.cpp recurso.cpp terreno.cpp menu.cpp 
	$(CC) $(FLAGS) $^ -o andypolis

clean:
	rm -vf *.o $(PROGRAM)

gdb: andypolis
	gdb ./andypolis

valgrind: andypolis
	valgrind --leak-check=full --show-leak-kinds=all --track-origins=yes -s ./andypolis