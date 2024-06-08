#include "DtInfoCasa.h"

DtInfoCasa::DtInfoCasa(int codigo, int cantAmbientes, int cantDormitorios, int cantBanios, bool garaje, DtDireccion direccion, float mtsCuadradosEdificados, float mtsCuadradosTotales, float mtsCuadradosVerdes, string tipo, float precio)
{
  this->codigo = codigo;
  this->cantAmbientes = cantAmbientes;
  this->cantDormitorios = cantDormitorios;
  this->cantBanios = cantBanios;
  this->garaje = garaje;
  this->direccion = direccion;
  this->mtsCuadradosEdificados = mtsCuadradosEdificados;
  this->mtsCuadradosTotales = mtsCuadradosTotales;
  this->mtsCuadradosVerdes = mtsCuadradosVerdes;
  this->tipo = tipo;
  this->precio = precio;
}

int DtInfoCasa::getCodigo()
{
  return this->codigo;
}

int DtInfoCasa::getCantAmbientes()
{
  return this->cantAmbientes;
}

int DtInfoCasa::getCantDormitorios()
{
  return this->cantDormitorios;
}

int DtInfoCasa::getCantBanios()
{
  return this->cantBanios;
}

float DtInfoCasa::getMtsCuadradosEdificados()
{
  return this->mtsCuadradosEdificados;
}

float DtInfoCasa::getMtsCuadradosTotales()
{
  return this->mtsCuadradosTotales;
}

float DtInfoCasa::getMtsCuadradosVerdes()
{
  return this->mtsCuadradosVerdes;
}

string DtInfoCasa::getTipo()
{
  return this->tipo;
}

float DtInfoCasa::getPrecio()
{
  return this->precio;
}

DtDireccion DtInfoCasa::getDireccion()
{
  return this->direccion;
}

bool DtInfoCasa::getGaraje()
{
  return this->garaje;
}