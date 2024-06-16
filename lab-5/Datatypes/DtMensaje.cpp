#include "DtMensaje.h"

DtMensaje::DtMensaje(DtFecha fecha, DtHora hora, string texto, string emisor) {
  this->fecha = fecha;
  this->hora = hora;
  this->texto = texto;
  this->emisor = emisor;
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

string DtMensaje::getEmisor() {
  return this->emisor;
}

DtMensaje::~DtMensaje() {
}