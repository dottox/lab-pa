#include "DtDatosApartamento.h"

DtDatosApartamento::DtDatosApartamento(int codigo, int cantAmbientes, int cantDormitorios, int cantBanios, bool garaje, DtDireccion direccion, float mtsCuadradosEdificados, float mtsCuadradosTotales, string tipo, float precio) {
  this->codigo = codigo;
  this->cantAmbientes = cantAmbientes;
  this->cantDormitorios = cantDormitorios;
  this->cantBanios = cantBanios;
  this->garaje = garaje;
  this->direccion = direccion;
  this->mtsCuadradosEdificados = mtsCuadradosEdificados;
  this->mtsCuadradosTotales = mtsCuadradosTotales;
  this->tipo = tipo;
  this->precio = precio;
}

int DtDatosApartamento::getCodigo() {
  return this->codigo;
}

int DtDatosApartamento::getCantAmbientes() {
  return this->cantAmbientes;
}

int DtDatosApartamento::getCantDormitorios() {
  return this->cantDormitorios;
}

int DtDatosApartamento::getCantBanios() {
  return this->cantBanios;
}

float DtDatosApartamento::getMtsCuadradosEdificados() {
  return this->mtsCuadradosEdificados;
}

float DtDatosApartamento::getMtsCuadradosTotales() {
  return this->mtsCuadradosTotales;
}

string DtDatosApartamento::getTipo() {
  return this->tipo;
}

float DtDatosApartamento::getPrecio() {
  return this->precio;
}

DtDireccion DtDatosApartamento::getDireccion() {
  return this->direccion;
}

bool DtDatosApartamento::getGaraje() {
  return this->garaje;
}