#ifndef CASA_H
#define CASA_H

#include "Propiedad.h"
#include "Inmobiliaria.h"
#include "../Datatypes/DtDatosCasa.h"

class Propiedad;
struct DtDatosCasa;

class Casa : public Propiedad {
  private:
    float mtsCuadradosVerdes;

  public:
    Casa(DtDatosCasa, Inmobiliaria*);
    
    // Getters
    float getMtsCuadradosVerdes();

    // Setters
    void setDatos(DtDatosCasa);

    //Otros
    DtDatos getInfo();

    // Destructor
    ~Casa();
};

#endif
