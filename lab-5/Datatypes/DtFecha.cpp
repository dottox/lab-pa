#include "DtFecha.h"

#include <ctime>

DtFecha::DtFecha()
{
  DtFecha fechaActual = getFechaActual();
  this->dia = fechaActual.getDia();
  this->mes = fechaActual.getMes();
  this->anio = fechaActual.getAnio();
}

DtFecha::DtFecha(int dia, int mes, int anio)
{
  this->dia = dia;
  this->mes = mes;
  this->anio = anio;
}

int DtFecha::getDia() {
  return this->dia;
}

int DtFecha::getMes() {
  return this->mes;
}

int DtFecha::getAnio() {
  return this->anio;
}

DtFecha DtFecha::getFechaActual() {
  time_t now = time(0);
  tm* ltm = localtime(&now);
  int year = 1900 + ltm->tm_year;
  int month = 1 + ltm->tm_mon;
  int day = ltm->tm_mday;

  return DtFecha(day, month, year);
}