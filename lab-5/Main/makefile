all: main.o
	g++ ICollectible.o ICollection.o IDictionary.o IIterator.o IKey.o OrderedKey.o Integer.o String.o List.o ListIterator.o ListNode.o OrderedDictionary.o OrderedDictionaryEntry.o DtFecha.o DtHora.o DtEdificio.o DtDepartamento.o DtZona.o DtDireccion.o DtMensaje.o DtDatos.o DtDatosApartamento.o DtDatosCasa.o Includes.o Mensaje.o Chat.o Usuario.o Inmobiliaria.o Interesado.o main.o -o programa

# INICIO COMPILACIÓN DE ICOLLECTION #

ICollectible.o: 
	g++ -c ../ICollection/interfaces/ICollectible.cpp

ICollection.o:
	g++ -c ../ICollection/interfaces/ICollection.cpp

IDictionary.o:
	g++ -c ../ICollection/interfaces/IDictionary.cpp

IIterator.o:
	g++ -c ../ICollection/interfaces/IIterator.cpp

IKey.o:
	g++ -c ../ICollection/interfaces/IKey.cpp

OrderedKey.o: IKey.o
	g++ -c ../ICollection/interfaces/OrderedKey.cpp

Integer.o: ICollectible.o OrderedKey.o
	g++ -c ../ICollection/Integer.cpp

String.o: ICollectible.o OrderedKey.o
	g++ -c ../ICollection/String.cpp

List.o: ICollection.o
	g++ -c ../ICollection/collections/List.cpp

ListIterator.o: IIterator.o
	g++ -c ../ICollection/collections/ListIterator.cpp

ListNode.o:
	g++ -c ../ICollection/collections/ListNode.cpp

OrderedDictionary.o: IDictionary.o
	g++ -c ../ICollection/collections/OrderedDictionary.cpp

OrderedDictionaryEntry.o:
	g++ -c ../ICollection/collections/OrderedDictionaryEntry.cpp

# FIN COMPILACIÓN DE ICOLLECTION #

# INICIO COMPILACIÓN DE DATATYPES #

DtFecha.o:
	g++ -c ../Datatypes/DtFecha.cpp

DtHora.o:
	g++ -c ../Datatypes/DtHora.cpp
	
DtEdificio.o:
	g++ -c ../Datatypes/DtEdificio.cpp

DtDepartamento.o:
	g++ -c ../Datatypes/DtDepartamento.cpp

DtZona.o:
	g++ -c ../Datatypes/DtZona.cpp

DtDireccion.o:
	g++ -c ../Datatypes/DtDireccion.cpp

DtMensaje.o: DtHora.o DtFecha.o
	g++ -c ../Datatypes/DtMensaje.cpp

DtDatos.o: DtDireccion.o
	g++ -c ../Datatypes/DtDatos.cpp

DtDatosApartamento.o: DtDireccion.o
	g++ -c ../Datatypes/DtDatosApartamento.cpp

DtDatosCasa.o: DtDireccion.o
	g++ -c ../Datatypes/DtDatosCasa.cpp

# FIN COMPILACIÓN DE DATATYPES #

# INICIO COMPILACIÓN CLASES #

Mensaje.o:
	g++ -c ../ClasesImplementacion/Mensaje.cpp

Chat.o: Mensaje.o
	g++ -c ../ClasesImplementacion/Chat.cpp

Usuario.o: ICollectible.o
	g++ -c ../ClasesImplementacion/Usuario.cpp

Interesado.o: DtFecha.o Usuario.o
	g++ -c ../ClasesImplementacion/Interesado.cpp

Inmobiliaria.o: Usuario.o DtDireccion.o DtFecha.o ICollectible.o ICollection.o
	g++ -c ../ClasesImplementacion/Inmobiliaria.cpp

# FIN COMPILACIÓN CLASES #

Includes.o: ICollectible.o ICollection.o IDictionary.o IIterator.o IKey.o OrderedKey.o Integer.o String.o List.o ListIterator.o ListNode.o OrderedDictionary.o OrderedDictionaryEntry.o DtFecha.o DtHora.o DtEdificio.o DtDepartamento.o DtZona.o DtDireccion.o DtMensaje.o DtDatos.o DtDatosApartamento.o DtDatosCasa.o Mensaje.o Chat.o Usuario.o Inmobiliaria.o Interesado.o
	g++ -c Includes.cpp

main.o: Includes.o
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