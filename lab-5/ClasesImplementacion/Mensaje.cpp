#include "../Clases/Mensaje.h"

Mensaje::Mensaje(DtFecha fecha, DtHora hora, string texto) {
  this->fecha = fecha;
  this->hora = hora;
  this->texto = texto;
}

DtMensaje Mensaje::getMensaje() {
  return DtMensaje(this->fecha, this->hora, this->texto);
}
