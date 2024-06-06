all: Hora.o Fecha.o main.o
	g++ Hora.o Fecha.o main.o -o programa

Fecha.o:
	g++ -c Fecha.cpp

Hora.o:
	g++ -c Hora.cpp
	
main.o: Fecha.o Hora.o
	g++ -c main.cpp

clean:
	rm -f Hora.o Fecha.o main.o programa
run:
	make clean
	make
	clear
	./programa