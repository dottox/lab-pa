#include "DtInfoApartamento.h"

DtInfoApartamento::DtInfoApartamento(int codigo, int cantAmbientes, int cantDormitorios, int cantBanios, bool garaje, DtDireccion direccion, float mtsCuadradosEdificados, float mtsCuadradosTotales, string tipo, float precio) {
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

int DtInfoApartamento::getCodigo() {
  return this->codigo;
}

int DtInfoApartamento::getCantAmbientes() {
  return this->cantAmbientes;
}

int DtInfoApartamento::getCantDormitorios() {
  return this->cantDormitorios;
}

int DtInfoApartamento::getCantBanios() {
  return this->cantBanios;
}

float DtInfoApartamento::getMtsCuadradosEdificados() {
  return this->mtsCuadradosEdificados;
}

float DtInfoApartamento::getMtsCuadradosTotales() {
  return this->mtsCuadradosTotales;
}

string DtInfoApartamento::getTipo() {
  return this->tipo;
}

float DtInfoApartamento::getPrecio() {
  return this->precio;
}

DtDireccion DtInfoApartamento::getDireccion() {
  return this->direccion;
}

bool DtInfoApartamento::getGaraje() {
  return this->garaje;
}