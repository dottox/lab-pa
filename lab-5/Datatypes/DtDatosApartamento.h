#ifndef DTDATOSAPARTAMENTO_H
#define DTDATOSAPARTAMENTO_H

#include "DtDireccion.h"
#include "DtDatos.h"

#include <string>
using namespace std;

struct DtDatosApartamento : public DtDatos
{
  public:
    DtDatosApartamento(int, int, int, int, bool, DtDireccion, float, float, string, float);

    int getCodigo();
    int getCantAmbientes();
    int getCantDormitorios();
    int getCantBanios();
    float getMtsCuadradosEdificados();
    float getMtsCuadradosTotales();
    string getTipo();
    float getPrecio();
    DtDireccion getDireccion();
    bool getGaraje();

    ~DtDatosApartamento();
};

#endif