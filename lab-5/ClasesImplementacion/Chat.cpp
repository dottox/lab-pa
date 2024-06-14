#include "../Clases/Chat.h"

#include "../ICollection/collections/List.h"
#include "../Datatypes/DtMensaje.h"
#include "../Datatypes/DtHora.h"
#include "../Datatypes/DtFecha.h"


// Constructor de la clase Chat
Chat::Chat(Inmobiliaria* inmobiliaria, Interesado* interesado)
{
  this->inmobiliaria = inmobiliaria;
  this->interesado = interesado;
  this->mensajes = new List();
}

// Devuelve los mensajes del chat a modo de ICollection*
ICollection* Chat::getMensajes()
{
  ICollection* ret = new List();
  IIterator* it = this->mensajes->getIterator();
  while (it->hasCurrent())
  {
    Mensaje* mensaje = dynamic_cast<Mensaje*>(it->getCurrent());
    ret->add(mensaje->getMensaje());
    it->next();
  }
  delete it;
  return ret;
}

// Devuelve la inmobiliaria del chat
Inmobiliaria* Chat::getInmobiliaria()
{
  return this->inmobiliaria;
}

// Devuelve el interesado del chat
Interesado* Chat::getInteresado()
{
  return this->interesado;
}

// Setea la inmobiliaria del chat
void Chat::setInmobiliaria(Inmobiliaria* inmobiliaria)
{
  this->inmobiliaria = inmobiliaria;
}

// Setea el interesado del chat
void Chat::setInteresado(Interesado* interesado)
{
  this->interesado = interesado;
}

// Añade el mensaje a la lista
void Chat::addMensaje(ICollectible* mensaje)
{
  this->mensajes->add(mensaje);
}

// Crea un mensaje con los datos pasados por parámetro y la fecha y hora actual
Mensaje* Chat::createMensaje(string texto, string emisor)
{
  DtFecha fecha;
  DtHora hora;

  return new Mensaje(fecha, hora, texto, emisor);
}

// Borra todos los mensajes, dejando la lista en NULL
void Chat::deleteMensajes()
{
  if (this->mensajes->isEmpty())
  {
    return;
  }

  IIterator* it = this->mensajes->getIterator();
  while (it->hasCurrent())
  {
    this->mensajes->remove(it->getCurrent());
    it = this->mensajes->getIterator();
  }
  delete it;
}

// Selecciona los últimos 5 mensajes. Si hay menos de 5 mensajes, devuelve todos los mensajes.
ICollection* Chat::seleccionarConversacion()
{
  ICollection* ret = new List();
  IIterator* it = this->mensajes->getIterator();

  int cantMensajes = this->mensajes->getSize();

  if (cantMensajes <= 5) {
    while (it->hasCurrent()) {
      Mensaje* mensaje = dynamic_cast<Mensaje*>(it->getCurrent());
      ret->add(mensaje->getMensaje());
      it->next();
    }
  }
  else {
    for (int i = 0; i < cantMensajes - 5; i++) {
      it->next();
    }

    while (it->hasCurrent()) {
      Mensaje* mensaje = dynamic_cast<Mensaje*>(it->getCurrent());
      ret->add(mensaje->getMensaje());
      it->next();
    }
  }

  delete it;
  return ret;
}

// Destructor de la clase Chat
Chat::~Chat()
{
  deleteMensajes();
}