#ifndef EMPRESANACIONAL_H
#define EMPRESANACIONAL_H

#include "../empresa/Empresa.h"

class EmpresaNacional : public Empresa {
  public:
    // CONSTRUCTOR
    EmpresaNacional(string, Direccion, string); // id, direccion, rut

    // SETTERS 
    void setRut(string);

    // GETTERS 
    string getRut();
    float getDescuento();

    ~EmpresaNacional();
      
  private:
    string rut;
};

#endif