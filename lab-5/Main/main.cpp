#include "Includes.cpp"
#include <iostream>

using namespace std;

void pruebaChat();
void pruebaList();

int main() {
  pruebaChat();
}

void pruebaChat() {
  DtDireccion direccion("Uruguay", "asdasd", 1234);
  DtFecha fecha(1, 1, 2000);
  Inmobiliaria* inmobiliaria = new Inmobiliaria("asd", "asd", direccion);
  Interesado* interesado = new Interesado("asd", "asd", "asd", "asd", fecha);
  Chat* chat = new Chat(inmobiliaria, interesado);

  Usuario* usuarioinm = dynamic_cast<Usuario*>(inmobiliaria);
  Usuario* usuarioint = dynamic_cast<Usuario*>(interesado);

  cout << usuarioinm->getTipoUsuario() << endl;
  cout << usuarioint->getTipoUsuario() << endl;

  ICollectible* mensaje = chat->createMensaje("Hola, ¿cómo estás?", "Pablo");
  ICollectible* mensaje2 = chat->createMensaje("Bien, gracias. ¿Y tú?", "Manuel");
  ICollectible* mensaje3 = chat->createMensaje("3También bien, gracias.", "Juan");
  ICollectible* mensaje4 = chat->createMensaje("4También bien, gracias.", "Juan2");
  ICollectible* mensaje5 = chat->createMensaje("5También bien, gracias.", "Juan3");
  ICollectible* mensaje6 = chat->createMensaje("6También bien, gracias.", "Juan4");
  ICollectible* mensaje7 = chat->createMensaje("7También bien, gracias.", "Juan5");


  chat->addMensaje(mensaje);
  chat->addMensaje(mensaje2);
  chat->addMensaje(mensaje3);

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
  chat->addMensaje(mensaje5);
  chat->addMensaje(mensaje3);
  chat->addMensaje(mensaje2);
  chat->addMensaje(mensaje4);
  chat->addMensaje(mensaje7);
  chat->addMensaje(mensaje6);
  cout << "aia3" << endl;

  ICollection* msg = chat->seleccionarConversacion();

  cout << msg->getSize() << endl;
  cout << "aia4" << endl;
  it = msg->getIterator();
  while (it->hasCurrent()) {
    dtmensaje = dynamic_cast<DtMensaje*>(it->getCurrent());
    cout << dtmensaje->getTexto() << endl;
    it->next();
  }

  delete chat;
  delete inmobiliaria;
  delete interesado;
  delete mensaje;
  delete mensaje2;
  delete mensaje3;
  delete mensaje4;
  delete mensaje5;
  delete mensaje6;
  delete mensaje7;
  delete mensajes;
  delete msg;
  delete it;


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