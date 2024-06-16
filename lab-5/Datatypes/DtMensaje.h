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
    string emisor;

  public:
    // Constructor
    DtMensaje(DtFecha, DtHora, string, string);
    
    // Getters
    DtFecha getFecha();
    DtHora getHora();
    string getTexto();
    string getEmisor();
    
    // Destructor
    ~DtMensaje();
};

#endif