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
    Casa(DtDatosCasa, Inmobiliaria*, int, char);
    
    // Getters
    float getMtsCuadradosVerdes();

    // Setters
    void setDatos(DtDatosCasa);
    void setMtsCuadradosVerdes(float);

    //Otros
    DtDatos getDatos();

    // Destructor
    ~Casa();
};

#endif
