#include "../Clases/Casa.h"


Casa::Casa(DtDatosCasa datos, Inmobiliaria* inmo) : Propiedad::Propiedad(datos.getCodigo(),datos.getCantAmbientes(),datos.getCantDormitorios(),datos.getCantBanios(),datos.getGaraje(),datos.getDireccion(),datos.getMtsCuadradosEdificados(),datos.getMtsCuadradosTotales(),datos.getTipo(),datos.getPrecio(),inmo) 
{
  this->mtsCuadradosVerdes = datos.getMtsCuadradosVerdes();
} 

float Casa::getMtsCuadradosVerdes() {
  return this->mtsCuadradosVerdes;
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

Casa::~Casa() {
}
