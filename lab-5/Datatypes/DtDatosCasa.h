#ifndef DTDATOSCASA_H
#define DTDATOSCASA_H

#include "DtDireccion.h"
#include "DtDatos.h"

#include <string>
using namespace std;

struct DtDatosCasa : DtDatos
{
  private:
    float mtsCuadradosVerdes;

  public:
    DtDatosCasa(int, int, int, int, bool, DtDireccion, float, float, string, float, float);

    int getCodigo();
    int getCantAmbientes();
    int getCantDormitorios();
    int getCantBanios();
    float getMtsCuadradosEdificados();
    float getMtsCuadradosTotales();
    float getMtsCuadradosVerdes();
    string getTipo();
    float getPrecio();
    DtDireccion getDireccion();
    bool getGaraje();
};

#endif