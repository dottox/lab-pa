#include "DtZona.h"

DtZona::DtZona(int codigo, string nombre) {
  this->codigo = codigo;
  this->nombre = nombre;
}

int DtZona::getCodigo() {
  return this->codigo;
}

string DtZona::getNombre() {
  return this->nombre;
}