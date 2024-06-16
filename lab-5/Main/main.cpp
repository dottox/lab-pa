#include "Includes.cpp"
#include <iostream>

#include "../Clases/Apartamento.h"
#include "../Clases/Casa.h"

using namespace std;

void pruebaChat();
void pruebaList();
void pruebaPropiedad();

int main() {
  pruebaChat();
  pruebaList();
  pruebaPropiedad();
  //cout << "Sin ninguna prueba" << endl; 
}

void pruebaPropiedad() {
  DtDireccion direccion("Uruguay", "asdasd", 1234);

  cout << "aia" << endl;
  Inmobiliaria* inmobiliaria = new Inmobiliaria("asd", "asd", direccion);
  Interesado* interesado = new Interesado("asd", "asd", "asd", "asd", DtFecha(1, 1, 2000));


  DtDatosApartamento dtdatosapartamento = DtDatosApartamento(1, 2, 3, 4, true, direccion, 5, 6, "asd", 7);
  Apartamento* apartamento = new Apartamento(dtdatosapartamento, inmobiliaria);

  DtDatosCasa dtdatoscasa = DtDatosCasa(1, 2, 3, 4, true, direccion, 5, 6, "asd", 7, 8);
  Casa* casa = new Casa(dtdatoscasa, inmobiliaria);

  cout << "DtDato cod: " << dtdatosapartamento.getCodigo() << endl;
  cout << "DtDato ambientes: " << dtdatosapartamento.getCantAmbientes() << endl;
  cout << "DtDato: " << dtdatosapartamento.getCantDormitorios() << endl;
  cout << apartamento->getCodigo() << endl;
  cout << apartamento->getCantAmbientes() << endl;
  cout << apartamento->getCantDormitorios() << endl;
  cout << apartamento->getCantBanios() << endl;
  cout << apartamento->getGaraje() << endl;
  cout << apartamento->getDireccion().getCiudad() << endl;
  cout << apartamento->getDireccion().getCalle() << endl;
  cout << apartamento->getDireccion().getNumero() << endl;
  cout << apartamento->getMtsCuadradosEdificados() << endl;
  cout << apartamento->getMtsCuadradosTotales() << endl;
  cout << apartamento->getTipo() << endl;
  cout << apartamento->getPrecio() << endl;
  cout << "aia2" << endl;


  cout << casa->getCodigo() << endl;
  cout << casa->getCantAmbientes() << endl;
  cout << casa->getCantDormitorios() << endl;
  cout << casa->getCantBanios() << endl;
  cout << casa->getGaraje() << endl;
  cout << casa->getDireccion().getCiudad() << endl;
  cout << casa->getDireccion().getCalle() << endl;
  cout << casa->getDireccion().getNumero() << endl;
  cout << casa->getMtsCuadradosEdificados() << endl;
  cout << casa->getMtsCuadradosTotales() << endl;
  cout << casa->getTipo() << endl;
  cout << casa->getPrecio() << endl;


  Interesado* interesado2 = new Interesado("h@gmail.com", "asd", "asd", "asd", DtFecha(1, 1, 2000));
  Interesado* interesado3 = new Interesado("g@outlook.com", "asd", "asd", "asd", DtFecha(1, 1, 2000));
  Interesado* interesado4 = new Interesado("jk@live.com", "asd", "asd", "asd", DtFecha(1, 1, 2000));

  //Crear chat
  ICollectible* chat = apartamento->createChat(interesado2);
  ICollectible* chat2 = apartamento->createChat(interesado3);
  ICollectible* chat3 = apartamento->createChat(interesado4);

  ICollectible* chat4 = casa->createChat(interesado2);
  ICollectible* chat5 = casa->createChat(interesado3);
  ICollectible* chat6 = casa->createChat(interesado4);
  cout << "aia3" << endl;

  //Agregar chat a propiedad
  apartamento->addChat(chat);
  apartamento->addChat(chat2);
  apartamento->addChat(chat3);

  casa->addChat(chat4);
  casa->addChat(chat5);
  casa->addChat(chat6);

  cout << "aia4" << endl;
  apartamento->setChatActual(interesado2->getEmail());
  cout << "aia4.1" << endl;

  if (apartamento->getChatActual() != NULL) {
    apartamento->getChatActual()->addMensaje(apartamento->getChatActual()->createMensaje("Hola, ¿cómo estás?", "Pablo"));
    apartamento->getChatActual()->addMensaje(apartamento->getChatActual()->createMensaje("Bien, gracias. ¿Y tú?", "Manuel"));
  }

  cout << "aia5" << endl;

  DtInfo info = apartamento->getInfoPropiedad("h@gmail.com");
  DtInfo info2 = apartamento->getInfoPropiedad("g@outlook.com");
  DtInfo info3 = apartamento->getInfoPropiedad("jk@live.com");

  cout << info.getCodigo() << endl;
  cout << info.getDireccion().getCiudad() << endl;
  cout << info.getDireccion().getCalle() << endl;
  cout << info.getDireccion().getNumero() << endl;
  cout << info.getCantMensajes() << endl;

  cout << info2.getCodigo() << endl;
  cout << info2.getDireccion().getCiudad() << endl;
  cout << info2.getDireccion().getCalle() << endl;
  cout << info2.getDireccion().getNumero() << endl;
  cout << info2.getCantMensajes() << endl;

  cout << info3.getCodigo() << endl;
  cout << info3.getDireccion().getCiudad() << endl;
  cout << info3.getDireccion().getCalle() << endl;
  cout << info3.getDireccion().getNumero() << endl;
  cout << info3.getCantMensajes() << endl;

  delete inmobiliaria;
  delete interesado;
  delete interesado2;
  delete interesado3;
  delete interesado4;
  delete apartamento;
  delete casa;

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

  cout << "aia" << endl;
  ICollectible* mensaje = chat->createMensaje("Hola, ¿cómo estás?", "Pablo");
  ICollectible* mensaje2 = chat->createMensaje("Bien, gracias. ¿Y tú?", "Manuel");
  ICollectible* mensaje3 = chat->createMensaje("3También bien, gracias.", "Juan");
  ICollectible* mensaje4 = chat->createMensaje("4También bien, gracias.", "Juan2");
  ICollectible* mensaje5 = chat->createMensaje("5También bien, gracias.", "Juan3");
  ICollectible* mensaje6 = chat->createMensaje("6También bien, gracias.", "Juan4");
  ICollectible* mensaje7 = chat->createMensaje("7También bien, gracias.", "Juan5");

  cout << "aia2" << endl;

  chat->addMensaje(mensaje);
  chat->addMensaje(mensaje2);
  chat->addMensaje(mensaje3);

  cout << "aia3" << endl;

  ICollection* mensajes = chat->getMensajes();
  IIterator* it = mensajes->getIterator();
  DtMensaje* dtmensaje;
  while (it->hasCurrent()) {
    cout << "aia3.1" << endl;

    dtmensaje = dynamic_cast<DtMensaje*>(it->getCurrent());
    cout << "aia3.2" << endl;
    cout << dtmensaje->getTexto() << endl;
    it->next();

  }
  cout << "aia4" << endl;

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
  cout << "aia5" << endl;

  while (it->hasCurrent()) {
    cout << "aia5.1" << endl;

    dtmensaje = dynamic_cast<DtMensaje*>(it->getCurrent());
    cout << "aia5.1.1" << endl;

    cout << dtmensaje->getTexto() << endl;
    it->next();
    cout << "aia5.2" << endl;

  }
  cout << "aia6" << endl;


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
  delete it;
}