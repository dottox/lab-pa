#include "DtDatosApartamento.h"

DtDatosApartamento::DtDatosApartamento(
    int codigo, 
    int cantAmbientes, 
    int cantDormitorios, 
    int cantBanios, 
    bool garaje, 
    DtDireccion direccion, 
    float mtsCuadradosEdificados, 
    float mtsCuadradosTotales, 
    string tipo, 
    float precio
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
) { }

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