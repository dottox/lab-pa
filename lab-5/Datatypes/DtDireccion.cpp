#include "DtDireccion.h"

DtDireccion::DtDireccion()
{
}

DtDireccion::DtDireccion(string calle, string ciudad, int nro)
{
  this->calle = calle;
  this->ciudad = ciudad;
  this->nro = nro;
}

string DtDireccion::getCalle() {
  return this->calle;
}

string DtDireccion::getCiudad() {
  return this->ciudad;
}

int DtDireccion::getNro() {
  return this->nro;
}

