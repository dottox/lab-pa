#include "DtInfo.h"

DtInfo::DtInfo(int codigo, int cantMensajes, DtDireccion direccion)
{
  this->codigo = codigo;
  this->cantMensajes = cantMensajes;
  this->direccion = direccion;
  this->tipo = "";
}

DtInfo::DtInfo(int codigo, string tipo, DtDireccion direccion)
{
  this->codigo = codigo;
  this->direccion = direccion;
  this->tipo = tipo;
  this->cantMensajes = -1;
}

int DtInfo::getCodigo()
{
  return this->codigo;
}

int DtInfo::getCantMensajes()
{
  return this->cantMensajes;
}

string DtInfo::getTipo()
{
  return this->tipo;
}

DtDireccion DtInfo::getDireccion()
{
  return this->direccion;
}

DtInfo::~DtInfo()
{
}

