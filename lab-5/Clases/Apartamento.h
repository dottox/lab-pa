#ifndef APARTAMENTO_H
#define APARTAMENTO_H

#include "Propiedad.h"
#include "Inmobiliaria.h"
#include "../Datatypes/DtDatosApartamento.h"

class Propiedad;
class Inmobiliaria;
struct DtDatosApartamento;

class Apartamento : public Propiedad {
  public:
    Apartamento(DtDatosApartamento, Inmobiliaria*, int, char);
    
    // Setters
    void setDatos(DtDatosApartamento);

    // Otros
    DtDatos getDatos();

    ~Apartamento();
};

#endif
