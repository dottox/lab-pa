#include "DtMensaje.h"

DtMensaje::DtMensaje(DtFecha fecha, DtHora hora, string texto) {
  this->fecha = fecha;
  this->hora = hora;
  this->texto = texto;
}

DtFecha DtMensaje::getFecha() {
  return this->fecha;
}

DtHora DtMensaje::getHora() {
  return this->hora;
}

string DtMensaje::getTexto() {
  return this->texto;
}

DtMensaje::~DtMensaje() {
}