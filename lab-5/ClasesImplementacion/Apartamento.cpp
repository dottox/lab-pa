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
  this->codigo = datosApartamento.getCodigo();
  this->cantAmbientes = datosApartamento.getCantAmbientes();
  this->cantDormitorios = datosApartamento.getCantDormitorios();
  this->cantBanios = datosApartamento.getCantBanios();
  this->garaje = datosApartamento.getGaraje();
  this->direccion = datosApartamento.getDireccion();
  this->mtsCuadradosEdificados = datosApartamento.getMtsCuadradosEdificados();
  this->mtsCuadradosTotales = datosApartamento.getMtsCuadradosTotales();
  this->tipo = datosApartamento.getTipo();
  this->precio = datosApartamento.getPrecio();
}

Apartamento::~Apartamento() {
}