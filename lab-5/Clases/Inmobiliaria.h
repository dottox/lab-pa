#ifndef INMOBILIARIA_H
#define INMOBILIARIA_H

#include "Usuario.h"
#include "Propiedad.h"

#include "../Datatypes/DtDireccion.h"
#include "../Datatypes/DtFecha.h"

#include "../ICollection/interfaces/ICollection.h"
#include "../ICollection/interfaces/ICollectible.h"

class Propiedad;

class Inmobiliaria : public Usuario {
  private:
    DtDireccion direccion;
    ICollection* propiedades;
  
  public:
    // Constructor
    Inmobiliaria(string, string, DtDireccion);

    // Otros
    void addPropiedad(Propiedad*);
    void removePropiedad(Propiedad*);
    string getTipoUsuario();

    // Getters
    ICollection* getPropiedades();
    DtDireccion getDireccion();

    // Setters
    void setDireccion(DtDireccion);

    // Destructor
    ~Inmobiliaria();
};

#endif
