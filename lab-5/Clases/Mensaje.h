#ifndef MENSAJE_H
#define MENSAJE_H

#include "../Datatypes/DtFecha.h"
#include "../Datatypes/DtHora.h"
#include "../Datatypes/DtMensaje.h"

#include "../ICollection/interfaces/ICollectible.h"

#include <string>
using namespace std;

struct DtFecha;
struct DtHora;
struct DtMensaje;
struct ICollectible;

class Mensaje : public ICollectible {
  private:
    DtFecha fecha;
    DtHora hora;
    string texto;
    string emisor;
  
  public:
    Mensaje(DtFecha, DtHora, string, string);
    DtMensaje getMensaje();
    ~Mensaje();
};

#endif
