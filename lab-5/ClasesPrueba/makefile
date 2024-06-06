all: Animal.o Gato.o Perro.o Persona.o main.o ISistema.o Sistema.o Factory.o
	g++ Animal.o Gato.o Perro.o Persona.o main.o ISistema.o Sistema.o Factory.o -o programa

Animal.o:
	g++ -c Animal.cpp

Gato.o: Animal.o
	g++ -c Gato.cpp

Perro.o: Animal.o
	g++ -c Perro.cpp	

Persona.o:	Animal.o Gato.o Perro.o
	g++ -c Persona.cpp

ISistema.o: ISistema.h
	g++ -c ISistema.cpp

Sistema.o: ISistema.o Sistema.h
	g++ -c Sistema.cpp

Factory.o: Factory.h ISistema.o Sistema.o
	g++ -c Factory.cpp
	
main.o: ISistema.o Factory.o
	g++ -c main.cpp

clean:
	rm -f Animal.o Gato.o Perro.o Persona.o main.o ISistema.o Sistema.o Factory.o programa
run:
	make clean
	make
	clear
	./programa