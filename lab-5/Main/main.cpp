#include "Includes.cpp"
#include <iostream>

using namespace std;

void pruebaChat();
void pruebaList();

int main() {
  pruebaChat();
}

void pruebaChat() {
  cout << "a" << endl;

  DtDireccion direccion("Uruguay", "asdasd", 1234);

  cout << "a1.01" << endl;


  DtFecha fecha(1, 1, 2000);

  cout << "a1.1" << endl;

  Inmobiliaria* inmobiliaria = new Inmobiliaria("asd", "asd", direccion);

  cout << "a1.2" << endl;

  Interesado* interesado = new Interesado("asd", "asd", "asd", "asd", fecha);

  cout << "a1.3" << endl;

  Chat* chat = new Chat(inmobiliaria, interesado);

  cout << "a2" << endl;


  ICollectible* mensaje = chat->createMensaje("Hola, ¿cómo estás?", "Pablo");
  ICollectible* mensaje2 = chat->createMensaje("Bien, gracias. ¿Y tú?", "Manuel");
  ICollectible* mensaje3 = chat->createMensaje("También bien, gracias.", "Juan");

  cout << "a3" << endl;


  chat->addMensaje(mensaje);
  chat->addMensaje(mensaje2);
  chat->addMensaje(mensaje3);

  cout << "ai" << endl;


  ICollection* mensajes = chat->getMensajes();
  IIterator* it = mensajes->getIterator();
  DtMensaje* dtmensaje;
  while (it->hasCurrent()) {
    dtmensaje = dynamic_cast<DtMensaje*>(it->getCurrent());
    cout << dtmensaje->getTexto() << endl;
    it->next();
  }

  cout << "aia" << endl;
  chat->deleteMensajes();
  cout << "aia2" << endl;

  chat->addMensaje(mensaje);
  cout << "aia3" << endl;


  ICollection* msg = chat->getMensajes();
  cout << "aia4" << endl;
  it = msg->getIterator();
  while (it->hasCurrent()) {

    dtmensaje = dynamic_cast<DtMensaje*>(it->getCurrent());
    cout << dtmensaje->getTexto() << endl;
    it->next();
  }


}

void pruebaList() {
  ICollection* myList = new List();
  ICollectible* myInt = new Integer(5);
  ICollectible* myString = new String("Hello, World!");

  myList->add(myInt);
  myList->add(myString);

  // Iterar sobre la colección
  IIterator* it = myList->getIterator();
  while (it->hasCurrent()) {
    ICollectible* current = it->getCurrent();
    
    // Dynamic cast to integer or string
    Integer* intPtr = dynamic_cast<Integer*>(current);
    String* strPtr = dynamic_cast<String*>(current);
    if (intPtr != nullptr) {
      cout << intPtr->getValue() << endl;
    } else if (strPtr != nullptr) {
      cout << strPtr->getValue() << endl;
    }
    it->next();
  }

  delete myList;
  delete myInt;
  delete myString;
}