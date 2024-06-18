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
    DtMensaje* msg = extractDtMensajeFromCollectible(it->getCurrent());
    ret->add(msg);
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
void Chat::addMensaje(DtMensaje mensaje)
{
  // Se crea el mensaje y se guarda
  Mensaje* newMensaje = new Mensaje(mensaje.getFecha(), mensaje.getHora(), mensaje.getTexto(), mensaje.getEmisor());
  this->mensajes->add(newMensaje);
}

// Borra todos los mensajes, dejando la lista en NULL
void Chat::deleteMensajes()
{
  if (this->mensajes->isEmpty())
  {
    return;
  }

  delete this->mensajes;
  this->mensajes = new List();
}

// Selecciona los últimos 5 mensajes. Si hay menos de 5 mensajes, devuelve todos los mensajes.
ICollection* Chat::seleccionarConversacion()
{
  ICollection* ret = new List();
  IIterator* it = this->mensajes->getIterator();

  int cantMensajes = this->mensajes->getSize();

  if (cantMensajes <= 5) {
    while (it->hasCurrent()) {
      DtMensaje* msg = extractDtMensajeFromCollectible(it->getCurrent());
      ret->add(msg);
      it->next();
    }
  }
  else {
    for (int i = 0; i < cantMensajes - 5; i++) {
      it->next();
    }

    while (it->hasCurrent()) {
      DtMensaje* msg = extractDtMensajeFromCollectible(it->getCurrent());
      ret->add(msg);
      it->next();
    }
  }

  delete it;
  return ret;
}

DtMensaje* Chat::extractDtMensajeFromCollectible(ICollectible* mensajeCollectible) {
  Mensaje* mensaje = dynamic_cast<Mensaje*>(mensajeCollectible);
  return new DtMensaje(mensaje->getMensaje().getFecha(), mensaje->getMensaje().getHora(), mensaje->getMensaje().getTexto(), mensaje->getMensaje().getEmisor());
}

// Destructor de la clase Chat
Chat::~Chat()
{
  deleteMensajes();
}