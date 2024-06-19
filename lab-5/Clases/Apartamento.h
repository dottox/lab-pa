#ifndef APARTAMENTO_H
#define APARTAMENTO_H

#include "Propiedad.h"
#include "Inmobiliaria.h"
#include "../Datatypes/DtDatosApartamento.h"

class Propiedad;
struct DtDatosApartamento;

class Apartamento : public Propiedad {
  public:
    Apartamento(DtDatosApartamento, Inmobiliaria*);
    
    // Setters
    void setDatos(DtDatosApartamento);

    // Otros
    DtDatos getInfo();

    ~Apartamento();
};

#endif
