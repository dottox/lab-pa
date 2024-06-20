#include "DtDatosApartamento.h"

DtDatosApartamento::DtDatosApartamento(
    int codigo, 
    int cantAmbientes, 
    int cantDormitorios, 
    int cantBanios, 
    bool garaje, 
    DtDireccion direccion, 
    float mtsCuadradosEdificados, 
    float mtsCuadradosTotales, 
    string tipo, 
    float precio
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
) { }

DtDatosApartamento::~DtDatosApartamento() { }