#include "DtDatos.h"

DtDatos::DtDatos(int codigo, int cantAmbientes, int cantDormitorios, int cantBanios, bool garaje, DtDireccion direccion, float mtsCuadradosEdificados, float mtsCuadradosTotales, string tipo, float precio)
{
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

DtDatos::DtDatos(int cantAmbientes, int cantDormitorios, int cantBanios, bool garaje, DtDireccion direccion, float mtsCuadradosEdificados, float mtsCuadradosTotales, string tipo, float precio)
{
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

int DtDatos::getCodigo() {
  return this->codigo;
}

int DtDatos::getCantAmbientes() {
  return this->cantAmbientes;
}

int DtDatos::getCantDormitorios() {
  return this->cantDormitorios;
}

int DtDatos::getCantBanios() {
  return this->cantBanios;
}

float DtDatos::getMtsCuadradosEdificados() {
  return this->mtsCuadradosEdificados;
}

float DtDatos::getMtsCuadradosTotales() {
  return this->mtsCuadradosTotales;
}

string DtDatos::getTipo() {
  return this->tipo;
}

float DtDatos::getPrecio() {
  return this->precio;
}

DtDireccion DtDatos::getDireccion() {
  return this->direccion;
}

bool DtDatos::getGaraje() {
  return this->garaje;
}

DtDatos::~DtDatos()
{
}