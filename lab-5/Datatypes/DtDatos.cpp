#include "DtDatos.h"

DtDatos::DtDatos(int, int, int, int, bool, DtDireccion, float, float, string, float)
{
  this->codigo = codigo;
  this->cantAmbientes = cantAmbientes;
  this->cantDormitorios = cantDormitorios;
  this->cantBanios = cantBanios;
  this->garaje = garaje;
  this->direccion = direccion;
  this->mtsCuadradosEdificados = mtsCuadradosEdificados;
  this->mtsCuadradosTotales = mtsCuadradosTotales;
  this->tipo = tipo;
  this->precio = precio;
}