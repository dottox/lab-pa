#ifndef DTDATOSAPARTAMENTO_H
#define DTDATOSAPARTAMENTO_H

#include "DtDireccion.h"
#include "DtDatos.h"

#include <string>
using namespace std;

struct DtDatos;
struct DtDireccion;

struct DtDatosApartamento : public DtDatos
{
  public:
    DtDatosApartamento(int, int, int, int, bool, DtDireccion, float, float, string, float);
    DtDatosApartamento(int, int, int, bool, DtDireccion, float, float, string, float);

    ~DtDatosApartamento();
};

#endif