all: DtFecha.o DtHora.o DtEdificio.o DtDepartamento.o DtZona.o DtDireccion.o DtMensaje.o DtInfoApartamento.o DtInfoCasa.o DtDatosApartamento.o DtDatosCasa.o ICollectible.o ICollection.o main.o Mensaje.o List.o Inmobiliaria.o Interesado.o Chat.o
	g++ DtFecha.o DtHora.o DtEdificio.o DtDepartamento.o DtZona.o DtDireccion.o DtMensaje.o DtInfoApartamento.o DtInfoCasa.o DtDatosApartamento.o DtDatosCasa.o ICollectible.o ICollection.o main.o Mensaje.o List.o Inmobiliaria.o Interesado.o Chat.o -o programa

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

ICollectible.o:
	g++ -c ../ICollection/interfaces/ICollectible.cpp

ICollection.o: ICollectible.o
	g++ -c ../ICollection/interfaces/ICollection.cpp

ListNode.o:
	g++ -c ../ICollection/collections/ListNode.cpp

List.o: ICollectible.o ICollection.o ListNode.o
	g++ -c ../ICollection/collections/List.cpp

Mensaje.o: DtMensaje.o DtFecha.o DtHora.o
	g++ -c ../ClasesImplementacion/Mensaje.cpp

Inmobiliaria.o: DtDireccion.o ICollection.o
	g++ -c ../ClasesImplementacion/Inmobiliaria.cpp

Interesado.o: DtFecha.o
	g++ -c ../ClasesImplementacion/Interesado.cpp

Chat.o: Mensaje.o Inmobiliaria.o Interesado.o ICollection.o ICollectible.o List.o
	g++ -c ../ClasesImplementacion/Chat.cpp


main.o: DtFecha.o DtHora.o DtEdificio.o DtDepartamento.o DtZona.o DtDireccion.o DtMensaje.o DtInfoApartamento.o DtInfoCasa.o DtDatosApartamento.o DtDatosCasa.o ICollectible.o ICollection.o Mensaje.o Inmobiliaria.o Interesado.o Chat.o
	g++ -c main.cpp

cleanPrograma:
	rm -f programa

clean:
	rm *.o

run:
	make cleanPrograma
	make
	make clean
	clear
	./programa