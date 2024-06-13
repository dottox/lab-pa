#ifndef MENSAJE_H
#define MENSAJE_H

#include "../Datatypes/DtFecha.h"
#include "../Datatypes/DtHora.h"
#include "../Datatypes/DtMensaje.h"

#include "../ICollection/interfaces/ICollection.h"

#include <string>
using namespace std;

class Mensaje : public ICollectible {
  private:
    DtFecha fecha;
    DtHora hora;
    string texto;
  
  public:
    Mensaje(DtFecha, DtHora, string);
    DtMensaje getMensaje();
    ~Mensaje();
};

#endif
