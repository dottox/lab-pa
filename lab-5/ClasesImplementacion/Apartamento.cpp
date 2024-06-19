#include "../Clases/Apartamento.h"

Apartamento::Apartamento(DtDatosApartamento datosApartamento, Inmobiliaria* inmo) : Propiedad::Propiedad(
  datosApartamento.getCodigo(),
  datosApartamento.getCantAmbientes(),
  datosApartamento.getCantDormitorios(),
  datosApartamento.getCantBanios(),
  datosApartamento.getGaraje(),
  datosApartamento.getDireccion(),
  datosApartamento.getMtsCuadradosEdificados(),
  datosApartamento.getMtsCuadradosTotales(),
  datosApartamento.getTipo(),
  datosApartamento.getPrecio(),
  inmo
) {
}

void Apartamento::setDatos(DtDatosApartamento datosApartamento) {
  this->setCodigo(datosApartamento.getCodigo());
  this->setCantAmbientes(datosApartamento.getCantAmbientes());
  this->setCantDormitorios(datosApartamento.getCantDormitorios());
  this->setCantBanios(datosApartamento.getCantBanios());
  this->setGaraje(datosApartamento.getGaraje());
  this->setDireccion(datosApartamento.getDireccion());
  this->setMtsCuadradosEdificados(datosApartamento.getMtsCuadradosEdificados());
  this->setMtsCuadradosTotales(datosApartamento.getMtsCuadradosTotales());
  this->setTipo(datosApartamento.getTipo());
  this->setPrecio(datosApartamento.getPrecio());
}

Apartamento::~Apartamento() {
}