#ifndef DTMENSAJE_H
#define DTMENSAJE_H

#include "DtFecha.h"
#include "DtHora.h"

#include <string>
using namespace std;

struct DtMensaje
{
  private:
    DtFecha fecha;
    DtHora hora;
    string texto;

  public:
    DtMensaje(DtFecha, DtHora, string);
    DtFecha getFecha();
    DtHora getHora();
    string getTexto();
};

#endif