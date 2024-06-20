#include "DtDatosCasa.h"

DtDatosCasa::DtDatosCasa(
  int codigo, 
  int cantAmbientes, 
  int cantDormitorios, 
  int cantBanios, 
  bool garaje, 
  DtDireccion direccion, 
  float mtsCuadradosEdificados, 
  float mtsCuadradosTotales, 
  string tipo, 
  float precio, 
  float mtsCuadradosVerdes
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
) {
  this->mtsCuadradosVerdes = mtsCuadradosVerdes;
}

float DtDatosCasa::getMtsCuadradosVerdes() {
  return this->mtsCuadradosVerdes;
}

DtDatosCasa::~DtDatosCasa() {
}
