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

Apartamento::~Apartamento() {
}