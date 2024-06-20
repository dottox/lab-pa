#ifndef DTINFO_H
#define DTINFO_H

#include "DtDireccion.h"

#include "../ICollection/interfaces/ICollectible.h"

#include <string>
using namespace std;

struct DtDireccion;
class ICollectible;

struct DtInfo : public ICollectible
{
  private:
    int codigo;
    int cantMensajes;
    string tipo;
    DtDireccion direccion;

  public:
    // Constructor
    DtInfo(int, string, DtDireccion);
    DtInfo(int, int, DtDireccion);
    
    // Getters
    int getCodigo();
    int getCantMensajes();
    string getTipo();
    DtDireccion getDireccion();

    // Destructor
    ~DtInfo();
};

#endif