all: main.o
	g++ ICollectible.o ICollection.o IDictionary.o IIterator.o IKey.o OrderedKey.o Integer.o String.o List.o ListIterator.o ListNode.o OrderedDictionary.o OrderedDictionaryEntry.o Includes.o main.o -o programa

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

Includes.o: ICollectible.o ICollection.o IDictionary.o IIterator.o IKey.o OrderedKey.o Integer.o String.o List.o ListIterator.o ListNode.o OrderedDictionary.o OrderedDictionaryEntry.o
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