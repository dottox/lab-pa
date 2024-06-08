#ifndef DTINFOCASA_H
#define DTINFOCASA_H

#include "DtDireccion.h"

struct DtInfoCasa {
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
    float mtsCuadradosVerdes;

  public:
    DtInfoCasa(int, int, int, int, bool, DtDireccion, float, float, string, float, float);

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