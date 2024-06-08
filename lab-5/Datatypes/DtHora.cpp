#include "DtHora.h"

DtHora::DtHora()
{
}

DtHora::DtHora(int hora, int minuto)
{
  this->hora = hora;
  this->minuto = minuto;
}

int DtHora::getHora() {
  return this->hora;
}

int DtHora::getMinuto() {
  return this->minuto;
}
