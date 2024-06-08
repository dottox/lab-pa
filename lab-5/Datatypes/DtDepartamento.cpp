#include "DtDepartamento.h"

DtDepartamento::DtDepartamento(char codigo, string nombre) {
  this->codigo = codigo;
  this->nombre = nombre;
}

int DtDepartamento::getCodigo() {
  return this->codigo;
}

string DtDepartamento::getNombre() {
  return this->nombre;
}