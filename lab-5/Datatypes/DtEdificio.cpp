#include "DtEdificio.h"

DtEdificio::DtEdificio(string nombre, int cantPisos, float gastosComunes) {
  this->nombre = nombre;
  this->cantPisos = cantPisos;
  this->gastosComunes = gastosComunes;
}

string DtEdificio::getNombre() {
  return this->nombre;
}

int DtEdificio::getCantPisos() {
  return this->cantPisos;
}

float DtEdificio::getGastosComunes() {
  return this->gastosComunes;
}

DtEdificio::~DtEdificio() {
}