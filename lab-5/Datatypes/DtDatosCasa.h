#ifndef DTDATOSCASA_H
#define DTDATOSCASA_H

#include "DtDireccion.h"
#include "DtDatos.h"

#include <string>
using namespace std;

struct DtDatosCasa : public DtDatos
{
  private:
    float mtsCuadradosVerdes;

  public:
    DtDatosCasa(int, int, int, int, bool, DtDireccion, float, float, string, float, float);
    DtDatosCasa(int, int, int, bool, DtDireccion, float, float, string, float, float);
    
    float getMtsCuadradosVerdes();

    ~DtDatosCasa();
};

#endif