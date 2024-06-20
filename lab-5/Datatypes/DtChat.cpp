#include "DtChat.h"

DtChat::DtChat(string interesado, int propiedad, int cantMensajes)
{
  this->interesado = interesado;
  this->propiedad = propiedad;
  this->cantMensajes = cantMensajes;
}

string DtChat::getInteresado()
{
  return this->interesado;
}

int DtChat::getPropiedad()
{
  return this->propiedad;
}

int DtChat::getCantMensajes()
{
  return this->cantMensajes;
}

DtChat::~DtChat()
{
}