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

DtDatos Apartamento::getDatos() {
  return DtDatosApartamento(
    this->getCodigo(),
    this->getCantAmbientes(),
    this->getCantDormitorios(),
    this->getCantBanios(),
    this->getGaraje(),
    this->getDireccion(),
    this->getMtsCuadradosEdificados(),
    this->getMtsCuadradosTotales(),
    this->getTipo(),
    this->getPrecio()
  );
}

Apartamento::~Apartamento() {
}