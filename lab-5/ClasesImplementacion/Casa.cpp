#include "../Clases/Casa.h"


Casa::Casa(DtDatosCasa datos, Inmobiliaria* inmo) : Propiedad::Propiedad(datos.getCodigo(),datos.getCantAmbientes(),datos.getCantDormitorios(),datos.getCantBanios(),datos.getGaraje(),datos.getDireccion(),datos.getMtsCuadradosEdificados(),datos.getMtsCuadradosTotales(),datos.getTipo(),datos.getPrecio(),inmo) 
{
  this->mtsCuadradosVerdes = datos.getMtsCuadradosVerdes();
} 

void Casa::setDatos(DtDatosCasa datos) {
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

DtDatos Casa::getDatos(){
  return DtDatosCasa(
    this->getCodigo(),
    this->getCantAmbientes(),
    this->getCantDormitorios(),
    this->getCantBanios(),
    this->getGaraje(),
    this->getDireccion(),
    this->getMtsCuadradosEdificados(),
    this->getMtsCuadradosTotales(),
    this->getTipo(),
    this->getPrecio(),
    this->getMtsCuadradosVerdes()
  );
}

float Casa::getMtsCuadradosVerdes() {
  return this->mtsCuadradosVerdes;
}

void Casa::setMtsCuadradosVerdes(float mtsCuadradosVerdes) {
  this->mtsCuadradosVerdes = mtsCuadradosVerdes;
}

Casa::~Casa() {
}
