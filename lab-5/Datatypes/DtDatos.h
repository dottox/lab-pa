#ifndef DTDATOS_H
#define DTDATOS_H

#include "DtDireccion.h"

#include <string>
using namespace std;

struct DtDatos 
{
  protected:
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
    DtDatos(int, int, int, int, bool, DtDireccion, float, float, string, float);

  public:
    virtual int getCodigo();
    virtual int getCantAmbientes();
    virtual int getCantDormitorios();
    virtual int getCantBanios();
    virtual float getMtsCuadradosEdificados();
    virtual float getMtsCuadradosTotales();
    virtual string getTipo();
    virtual float getPrecio();
    virtual DtDireccion getDireccion();
    virtual bool getGaraje();

    virtual ~DtDatos();
};

#endif
