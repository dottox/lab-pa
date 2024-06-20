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

void Apartamento::setDatos(DtDatosApartamento datos) {
  this->codigo = datos.getCodigo();
  this->cantAmbientes = datos.getCantAmbientes();
  this->cantDormitorios = datos.getCantDormitorios();
  this->cantBanios = datos.getCantBanios();
  this->garaje = datos.getGaraje();
  this->direccion = datos.getDireccion();
  this->mtsCuadradosEdificados = datos.getMtsCuadradosEdificados();
  this->mtsCuadradosTotales = datos.getMtsCuadradosTotales();
  this->tipo = datos.getTipo();
  this->precio = datos.getPrecio();
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