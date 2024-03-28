#ifndef EMPRESAEXTRANJERA_H
#define EMPRESAEXTRANJERA_H

#include "../empresa/Empresa.h"

class EmpresaExtranjera : public Empresa {
  public:
    // CONSTRUCTOR
    EmpresaExtranjera(string, Direccion, string); // id, direccion, nombreFantasia

    // SETTERS 
    void setNombreFantasia(string);

    // GETTERS 
    string getNombreFantasia();
    float getDescuento();

    ~EmpresaExtranjera();
    
  private:
    string nombreFantasia;
};

#endif
