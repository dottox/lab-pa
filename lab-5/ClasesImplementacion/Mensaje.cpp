#include "../Clases/Mensaje.h"

Mensaje::Mensaje(
    DtFecha fecha, 
    DtHora hora, 
    string texto, 
    string emisor
  ) {
  this->fecha = fecha;
  this->hora = hora;
  this->texto = texto;
  this->emisor = emisor;
}

DtMensaje Mensaje::getMensaje() {
  return DtMensaje(this->fecha, this->hora, this->texto, this->emisor);
}

Mensaje::~Mensaje()
{
}
