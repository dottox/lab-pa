#include "DtInmobiliaria.h"

DtInmobiliaria::DtInmobiliaria(string email, DtDireccion direccion) {
  this->email = email;
  this->direccion = direccion;
}

DtDireccion DtInmobiliaria::getDireccion() {
  return this->direccion;
}

string DtInmobiliaria::getEmail() {
  return this->email;
}

DtInmobiliaria::~DtInmobiliaria() {
}