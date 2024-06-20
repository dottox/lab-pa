all: main.o
	g++ ICollectible.o ICollection.o IDictionary.o IIterator.o IKey.o OrderedKey.o Integer.o String.o List.o ListIterator.o ListNode.o OrderedDictionary.o OrderedDictionaryEntry.o DtFecha.o DtHora.o DtEdificio.o DtDepartamento.o DtZona.o DtDireccion.o DtMensaje.o DtDatos.o DtInfo.o DtDatosApartamento.o DtDatosCasa.o DtInmobiliaria.o DtChat.o Includes.o Mensaje.o Chat.o Usuario.o Interesado.o Inmobiliaria.o Administrador.o Propiedad.o Apartamento.o Casa.o Edificio.o Zona.o Departamento.o ISistema.o Sistema.o SistemaFabrica.o main.o -o programa

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

InicioDatatypes: ICollectible.o ICollection.o IDictionary.o IIterator.o IKey.o OrderedKey.o Integer.o String.o List.o ListIterator.o ListNode.o OrderedDictionary.o OrderedDictionaryEntry.o
	clear
	echo "Compilando datatypes..."

DtFecha.o: InicioDatatypes
	g++ -c ../Datatypes/DtFecha.cpp

DtHora.o:	InicioDatatypes
	g++ -c ../Datatypes/DtHora.cpp
	
DtEdificio.o: InicioDatatypes
	g++ -c ../Datatypes/DtEdificio.cpp

DtDepartamento.o: InicioDatatypes
	g++ -c ../Datatypes/DtDepartamento.cpp

DtZona.o: InicioDatatypes
	g++ -c ../Datatypes/DtZona.cpp

DtDireccion.o: InicioDatatypes
	g++ -c ../Datatypes/DtDireccion.cpp

DtMensaje.o: DtHora.o DtFecha.o
	g++ -c ../Datatypes/DtMensaje.cpp

DtInfo.o: DtDireccion.o
	g++ -c ../Datatypes/DtInfo.cpp

DtDatos.o: DtDireccion.o
	g++ -c ../Datatypes/DtDatos.cpp

DtDatosApartamento.o: DtDireccion.o
	g++ -c ../Datatypes/DtDatosApartamento.cpp

DtDatosCasa.o: DtDireccion.o
	g++ -c ../Datatypes/DtDatosCasa.cpp

DtInmobiliaria.o: DtDireccion.o
	g++ -c ../Datatypes/DtInmobiliaria.cpp

DtChat.o: InicioDatatypes
	g++ -c ../Datatypes/DtChat.cpp

# FIN COMPILACIÓN DE DATATYPES #

# INICIO COMPILACIÓN CLASES #

InicioClases: DtFecha.o DtHora.o DtEdificio.o DtDepartamento.o DtZona.o DtDireccion.o DtMensaje.o DtInfo.o DtDatos.o DtDatosApartamento.o DtDatosCasa.o DtInmobiliaria.o DtChat.o
	clear
	echo "Compilando clases..."

Mensaje.o: InicioClases
	g++ -c ../ClasesImplementacion/Mensaje.cpp

Chat.o: Mensaje.o
	g++ -c ../ClasesImplementacion/Chat.cpp

Usuario.o: InicioClases
	g++ -c ../ClasesImplementacion/Usuario.cpp

Interesado.o: Usuario.o
	g++ -c ../ClasesImplementacion/Interesado.cpp

Inmobiliaria.o: Usuario.o
	g++ -c ../ClasesImplementacion/Inmobiliaria.cpp

Administrador.o: Usuario.o
	g++ -c ../ClasesImplementacion/Administrador.cpp

Propiedad.o: Chat.o
	g++ -c ../ClasesImplementacion/Propiedad.cpp

Apartamento.o: Propiedad.o
	g++ -c ../ClasesImplementacion/Apartamento.cpp
	
Casa.o: Propiedad.o
	g++ -c ../ClasesImplementacion/Casa.cpp

Edificio.o: Apartamento.o
	g++ -c ../ClasesImplementacion/Edificio.cpp

Zona.o: Edificio.o Propiedad.o
	g++ -c ../ClasesImplementacion/Zona.cpp

Departamento.o: Zona.o
	g++ -c ../ClasesImplementacion/Departamento.cpp

ISistema.o: Departamento.o
	g++ -c ../ClasesImplementacion/ISistema.cpp

Sistema.o: ISistema.o
	g++ -c ../ClasesImplementacion/Sistema.cpp

SistemaFabrica.o: ISistema.o Sistema.o
	g++ -c ../ClasesImplementacion/SistemaFabrica.cpp

# FIN COMPILACIÓN CLASES #

Includes.o: Mensaje.o Chat.o Usuario.o Interesado.o Inmobiliaria.o Administrador.o Propiedad.o Apartamento.o Casa.o Edificio.o Zona.o Departamento.o ISistema.o Sistema.o SistemaFabrica.o 
	g++ -c Includes.cpp

main.o: Includes.o
	g++ -c main.cpp

cleanPrograma:
	rm -f programa

clean:
	rm *.o

run:
	clear
	make cleanPrograma
	make
	make clean
	clear
	./programa