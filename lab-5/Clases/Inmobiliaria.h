#ifndef INMOBILIARIA_H
#define INMOBILIARIA_H

#include "Usuario.h"
#include "Propiedad.h"

#include "../Datatypes/DtDireccion.h"
#include "../Datatypes/DtFecha.h"

#include "../ICollection/interfaces/ICollection.h"
#include "../ICollection/interfaces/ICollectible.h"


class Usuario;
class Propiedad;
class ICollection;
struct DtDireccion;

class Inmobiliaria : public Usuario {
  private:
    DtDireccion direccion;
    ICollection* propiedades;
    ICollection* edificios; // Deberíamos gestionarlos en una colección, pero de igual manera, puede estar sujeto a cambios, de momento no haré nada con esto.
  
  public:
    // Constructor
    Inmobiliaria(string, string, DtDireccion);

    // Otros
    void addPropiedad(Propiedad*);
    Propiedad* buscarPropiedad(int);
    string getTipoUsuario();

    // Getters
    ICollection* getPropiedades();
    DtDireccion getDireccion();
    ICollection* propiedad__getConversaciones();

    // Setters
    void setDireccion(DtDireccion);

    // cu EliminarPropiedad
    void eliminarPropiedad(int);

    // Destructor
    ~Inmobiliaria();
};

#endif
