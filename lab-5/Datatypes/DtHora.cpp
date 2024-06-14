#include "DtHora.h"

#include <ctime>

DtHora::DtHora()
{
  DtHora horaActual = getHoraActual();
  this->hora = horaActual.getHora();
  this->minuto = horaActual.getMinuto();
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

DtHora DtHora::getHoraActual() {
  time_t now = time(0);
  tm* ltm = localtime(&now);
  int hour = ltm->tm_hour;
  int min = ltm->tm_min;
  
  return DtHora(hour, min);
}

DtHora::~DtHora()
{
}