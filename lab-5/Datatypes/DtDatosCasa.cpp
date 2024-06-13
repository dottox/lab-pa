#include "DtDatosCasa.h"

DtDatosCasa::DtDatosCasa(
  int codigo, 
  int cantAmbientes, 
  int cantDormitorios, 
  int cantBanios, 
  bool garaje, 
  DtDireccion direccion, 
  float mtsCuadradosEdificados, 
  float mtsCuadradosTotales, 
  string tipo, 
  float precio, 
  float mtsCuadradosVerdes
) 
: DtDatos::DtDatos(
  codigo, 
  cantAmbientes, 
  cantDormitorios, 
  cantBanios, 
  garaje, 
  direccion, 
  mtsCuadradosEdificados, 
  mtsCuadradosTotales, 
  tipo, 
  precio
) {
  this->mtsCuadradosVerdes = mtsCuadradosVerdes;
}

int DtDatosCasa::getCodigo() {
  return this->codigo;
}

int DtDatosCasa::getCantAmbientes() {
  return this->cantAmbientes;
}

int DtDatosCasa::getCantDormitorios() {
  return this->cantDormitorios;
}

int DtDatosCasa::getCantBanios() {
  return this->cantBanios;
}

float DtDatosCasa::getMtsCuadradosEdificados() {
  return this->mtsCuadradosEdificados;
}

float DtDatosCasa::getMtsCuadradosTotales() {
  return this->mtsCuadradosTotales;
}

float DtDatosCasa::getMtsCuadradosVerdes() {
  return this->mtsCuadradosVerdes;
}

string DtDatosCasa::getTipo() {
  return this->tipo;
}

float DtDatosCasa::getPrecio() {
  return this->precio;
}

DtDireccion DtDatosCasa::getDireccion() {
  return this->direccion;
}

bool DtDatosCasa::getGaraje() {
  return this->garaje;
}
