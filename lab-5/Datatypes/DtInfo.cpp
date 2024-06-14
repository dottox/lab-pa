#include "DtInfo.h"

DtInfo::DtInfo(int codigo, int cantMensajes, DtDireccion direccion)
{
  this->codigo = codigo;
  this->cantMensajes = cantMensajes;
  this->direccion = direccion;
}

int DtInfo::getCodigo()
{
  return this->codigo;
}

int DtInfo::getCantMensajes()
{
  return this->cantMensajes;
}

DtDireccion DtInfo::getDireccion()
{
  return this->direccion;
}

DtInfo::~DtInfo()
{
}

