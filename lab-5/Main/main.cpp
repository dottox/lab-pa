#include "Includes.cpp"
#include <iostream>

using namespace std;

void pruebaChat();
void pruebaList();
void pruebaPropiedad();

int main() {
  cout << "Sin ninguna prueba" << endl; 
}

void pruebaPropiedad() {
  DtDireccion direccion("Uruguay", "asdasd", 1234);

  cout << "aia" << endl;
  Inmobiliaria* inmobiliaria = new Inmobiliaria("asd", "asd", direccion);
  Interesado* interesado = new Interesado("asd", "asd", "asd", "asd", DtFecha(1, 1, 2000));
  
  
  Propiedad* propiedad = new Propiedad(1, 2, 3, 4, true, direccion, 5, 6, "asd", 7, inmobiliaria);

  cout << propiedad->getCodigo() << endl;
  cout << propiedad->getCantAmbientes() << endl;
  cout << propiedad->getCantDormitorios() << endl;
  cout << propiedad->getCantBanios() << endl;
  cout << propiedad->getGaraje() << endl;
  cout << propiedad->getDireccion().getCiudad() << endl;
  cout << propiedad->getDireccion().getCalle() << endl;
  cout << propiedad->getDireccion().getNumero() << endl;
  cout << propiedad->getMtsCuadradosEdificados() << endl;
  cout << propiedad->getMtsCuadradosTotales() << endl;
  cout << propiedad->getTipo() << endl;
  cout << propiedad->getPrecio() << endl;
  cout << "aia2" << endl;


  Interesado* interesado2 = new Interesado("h@gmail.com", "asd", "asd", "asd", DtFecha(1, 1, 2000));
  Interesado* interesado3 = new Interesado("g@outlook.com", "asd", "asd", "asd", DtFecha(1, 1, 2000));
  Interesado* interesado4 = new Interesado("jk@live.com", "asd", "asd", "asd", DtFecha(1, 1, 2000));

  //Crear chat
  ICollectible* chat = propiedad->createChat(interesado2);
  ICollectible* chat2 = propiedad->createChat(interesado3);
  ICollectible* chat3 = propiedad->createChat(interesado4);
  cout << "aia3" << endl;

  //Agregar chat a propiedad
  propiedad->addChat(chat);
  propiedad->addChat(chat2);
  propiedad->addChat(chat3);

  cout << "aia4" << endl;
  propiedad->setChatActual(interesado2->getEmail());
  cout << "aia4.1" << endl;

  if (propiedad->getChatActual() != NULL) {
    propiedad->getChatActual()->addMensaje(propiedad->getChatActual()->createMensaje("Hola, ¿cómo estás?", "Pablo"));
    propiedad->getChatActual()->addMensaje(propiedad->getChatActual()->createMensaje("Bien, gracias. ¿Y tú?", "Manuel"));
  }

  cout << "aia5" << endl;

  DtInfo* info = propiedad->getInfoPropiedad("h@gmail.com");
  DtInfo* info2 = propiedad->getInfoPropiedad("g@outlook.com");
  DtInfo* info3 = propiedad->getInfoPropiedad("jk@live.com");

  cout << info->getCodigo() << endl;
  cout << info->getDireccion().getCiudad() << endl;
  cout << info->getDireccion().getCalle() << endl;
  cout << info->getDireccion().getNumero() << endl;
  cout << info->getCantMensajes() << endl;

  cout << info2->getCodigo() << endl;
  cout << info2->getDireccion().getCiudad() << endl;
  cout << info2->getDireccion().getCalle() << endl;
  cout << info2->getDireccion().getNumero() << endl;
  cout << info2->getCantMensajes() << endl;

  cout << info3->getCodigo() << endl;
  cout << info3->getDireccion().getCiudad() << endl;
  cout << info3->getDireccion().getCalle() << endl;
  cout << info3->getDireccion().getNumero() << endl;
  cout << info3->getCantMensajes() << endl;


  delete propiedad;

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

  chat->deleteMensajes();

  chat->addMensaje(mensaje);
  chat->addMensaje(mensaje5);
  chat->addMensaje(mensaje3);
  chat->addMensaje(mensaje2);
  chat->addMensaje(mensaje4);
  chat->addMensaje(mensaje7);
  chat->addMensaje(mensaje6);

  ICollection* msg = chat->seleccionarConversacion();

  cout << msg->getSize() << endl;
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