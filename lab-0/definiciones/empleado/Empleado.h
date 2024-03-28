#ifndef EMPLEADO_H
#define EMPLEADO_H

#include "../datatypes/dtypes.h"

class Empleado {
  public:

    // CONSTRUCTOR
    Empleado(string, string, string, Direccion);

    // SETTERS 
    void setNombre(string);
    void setApellido(string);
    void setCi(string);
    void setDireccion(Direccion);

    // GETTERS 
    string getNombre();
    string getApellido();
    string getCi();
    Direccion getDireccion();
    
     //DESTRUCTORES
    ~Empleado();

  private:
    string ci;
    string nombre;
    string apellido;
    Direccion direccion;
  };

#endif
