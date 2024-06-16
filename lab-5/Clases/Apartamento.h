#ifndef APARTAMENTO_H
#define APARTAMENTO_H

#include "Propiedad.h"

class Propiedad;

class Apartamento : public Propiedad {
  public:
    Apartamento(DtDatosApartamento*);
    
    ~Apartamento();
};

#endif
