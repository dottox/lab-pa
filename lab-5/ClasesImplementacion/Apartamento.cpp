#include "../Clases/Administrador.h"

Apartamento::Apartamento(DtDatosApartamento* datosApartamento) : Propiedad::Propiedad(
  datosApartamento->getCodigo(),
  datosApartamento->getCantAmbientes(),
  datosApartamento->getCantDormitorios(),
  datosApartamento->getCantBanios(),
  datosApartamento->getGaraje(),
  datosApartamento->getDireccion(),
  datosApartamento->getMtsCuadradosEdificados(),
  datosApartamento->getMtsCuadradosTotales(),
  datosApartamento->getTipo(),
  datosApartamento->getPrecio()
) {
}

Apartamento::~Apartamento() {
}