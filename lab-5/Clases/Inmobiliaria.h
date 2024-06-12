#ifndef INMOBILIARIA_H
#define INMOBILIARIA_H

#include "Usuario.h"

#include "../Datatypes/DtDireccion.h"
#include "../ICollection/interfaces/ICollection.h"

class Inmobiliaria : public Usuario {
  private:
    DtDireccion direccion;
    ICollection* propiedades;
  
  public:
    // Constructor
    Inmobiliaria(string, string, DtFecha);

    // Otros
    void addPropiedad(Propiedad*);

    // Getters
    ICollection* getPropiedades();
    DtDireccion getDireccion();

    // Setters
    void setDireccion(DtDireccion);

    // Destructor
    ~Inmobiliaria();
};

#endif
