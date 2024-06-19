#ifndef DTINMOBILIARIA_H
#define DTINMOBILIARIA_H

#include <string>
using namespace std;

#include "../ICollection/interfaces/ICollectible.h"
#include "DtDireccion.h"

class ICollectible;

struct DtInmobiliaria : public ICollectible {
  private:
    string email;
    DtDireccion direccion;

  public:
    DtInmobiliaria(string,DtDireccion);
    string getEmail();
    DtDireccion getDireccion();

    ~DtInmobiliaria(); 
};

#endif