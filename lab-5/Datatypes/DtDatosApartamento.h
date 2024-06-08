#ifndef DTDATOSAPARTAMENTO_H
#define DTDATOSAPARTAMENTO_H

#include "DtDireccion.h"

struct DtDatosApartamento 
{
  private:
    int codigo;
    int cantAmbientes;
    int cantDormitorios;
    int cantBanios;
    bool garaje;
    DtDireccion direccion;
    float mtsCuadradosEdificados;
    float mtsCuadradosTotales;
    string tipo;
    float precio;

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
};

#endif