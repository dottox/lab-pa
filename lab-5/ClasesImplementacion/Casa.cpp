#include "../Clases/Casa.h"

Casa::Casa(DtDatosCasa datos, Inmobiliaria* inmo) : Propiedad::Propiedad(
  datos.getCodigo(),
  datos.getCantAmbientes(),
  datos.getCantDormitorios(),
  datos.getCantBanios(),
  datos.getGaraje(),
  datos.getDireccion(),
  datos.getMtsCuadradosEdificados(),
  datos.getMtsCuadradosTotales(),
  datos.getTipo(),
  datos.getPrecio(),
  inmo
) {
  this->mtsCuadradosVerdes = datos.getMtsCuadradosVerdes();
} 

float Casa::getMtsCuadradosVerdes() {
  return this->mtsCuadradosVerdes;
}

void Casa::setDatos(DtDatosCasa) {
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
  this->mtsCuadradosVerdes = datos.getMtsCuadradosVerdes();
}

Casa::~Casa() {
}
