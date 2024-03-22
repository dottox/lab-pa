all: Animal.o Gato.o Perro.o Persona.o Veterinaria.o main.o 
	g++ Animal.o Gato.o Perro.o Persona.o Veterinaria.o main.o -o programa

Animal.o:
	g++ -c Animal.cpp

Gato.o: Animal.o
	g++ -c Gato.cpp

Perro.o: Animal.o
	g++ -c Perro.cpp	

Persona.o:	Animal.o Gato.o Perro.o
	g++ -c Persona.cpp

Veterinaria.o: Animal.o Gato.o Perro.o Persona.o
	g++ -c Veterinaria.cpp

main.o: 
	g++ -c main.cpp

clean:
	rm -f Animal.o Gato.o Perro.o Persona.o Veterinaria.o main.o programa
run:
	make clean
	make
	cls
	./programa