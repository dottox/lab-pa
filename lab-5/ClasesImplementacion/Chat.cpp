#include "../Clases/Chat.h"
#include "../ICollection/collections/List.h"

Chat::Chat(Inmobiliaria* inmobiliaria, Interesado* interesado)
{
  this->inmobiliaria = inmobiliaria;
  this->interesado = interesado;
  this->mensajes = new List();
  this->cantMensajes = 0;
}

ICollection* Chat::getMensajes()
{
  return this->mensajes;
}

Inmobiliaria* Chat::getInmobiliaria()
{
  return this->inmobiliaria;
}

Interesado* Chat::getInteresado()
{
  return this->interesado;
}

void Chat::setInmobiliaria(Inmobiliaria* inmobiliaria)
{
  this->inmobiliaria = inmobiliaria;
}

void Chat::setInteresado(Interesado* interesado)
{
  this->interesado = interesado;
}

void Chat::addMensaje(ICollectible* mensaje)
{
  this->mensajes->add(mensaje);
  this->cantMensajes++;
}

Chat::~Chat()
{
  // Iterar sobre los mensajes y eliminarlos.
}