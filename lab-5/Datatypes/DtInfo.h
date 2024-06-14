#ifndef DTINFO_H
#define DTINFO_H

#include "DtDireccion.h"

#include "../ICollection/interfaces/ICollectible.h"

struct DtInfo : public ICollectible
{
  private:
    int codigo;
    int cantMensajes;
    DtDireccion direccion;

  public:
    // Constructor
    DtInfo(int, int, DtDireccion);
    
    // Getters
    int getCodigo();
    int getCantMensajes();
    DtDireccion getDireccion();

    // Destructor
    ~DtInfo();
};

#endif