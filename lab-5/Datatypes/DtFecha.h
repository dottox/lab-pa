#ifndef DTFECHA_H
#define DTFECHA_H

#include "../ICollection/interfaces/ICollectible.h"

class ICollectible;

struct DtFecha : public ICollectible 
{
  private:
    int dia;
    int mes;
    int anio;
    DtFecha getFechaActual();

  public:
    DtFecha();
    DtFecha(int, int, int);
    int getDia();
    int getMes();
    int getAnio();

    ~DtFecha();
};

#endif