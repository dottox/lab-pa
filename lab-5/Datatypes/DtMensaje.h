#ifndef DTMENSAJE_H
#define DTMENSAJE_H

#include "DtFecha.h"
#include "DtHora.h"

#include "../ICollection/interfaces/ICollectible.h"

#include <string>
using namespace std;

struct ICollectible;
struct DtFecha;
struct DtHora;

struct DtMensaje : public ICollectible
{
  private:
    DtFecha fecha;
    DtHora hora;
    string texto;

  public:
    // Constructor
    DtMensaje(DtFecha, DtHora, string);
    
    // Getters
    DtFecha getFecha();
    DtHora getHora();
    string getTexto();
    
    // Destructor
    ~DtMensaje();
};

#endif