#ifndef CASA_H
#define CASA_H

#include "Propiedad.h"

class Propiedad;

class Casa : public Propiedad {
  private:
    float mtsCuadradosVerdes;

  public:
    Casa(DtDatosCasa*);
    
    // Getters
    float getMtsCuadradosVerdes();

    
    // Otros
    virtual Chat* createChat(Interesado*);
    virtual DtInfo* getInfoPropiedad(string);
    virtual void setChatActual(string);
    virtual void addChat(ICollectible*);

    // Destructor
    ~Casa();
};

#endif
