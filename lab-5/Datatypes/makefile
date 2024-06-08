all: DtFecha.o DtHora.o DtEdificio.o DtDepartamento.o DtZona.o DtDireccion.o DtMensaje.o DtInfoApartamento.o DtInfoCasa.o DtDatosApartamento.o DtDatosCasa.o main.o
	g++ DtFecha.o DtHora.o DtEdificio.o DtDepartamento.o DtZona.o DtDireccion.o DtMensaje.o DtInfoApartamento.o DtInfoCasa.o DtDatosApartamento.o DtDatosCasa.o main.o -o programa

DtFecha.o:
	g++ -c DtFecha.cpp

DtHora.o:
	g++ -c DtHora.cpp
	
DtEdificio.o:
	g++ -c DtEdificio.cpp

DtDepartamento.o:
	g++ -c DtDepartamento.cpp

DtZona.o:
	g++ -c DtZona.cpp

DtDireccion.o:
	g++ -c DtDireccion.cpp

DtMensaje.o: DtHora.o DtFecha.o
	g++ -c DtMensaje.cpp

DtInfoApartamento.o: DtDireccion.o
	g++ -c DtInfoApartamento.cpp

DtInfoCasa.o: DtDireccion.o
	g++ -c DtInfoCasa.cpp

DtDatosApartamento.o: DtDireccion.o
	g++ -c DtDatosApartamento.cpp

DtDatosCasa.o: DtDireccion.o
	g++ -c DtDatosCasa.cpp


main.o: DtFecha.o DtHora.o DtEdificio.o DtDepartamento.o DtZona.o DtDireccion.o DtMensaje.o DtInfoApartamento.o DtInfoCasa.o DtDatosApartamento.o DtDatosCasa.o
	g++ -c main.cpp

cleanPrograma:
	rm -f programa

clean:
	rm -f DtFecha.o DtHora.o DtEdificio.o DtDepartamento.o DtZona.o DtDireccion.o DtMensaje.o DtInfoApartamento.o DtInfoCasa.o DtDatosApartamento.o DtDatosCasa.o main.o

run:
	make cleanPrograma
	make
	make clean
	clear
	./programa