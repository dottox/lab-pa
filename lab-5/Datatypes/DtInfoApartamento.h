#ifndef DTINFOAPARTAMENTO_H
#define DTINFOAPARTAMENTO_H

#include "DtDireccion.h"
#include <string>
using namespace std;

struct DtInfoApartamento {
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
    DtInfoApartamento(int, int, int, int, bool, DtDireccion, float, float, string, float);
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