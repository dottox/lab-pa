#ifndef DTDATOS_H
#define DTDATOS_H

#include "DtDireccion.h"

#include <string>
using namespace std;

struct DtDatos 
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
    
  protected:
    virtual DtDatos(int, int, int, int, bool, DtDireccion, float, float, string, float);

  public:
    virtual int getCodigo() = 0;
    virtual int getCantAmbientes() = 0;
    virtual int getCantDormitorios() = 0;
    virtual int getCantBanios() = 0;
    virtual float getMtsCuadradosEdificados() = 0;
    virtual float getMtsCuadradosTotales() = 0;
    virtual string getTipo() = 0;
    virtual float getPrecio() = 0;
    virtual DtDireccion getDireccion() = 0;
    virtual bool getGaraje() = 0;
};

#endif
